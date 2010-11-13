#include "Cursor.h"

static Cursor* singleton = NULL;

void Cursor::Draw(){
	GetCurrentCursor()->Draw(Mouse::getCurrentMouse()->X, Mouse::getCurrentMouse()->Y);
}
DrawCursor* Cursor::GetCurrentCursor(){
	if(singleton==NULL)
		singleton = new Cursor();

	return singleton->currentCursor;
}

void Cursor::SetCurrentCursor(DrawCursor* cursor){
	singleton->currentCursor = cursor;
}

Cursor::Cursor(){
	currentCursor = new NullCursor();
}


void NullCursor::Draw(int X, int Y){
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, Mouse::getCurrentMouse()->maxX, Mouse::getCurrentMouse()->maxY,0, 0,1);
	glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
	//glTranslatef(-0.375,0, 0);

	//glLoadIdentity();
		//Will be transparent
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
   glEnable(GL_BLEND);
   glDisable(GL_DEPTH_TEST);
   
   //Draw the cursor at the current mouse pos
   glBegin(GL_TRIANGLES);
     glColor4f(1,1,1,1);
     glVertex2f(X,Y);
     glVertex2f(X+20.0f,Y+20.0f);
     glVertex2f(X,Y+20.0f);
   glEnd();
   
   //Alles wird wie vorher
   glDisable(GL_BLEND);
   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
}
