#include "BattleBoard.h"

using namespace std;

BattleBoardView::BattleBoardView(BattleBoardModel* model){
  this->model = model;
  
  X = model->width/2;
  Y = model->height/2;
  rotateX = 45;
  rotateY = 0;
  zoom = 10;
  updateCamera();
  
  x_div = (int)(model->width/2.0);
  y_div = (int)(model->height/2.0);
  
  showGrid = false;
  showBoundry = false;
  showBackground = false;
  showForeground = false;
  showShips = false;
  showMissles = false;
  showSpecials = false;
  showParticles =false;
}

void BattleBoardView::updateCamera(){
  
}

void BattleBoardView::Draw(){
  gluLookAt(camera[0], camera[1], camera[2], /* look from camera XYZ */ 
	    X, Y, 0, /* look at the origin */ 
	    0, 1, 0); /* positive Y up vector */
  
      if(showGrid)
	DrawGrid();
      if(showBoundry)
	DrawBoundry();
      if(showBackground)
	DrawBackground();
      if(showShips)
	DrawShips();
      if(showMissles)
	DrawMissles();
      if(showSpecials)
	DrawMissles();
      if(showParticles)
	DrawParticles();
      if(showForeground)
	DrawForeground();
}
    
BattleBoardView::~BattleBoardView(){

}
  

void BattleBoardView::DrawGrid(){
  
}
void BattleBoardView::DrawBoundry(){
}
void BattleBoardView::DrawBackground(){
}
void BattleBoardView::DrawForeground(){
}
void BattleBoardView::DrawShips(){
}
void BattleBoardView::DrawMissles(){
}
void BattleBoardView::DrawSpecials(){
}
void BattleBoardView::DrawParticles(){
}
    
void BattleBoardView::DrawWireframeShip(const ShipPlacement& ship, int R, int G, int B){
}

