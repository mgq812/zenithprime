#include <string>

#include "BBState.h"

BBNullState* nullState = NULL;
BBNullState* BBNullState::getState(){
	if(nullState==NULL){
		nullState = new BBNullState();
	}

	return nullState;
}
void BBNullState::LeftMouseClick(NxRaycastHit& hit, BBControler* control){
	if(hit.shape ==NULL){
		//Do Nothing
	}
	else if(hit.shape->isPlane())
	{
		//
	}
	else
	{
		control->getModel()->addSelectedShip((BBShipModel*)hit.shape->userData);
		control->setState(BBSelectedState::getState());
	}
}
void BBNullState::RightMouseClick(NxRaycastHit& hit, BBControler* control){
	if(hit.shape ==NULL){
	}
	else if(hit.shape->isPlane())
	{
	}
	else
	{
		control->getModel();
	}
}
void BBNullState::MouseHover(NxRaycastHit& hit, BBControler* control){
	control->getModel()->clearHighlightedShips();
	if(hit.shape ==NULL){

	}
	else if(hit.shape->isPlane())
	{
		//Do nothing
	}
	else
	{
		control->getModel()->addHighlightedShip((BBShipModel*)hit.shape->userData);
	}
}
void BBNullState::LeftMouseDrag(NxRaycastHit& hit, BBControler* control){
	if(hit.shape ==NULL){
		//Do Nothing
	}
	else if(hit.shape->isPlane())
	{
	}
	else
	{
		control->getModel();
	}
}

BBNullState::BBNullState(){


}