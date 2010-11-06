#include "ShipGUI.h"

ShipView::ShipView(DrawableModel* model, ShipGUIController* controller){
	this->model = model;
	this->controller = controller;

	// Somewhere in the initialization part of your programâ¦
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Create light components
	float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float diffuseLight[] = { 0.6f, 0.6f, 0.6f,1.0f };
	float specularLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	//float position[] = { 0.0f, 10.0f, 10.0f, 0.5f };

	// Assign created components to GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

	glEnable(GL_LIGHT1);

	// Assign created components to GL_LIGHT0
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);

	float position[] = {0.0f, 5.0f, -20.0f,  0.3f };
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	float position2[] = {10.0f, 5.0f, 20.0f,  0.8f };
	glLightfv(GL_LIGHT1, GL_POSITION, position2);
	//glLightfv(GL_LIGHT0, GL_POSITION, position);


}

ShipView::~ShipView(){

}

void ShipView::Draw(){
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);

	/*float mcolor[] = { .2f, 0.2f, 0.2f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mcolor);*/

	//float specReflection[] = { 0.3f, 0.3f, 0.3f,0.5f };
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specReflection);

	
	//glMateriali(GL_FRONT, GL_SHININESS, 64);

	

	controller->enablePrespective();
	if(model->cacheTexture>0)
	{
		glBindTexture(GL_TEXTURE_2D, model->cacheTexture);
	}

	glCallList(model->cacheModel);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
}