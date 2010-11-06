#include <string>

#include "BBModel.h"

#include "BBState.h"
#include "BBStateStart.h"
#include "BBStateShip.h"
#include "BBStateEnemyShip.h"


BBState* BBStateEnemyShip::LClickNothing(BBModel* model)
{
	// next state
	return new BBStateStart();
}
BBState* BBStateEnemyShip::LClickEnemy(BBModel* model, BBPlayerModel* player, BBShipModel* ship)
{
	// next state
	return new BBStateEnemyShip();
}

BBState* BBStateEnemyShip::LClickShip(BBModel* model, BBShipModel* ship)
{
	// next state
	return new BBStateShip();
}

BBState* BBStateEnemyShip::RClickValidMove(BBModel* model)
{
	// next state
	return new BBStateEnemyShip();
}

BBState* BBStateEnemyShip::RClickBadMove(BBModel* model)
{
	// next state
	return new BBStateEnemyShip();
}

string BBStateEnemyShip::toString()
{
	return "Enemy Ship State";
}