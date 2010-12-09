#include "BBPlayerModel.h"

BBPlayerModel::BBPlayerModel(BBModel* parent)
{
	parentBoard = parent;
}


ZList<BBShipModel*> BBPlayerModel::getShips()
{
	return ships;
}

void BBPlayerModel::addShip(BBShipModel* ship)
{
	ships.insert(ship);
}

void BBPlayerModel::removeShip(BBShipModel* ship)
{
	ships.remove(ship);
}
