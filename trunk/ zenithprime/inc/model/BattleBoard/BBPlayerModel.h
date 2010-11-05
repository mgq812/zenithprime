#ifndef BBPLAYER_MODEL
#define BBPLAYER_MODEL

#include "ZList.h"
#include "BBShipModel.h"

class BBPlayerModel
{

public:
	BBPlayerModel();
	BBPlayerModel(ZList<BBShipModel*> ships1);
	ZList<BBShipModel*> getShips();
	void addShip(BBShipModel* ship);
	void removeShip(BBShipModel* ship);

private:

	ZList<BBShipModel*> ships;
	ZList<BBShipModel*> gostShips;
	
};

#endif