#include <string>

#include "BBModel.h"
#include "BBControler.h"
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
		control->getModel();
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
	if(hit.shape ==NULL){
		//Do nothing
	}
	else if(hit.shape->isPlane())
	{
		//Do nothing
	}
	else
	{
		control->getModel();
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