#ifndef BBPLAYER_MODEL
#define BBPLAYER_MODEL

#include <list>
#include "BBShipModel.h"

class BBPlayerModel
{
public:
	BBPlayerModel();

private:
	list<BBShipModel*> ships;
	list<BBShipModel*> gostShips;
};

#endif