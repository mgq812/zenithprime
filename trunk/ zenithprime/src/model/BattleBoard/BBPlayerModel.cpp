#include "BBPlayerModel.h"

BBPlayerModel::BBPlayerModel()
{}
BBPlayerModel::BBPlayerModel(ZList<BBShipModel*> ships1)
	:ships(ships1)
{}

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
