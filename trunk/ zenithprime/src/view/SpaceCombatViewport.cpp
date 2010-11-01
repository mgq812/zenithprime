#include "SpaceCombatViewport.h"

SpaceCombatViewport::SpaceCombatViewport()
{}

SpaceCombatViewport::SpaceCombatViewport(int width, int height, int x, int y)
	:Width(width), Height(height), offsetX(x), offsetY(y)
{
	BattleBoardModel* battleBoardModel = new BattleBoardModel();
	battleBoardView = new BattleBoardView(battleBoardModel);
}
SpaceCombatViewport::~SpaceCombatViewport(){

}

int SpaceCombatViewport::Draw(){
	glPushMatrix();
	glLoadIdentity();
	//gluPerspective(45.0f, (GLfloat)Width/(GLfloat)Height, 0.1f, 10000.0f);
	glViewport(offsetX,offsetY,Width,Height);
	battleBoardView->Draw();
	glFlush();
	glPopMatrix();
	return true;
}
int SpaceCombatViewport::Update(){
	return true;
}
int SpaceCombatViewport::Resize(int width, int height){
	Width = width;
	Height = height;
	return true;
}
int SpaceCombatViewport::MoveTo(int x, int y){
	offsetX = x;
	offsetY = y;
	return true;
}