#include "SpaceCombatViewport.h"

SpaceCombatViewport::SpaceCombatViewport(int width, int height, int x =0; int y=0): Width(width), Height(height), offsetX(x), offsetY(y){
	BattleBoardModel* battleBoardModel = new BattleBoardModel();
	battleBoardView = new BattleBoardView(battleBoardModel);
}
SpaceCombatViewport::~SpaceCombatViewport(){

}

int SpaceCombatViewport::Draw(){
	glPushMatrix();
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