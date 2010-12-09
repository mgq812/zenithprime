#ifndef BBPLAYER_MODEL
#define BBPLAYER_MODEL

#include "BBModel.h"
#include "BBShipModel.h"
#include "ZList.h"

class BBModel;

class BBPlayerModel
{
friend class BBShipModel;
public:
	BBPlayerModel(BBModel* parent);
	ZList<BBShipModel*> getShips();
	void addShip(BBShipModel* ship);
	void removeShip(BBShipModel* ship);

private:

	ZList<BBShipModel*> ships;
	ZList<BBShipModel*> gostShips;
	BBModel* parentBoard;
	
};

#endif