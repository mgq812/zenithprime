#include "BattleBoardGUI.h"

class FactoryVisitor
{
public:
	virtual void AddBackground(BBModel* model);
	virtual void AddLights(BBModel* model);
	virtual void AddPlayers(BBModel* model);
	virtual void AddShips(BBPlayerModel* playerModel, BBModel* model);
};