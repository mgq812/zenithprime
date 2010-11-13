#include "SpaceCombatViewport.h"

SpaceCombatViewport::SpaceCombatViewport(BattleBoardView* bbView)
{
	Width = 0;
	Height = 0;
	offsetX = 0;
	offsetY = 0;

	battleBoardView = bbView;
	battleBoardView->setViewport(offsetX, offsetY, Width, Height, 60.0f);
}

SpaceCombatViewport::SpaceCombatViewport(BattleBoardView* bbView, int width =0, int height=0, int x=0, int y=0)
	:Width(width), Height(height), offsetX(x), offsetY(y)
{
	battleBoardView = bbView;
	battleBoardView->setViewport(offsetX, offsetY, Width, Height, 60.0f);
}
SpaceCombatViewport::~SpaceCombatViewport(){

}

int SpaceCombatViewport::Draw()
{
	if(Width>0){
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, (GLfloat)Width/(GLfloat)Height, 0.1f, 10000000.0f);
		glViewport(offsetX,offsetY,Width,Height);

		glMatrixMode(GL_MODELVIEW);
		battleBoardView->Draw();


		glFlush();
		glPopMatrix();
	}
	return true;
}
int SpaceCombatViewport::Update(){
	battleBoardView->Update();
	return true;
}
int SpaceCombatViewport::Resize(int width, int height){
	Width = width;
	Height = height;

	battleBoardView->setViewport(offsetX, offsetY, Width, Height, 60.0f);
	return true;
}
int SpaceCombatViewport::MoveTo(int x, int y){
	offsetX = x;
	offsetY = y;
	return true;
}