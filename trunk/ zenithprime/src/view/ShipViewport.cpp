#include "ShipViewport.h"

using namespace std;

ShipViewport::ShipViewport(ShipView* sView)
{
	Width = 0;
	Height = 0;
	offsetX = 0;
	offsetY = 0;

	shipView = sView;
}

ShipViewport::ShipViewport(ShipView* sView, int width =0, int height=0, int x=0, int y=0)
	:Width(width), Height(height), offsetX(x), offsetY(y)
{
	shipView = sView;
}
ShipViewport::~ShipViewport(){

}

int ShipViewport::Draw()
{
	if(Width>0){
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, (GLfloat)Width/(GLfloat)Height, 0.1f, 10000000.0f);
		glViewport(offsetX,offsetY,Width,Height);

		glMatrixMode(GL_MODELVIEW);
		shipView->Draw();
		glFlush();
		glPopMatrix();
		glFlush();
	}
	return true;
}
int ShipViewport::Update(){
	return true;
}
int ShipViewport::Resize(int width, int height){
	Width = width;
	Height = height;
	return true;
}
int ShipViewport::MoveTo(int x, int y){
	offsetX = x;
	offsetY = y;
	return true;
}