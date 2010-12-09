#ifndef BBCONTROLER_H
#define BBCONTROLER_H


#include "NxPhysics.h"
#include "BBModel.h"
#include "BBState.h"

class BBState;

class BBControler
{
public:
	BBControler(BBModel* battleBoard1);
	void LeftMouseClick(NxRaycastHit& hit);
	void RightMouseClick(NxRaycastHit& hit);
	void MouseHover(NxRaycastHit& hit);
	void LeftMouseDrag(NxRaycastHit& hit);

	BBModel* getModel();
	void setState(BBState* nextState);
private:

	BBModel* battleBoard;
	BBState* currentState;
};

#endif