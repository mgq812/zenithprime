#ifndef BBSTATESHIP_H
#define BBSTATESHIP_H

#include <string>

#include "BBState.h"

class BBStateShip : public BBState
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