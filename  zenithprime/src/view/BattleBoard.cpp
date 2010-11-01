#include "BattleBoard.h"

using namespace std;

BattleBoardView::BattleBoardView(BattleBoardModel* model){
  this->model = model;
  
  X = model->width/2;
  Y = model->hieght/2;
  rotateX = 45;
  rotateY = 0;
  zoom = 10;
  updateCamera();
  
  x_div = (int)model->width/2;
  y_div = (int)model->hieght/2;
  
  showGrid = true;
  showBoundry = false;
  showBackground = false;
  showForeground = false;
  showShips = false;
  showMissles = false;
  showSpecials = false;
  showParticles =false;
}

void BattleBoardView::updateCamera(){
	Matrix cam =	Matrix::CreateTranslation(Vector3(X,0,Y)) * 
					/* maybe make a const for pi */
					Matrix::CreateRotationY(rotateY* (float)3.14159265358/180) *
					Matrix::CreateRotationX(rotateX* (float)3.14159265358/180);

	Vector3 forward = Vector3::Transform(Vector3(0,0,-zoom),  cam); 
	camera[0] = forward.x;
	camera[1] = forward.y;
	camera[2] = forward.z;
}

void BattleBoardView::Draw(){
  
  gluLookAt(camera[0], camera[1], camera[2], /* look from camera XYZ */ 
	    X, 0, Y, /* look at the origin */ 
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
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);

	//Draw Verticle Lines
	float grid_width = model->width/x_div;

	for(int i = 0; i<x_div; i++)
	{
		glVertex3f(i*grid_width,0,0);
		glVertex3f(i*grid_width,0,model->hieght);
	}

	// Draw Horizontal Lines
	float grid_height = model->hieght/y_div;
	for(int j = 0; j<y_div; j++)
	{
		glVertex3f(0,0,grid_height*j);
		glVertex3f(model->width,0,grid_height*j);
	}

	glEnd();
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

