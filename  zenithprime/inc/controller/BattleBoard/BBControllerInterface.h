#include "BattleBoardGUI.h"

class BBControllerInterface : public BattleBoardGUIFacade
{
public:
	BBControllerInterface(BBModel* model);
	~BBControllerInterface();
	virtual void mouseMoved(float originX, float originY, float originZ, float directionX, float directionY, float directionZ);
	virtual void mouseDragged(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons);
	virtual void mousePressed(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons);
	virtual void mouseReleased(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons);
	virtual void mouseClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button);
	virtual void mouseDoubleClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button);
	virtual void Update();
private:
	BBModel* model;
};