#include "BBControllerInterface.h"

BBShipModel* curse;
BBControllerInterface::BBControllerInterface(BBModel* model){
	
	this->model = model;
}
BBControllerInterface::~BBControllerInterface(){
}
void BBControllerInterface::mouseMoved(float originX, float originY, float originZ, float directionX, float directionY, float directionZ){
		NxRaycastHit hit = model->physicalWorld->CastRay(originX, originY, originZ, directionX, directionY, directionZ);
		if(hit.shape==NULL){
			model->animate = true;
			return;
		}
		else{
			bool act = hit.shape->isPlane();
			model->animate = false;
			return;
		}
}
void BBControllerInterface::mouseDragged(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons){
}
void BBControllerInterface::mousePressed(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons){
}
void BBControllerInterface::mouseReleased(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons){
}
void BBControllerInterface::mouseClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button){
}
void BBControllerInterface::mouseDoubleClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button){
}
void BBControllerInterface::Update(){
}
