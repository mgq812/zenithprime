#include <string>

#include "BBModel.h"

#include "BBState.h"
#include "BBStateStart.h"
#include "BBStateShip.h"
#include "BBStateEnemyShip.h"


BBState* BBStateStart::LClickNothing(BBModel* model)
{
	// next state
	return new BBStateStart();
}
BBState* BBStateStart::LClickEnemy(BBModel* model, BBPlayerModel* player, BBShipModel* ship)
{
	// next state
	return new BBStateEnemyShip();
}

BBState* BBStateStart::LClickShip(BBModel* model, BBShipModel* ship)
{
	// next state
	return new BBStateShip();
}

BBState* BBStateStart::RClickValidMove(BBModel* model)
{
	// next state
	return new BBStateStart();
}

BBState* BBStateStart::RClickBadMove(BBModel* model)
{
	// next state
	return new BBStateStart();
}

string BBStateStart::toString()
{
	return "Start State";
}