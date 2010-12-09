#include "BBState.h"

BBSelectedState* nullState = NULL;
BBSelectedState* BBSelectedState::getState(){
	if(nullState==NULL){
		nullState = new BBSelectedState();
	}

	return nullState;
}
void BBSelectedState::LeftMouseClick(NxRaycastHit& hit, BBControler* control){
	if(hit.shape ==NULL){
		control->getModel()->clearSelectedShips();
		control->setState(BBNullState::getState());
	}
	else if(hit.shape->isPlane())
	{
			std::vector<BBShipModel*> list;
			control->getModel()->getSelectedShips(list);

			for(int i = 0; i < list.size(); i++)
				list[i]->shipActor->moveGlobalPosition(hit.worldImpact);

	}
	else
	{
		if(!Keyboard::getCurrentKeyboard()->Keys[VK_SHIFT])
			control->getModel()->clearSelectedShips();
		control->getModel()->addSelectedShip((BBShipModel*)hit.shape->userData);	
	}
}
void BBSelectedState::RightMouseClick(NxRaycastHit& hit, BBControler* control){
	control->getModel()->clearSelectedShips();
	control->setState(BBNullState::getState());

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
void BBSelectedState::MouseHover(NxRaycastHit& hit, BBControler* control){
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
void BBSelectedState::LeftMouseDrag(NxRaycastHit& hit, BBControler* control){
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

BBSelectedState::BBSelectedState(){


}