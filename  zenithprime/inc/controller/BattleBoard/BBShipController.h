#pragma once
#include "BBModel.h"

class BBShipModel;

class BBModel;

struct ShipMove
{
	BBShipModel* shipModel;
	std::vector<NxVec3> path;
	int step;
	ShipMove* next;
	ShipMove* prev;
};

class BBShipController
{
public:
	BBShipController(BBModel* model);
	void MoveShip(BBShipModel* shipModel,float x, float y);
	void TryMoveShip(BBShipModel* shipModel,float x, float y);
	void Update();
private:
	BBModel* model;
	ShipMove* head;
};

