#ifndef BBSTATE_H
#define BBSTATE_H

#include <string>

#include "BBShipModel.h"

class BBState
{
public:
	virtual BBState* LClickNothing(BBModel* model) = 0;
	virtual BBState* LClickEnemy(BBModel* model, BBPlayerModel* player, BBShipModel* ship) = 0;
	virtual BBState* LClickShip(BBModel* model, BBShipModel* ship) = 0;
	virtual BBState* RClickValidMove(BBModel* model) = 0;
	virtual BBState* RClickBadMove(BBModel* model) = 0;

	virtual string toString() = 0;

private:

};

#endif