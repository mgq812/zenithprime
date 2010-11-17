#include "BattleBoardGUI.h"
#include <iostream>

using namespace std;
GLUquadricObj* quadratic=gluNewQuadric();			// Create A Pointer To The Quadric Object ( NEW )
	
BattleBoardView::BattleBoardView(BBModel* model, BattleBoardController* controller){
  this->model = model;
  this->controller = controller;
  
  showGrid = true;
  showBoundry = false;
  showBackground = true;
  showForeground = false;
  showShips = true;
  showMissles = false;
  showSpecials = false;
  showParticles =false;
  showSelected = false;
	showCursor = true;
	showGhosts = false;
	showAnchor = true;

  x_div = (int)model->getWidth()/10;
  y_div = (int)model->getHeight()/10;
	gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals ( NEW )
	gridCache = -1;
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
	 if(showSelected)
		 DrawSelected();
	 if(showAnchor)
		 DrawAnchor();
	 if(showGhosts)
		 DrawGhosts();
	 if(showCursor)
		 DrawCursor();
     if(showForeground)
		DrawForeground();

	
}
    
BattleBoardView::~BattleBoardView(){

}
  

void BattleBoardView::DrawGrid(){
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glBegin(GL_LINES);
	glColor4f(0.0f, .5f, .7f, 0.2f);

	//Draw Verticle Lines
	float grid_width = model->getWidth()/x_div;

	for(int i = 0; i<=x_div; i++)
	{
		glVertex3f(i*grid_width,0,0);
		glVertex3f(i*grid_width,0,model->getHeight());
	}

	// Draw Horizontal Lines
	float grid_height = model->getHeight()/y_div;
	for(int j = 0; j<=y_div; j++)
	{
		glVertex3f(0,0,grid_height*j);
		glVertex3f(model->getWidth(),0,grid_height*j);
	}

	glEnd();
	//cout<<"Drawing"<<endl;
	glDisable(GL_BLEND);
}

void BattleBoardView::DrawBoundry(){
}

void BattleBoardView::DrawBackground()
{
	BBShipModel* background = model->getBackground();

	setTransforms(background);
	
	glBindTexture(GL_TEXTURE_2D, background->getDrawModel()->cacheTexture);
		glEnable(GL_TEXTURE_2D);

	glCallList(background->getDrawModel()->cacheModel);

	glDisable(GL_TEXTURE_2D);
	clearTransforms();
}

void BattleBoardView::DrawForeground(){
}
void BattleBoardView::DrawShips(){
	vector<BBShipModel*> list;
	model->getAllShips(list);
	list.push_back(new BBShipModel(100, 100, 10, 15));

	for(unsigned int i = 0; i < list.size() ; i++){
		DrawShip(list[i]);
	}
}

void BattleBoardView::DrawMissles(){
}
void BattleBoardView::DrawSpecials(){
}
void BattleBoardView::DrawParticles(){
}
void BattleBoardView::DrawSelected(){
	vector<BBShipModel*> list;
	model->getSelectedShips(list);

	for(unsigned int i = 0; i < list.size() ; i++){
		DrawSelectedShip(list[i]);
	}
}

void BattleBoardView::DrawCursor(){
	Cursor::Draw();
}
void BattleBoardView::DrawGhosts(){

	vector<BBShipModel*> list;
	model->getAllGhostShips(list);

	for(unsigned int i = 0; i < list.size() ; i++){
		DrawWireframeShip(list[i]);
	}
}
void BattleBoardView::DrawAnchor(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	

	glColor4f(0.0f, .5f, .7f, 0.2f);
	glPushMatrix();
	glTranslatef(controller->X, controller->Y, controller->Z);
	glCallList(DrawableModel::NULLDrawableModel()->cacheModel);
	glPopMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_BLEND);
}
    
//void BattleBoardView::DrawWireframeShip(const ShipPlacement& ship, int R, int G, int B){
//}


void BattleBoardView::setGridDivision(int x, int y){
	x_div = x;
	y_div = y;
	
	if(gridCache>=0)

	gridCache = -1;
}

void BattleBoardView::setViewport(int x, int y, int width, int height, float angle){
	controller->setViewport(x,y, width, height, angle);
}

void BattleBoardView::Update(){
	controller->Update();
}


void BattleBoardView::setTransforms(BBShipModel* shipModel){
	glPushMatrix();
	glTranslatef(shipModel->getX(), 0, shipModel->getY());
	glRotatef(shipModel->getAngle(), 0, 1, 0);
	glScalef(shipModel->getScale(), shipModel->getScale(), shipModel->getScale());
}
void BattleBoardView::clearTransforms(){
	glPopMatrix();
}

void BattleBoardView::DrawShip(BBShipModel* shipModel){
	
	setTransforms(shipModel);
	if(shipModel->getDrawModel()->cacheTexture>0)
	{
		glBindTexture(GL_TEXTURE_2D, shipModel->getDrawModel()->cacheTexture);
			glEnable(GL_TEXTURE_2D);
	}
	else
	{
		glColor3f(.5, .5, .5);
	}

	glCallList(shipModel->getDrawModel()->cacheModel);

	glDisable(GL_TEXTURE_2D);
	clearTransforms();
}
void BattleBoardView::DrawWireframeShip(BBShipModel* shipModel){
	setTransforms(shipModel);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	

	glColor4f(0.0f, .5f, .7f, 0.2f);

	glCallList(shipModel->getDrawModel()->cacheModel);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_BLEND);

	clearTransforms();
}
void BattleBoardView::DrawSelectedShip(BBShipModel* shipModel){
	setTransforms(shipModel);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	

	glColor4f(0.2f, .5f, .2f, 0.2f);

	glCallList(shipModel->getDrawModel()->cacheModel);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_BLEND);

	clearTransforms();
}

void BattleBoardView::DrawHighlightedShip(BBShipModel* shipModel){
	setTransforms(shipModel);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	

	glColor4f(0.5f, .5f, 0.0f, 0.2f);

	glCallList(shipModel->getDrawModel()->cacheModel);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_BLEND);

	clearTransforms();
}