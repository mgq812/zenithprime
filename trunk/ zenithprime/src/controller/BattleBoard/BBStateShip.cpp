#include <string>

#include "BBModel.h"

#include "BBState.h"
#include "BBStateStart.h"
#include "BBStateShip.h"
#include "BBStateEnemyShip.h"


BBState* BBStateShip::LClickNothing(BBModel* model)
{
	// next state
	return new BBStateStart();
}
BBState* BBStateShip::LClickEnemy(BBModel* model, BBPlayerModel* player, BBShipModel* ship)
{
	// next state
	return new BBStateEnemyShip();
}

BBState* BBStateShip::LClickShip(BBModel* model, BBShipModel* ship)
{
	// next state
	return new BBStateShip();
}

BBState* BBStateShip::RClickValidMove(BBModel* model)
{
	// next state
	return new BBStateStart();
}

BBState* BBStateShip::RClickBadMove(BBModel* model)
{
	// next state
	return new BBStateShip();
}

string BBStateShip::toString()
{
	return "Ship State";
}