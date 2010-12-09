#ifndef BBSTATE_H
#define BBSTATE_H

#include <string>

#include "NxPhysics.h"
class BBControler;

class BBState
{
public:
	virtual void LeftMouseClick(NxRaycastHit& hit, BBControler* control)=0;
	virtual void RightMouseClick(NxRaycastHit& hit, BBControler* control)=0;
	virtual void MouseHover(NxRaycastHit& hit, BBControler* control)=0;
	virtual void LeftMouseDrag(NxRaycastHit& hit, BBControler* control)=0;

private:

};

class BBNullState : public BBState
{
public:
	static BBNullState* getState();
	virtual void LeftMouseClick(NxRaycastHit& hit, BBControler* control);
	virtual void RightMouseClick(NxRaycastHit& hit, BBControler* control);
	virtual void MouseHover(NxRaycastHit& hit, BBControler* control);
	virtual void LeftMouseDrag(NxRaycastHit& hit, BBControler* control);
private:
	BBNullState();
};
#endif