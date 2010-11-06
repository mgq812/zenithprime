#ifndef BBSTATEENEMYSHIP_H
#define BBSTATEENEMYSHIP_H

#include <string>

#include "BBState.h"

class BBStateEnemyShip : public BBState
{
public:
	virtual BBState* LClickNothing(BBModel* model);
	virtual BBState* LClickEnemy(BBModel* model, BBPlayerModel* player, BBShipModel* ship);
	virtual BBState* LClickShip(BBModel* model, BBShipModel* ship);
	virtual BBState* RClickValidMove(BBModel* model);
	virtual BBState* RClickBadMove(BBModel* model);
	
	virtual string toString();

private:

};

#endif