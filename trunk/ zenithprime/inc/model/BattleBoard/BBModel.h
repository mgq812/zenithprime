#ifndef BBMODEL_H
#define BBMODEL_H

#include "BBPhysics.h"
#include "ZList.h"
#include <vector>
#include "BBPlayerModel.h"

class BBModel
{
public:
	// Constructors
	BBModel();
	BBModel(float width1, float height1, ZList<BBPlayerModel*> players1);
	BBModel(float width1, float height1, ZList<BBPlayerModel*> players1, BBShipModel* background);
	~BBModel();

	// Getters and setters
	float getWidth();
	float getHeight();
	void setWidth(float width1);
	void setHeight(float height1);

	// other functions
	ZList<BBPlayerModel*> getPlayers();
	void addPlayer(BBPlayerModel* player);
	void removePlayer(BBPlayerModel* player);

	void getAllShips(vector<BBShipModel*>& list);
	void getAllGhostShips(vector<BBShipModel*>& list);
	void getSelectedShips(vector<BBShipModel*>& list);
	BBShipModel* getBackground();

	bool animate;
	BBShipModel* mockShip;
	BBPhysics* physicalWorld;

	float cursX, cursY, cursZ;
private:
	float width;
	float height;
	//Image Background;
	ZList<BBPlayerModel*> players;
	BBPlayerModel* curPlayer;
	BBShipModel* background;
};

#endif