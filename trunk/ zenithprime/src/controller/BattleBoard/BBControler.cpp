#include <iostream>

#include "BBControler.h"

BBControler::BBControler(BBModel* battleBoard1){
	battleBoard = battleBoard1;
	currentState = BBNullState::getState();
}
void BBControler::setState(BBState* nextState)
{
	currentState = nextState;
}
void BBControler::LeftMouseClick(NxRaycastHit& hit){
	currentState->LeftMouseClick(hit, this);
}
void BBControler::RightMouseClick(NxRaycastHit& hit){
	currentState->RightMouseClick(hit, this);
}

void BBControler::MouseHover(NxRaycastHit& hit){
	currentState->MouseHover(hit, this);
}
void BBControler::LeftMouseDrag(NxRaycastHit& hit){
	currentState->LeftMouseDrag(hit, this);
}

BBModel* BBControler::getModel(){
	return battleBoard;
}