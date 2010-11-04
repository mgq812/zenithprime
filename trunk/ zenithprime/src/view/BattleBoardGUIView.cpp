#include "BattleBoardGUI.h"
#include <iostream>

using namespace std;

BattleBoardView::BattleBoardView(BattleBoardModel* model, BattleBoardController* controller){
  this->model = model;
  this->controller = controller;
  
  showGrid = true;
  showBoundry = false;
  showBackground = false;
  showForeground = false;
  showShips = false;
  showMissles = false;
  showSpecials = false;
  showParticles =false;

  x_div = (int)model->width/10;
  y_div = (int)model->hieght/10;

}

void BattleBoardView::Draw()
{
  
	controller->enablePrespective();
  
	
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
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glBegin(GL_LINES);
	glColor4f(0.0, .5, .7, 0.2);

	//Draw Verticle Lines
	float grid_width = model->width/x_div;

	for(int i = 0; i<=x_div; i++)
	{
		glVertex3f(i*grid_width,0,0);
		glVertex3f(i*grid_width,0,model->hieght);
	}

	// Draw Horizontal Lines
	float grid_height = model->hieght/y_div;
	for(int j = 0; j<=y_div; j++)
	{
		glVertex3f(0,0,grid_height*j);
		glVertex3f(model->width,0,grid_height*j);
	}

	glEnd();
	//cout<<"Drawing"<<endl;
	glDisable(GL_BLEND);
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


void BattleBoardView::setGridDivision(int x, int y){
	x_div = x;
	y_div = y;
}