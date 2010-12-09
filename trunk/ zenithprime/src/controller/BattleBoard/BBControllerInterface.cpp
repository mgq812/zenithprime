#include "BBControllerInterface.h"

BBShipModel* curse;
BBControllerInterface::BBControllerInterface(BBModel* model, BBControler* control){
	
	this->model = model;
	this->control = control;
}
BBControllerInterface::~BBControllerInterface(){
}
void BBControllerInterface::mouseMoved(float originX, float originY, float originZ, float directionX, float directionY, float directionZ){
		NxRaycastHit hit = model->CastRay(originX, originY, originZ, directionX, directionY, directionZ);
		if(hit.shape==NULL){
			model->animate = true;
			model->cursX = 0;
			model->cursY = 0;
			model->cursZ = 0;
		}
		else{
			bool act = hit.shape->isPlane();
			if(act==false)
				act = hit.shape->isBox();
			model->animate = false;
			model->cursX = hit.worldImpact.x;
			model->cursY = hit.worldImpact.y;
			model->cursZ = hit.worldImpact.z;
		}

		control->MouseHover(hit);
}
void BBControllerInterface::mouseDragged(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons){
	NxRaycastHit hit = model->CastRay(originX, originY, originZ, directionX, directionY, directionZ);
	if(buttons & MOUSE_LBUTTON != 0)
		control->LeftMouseDrag(hit);
}
void BBControllerInterface::mousePressed(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons){
}
void BBControllerInterface::mouseReleased(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons){
}
void BBControllerInterface::mouseClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button){
	NxRaycastHit hit = model->CastRay(originX, originY, originZ, directionX, directionY, directionZ);
	if(button == MOUSE_LBUTTON)
		control->LeftMouseClick(hit);
	else
		control->RightMouseClick(hit);
}
void BBControllerInterface::mouseDoubleClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button){
}
void BBControllerInterface::Update(){
}
