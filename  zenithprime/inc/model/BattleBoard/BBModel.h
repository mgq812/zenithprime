#ifndef BBMODEL_H
#define BBMODEL_H

#include "ZList.h"
#include "BBPlayerModel.h"

class BBModel
{
public:
	// Constructors
	BBModel();
	BBModel(float width1, float height1, ZList<BBPlayerModel*> players1);

	// Getters and setters
	float getWidth();
	float getHeight();
	void setWidth(float width1);
	void setHeight(float height1);

	// other functions
	ZList<BBPlayerModel*> getPlayers();
	void addPlayer(BBPlayerModel* player);
	void removePlayer(BBPlayerModel* player);

private:
	float width;
	float height;
	//Image Background;
	ZList<BBPlayerModel*> players;
	BBPlayerModel* curPlayer;
};

#endif