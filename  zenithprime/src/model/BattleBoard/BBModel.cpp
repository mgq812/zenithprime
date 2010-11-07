#include "BBPlayerModel.h"
#include "BBModel.h"

BBModel::BBModel()
	:width(0), height(0)
{}

BBModel::BBModel(float width1, float height1 /*,Image background1*/, ZList<BBPlayerModel*> players1)
	:players(players1), width(width1), height(height1)
{
}

float BBModel::getWidth()
{
	return width;
}

float BBModel::getHeight()
{
	return height;
}

void BBModel::setWidth(float width1)
{
	width = width1;
}

void BBModel::setHeight(float height1)
{
	height = height1;
}

ZList<BBPlayerModel*> BBModel::getPlayers()
{
	return players;
}

void BBModel::addPlayer(BBPlayerModel* player)
{
	players.insert(player);
}

void BBModel::removePlayer(BBPlayerModel* player)
{
	players.remove(player);
}


void BBModel::getAllShips(vector<BBShipModel*>& list){

}
void BBModel::getAllGhostShips(vector<BBShipModel*>& list){
}
void BBModel::getSelectedShips(vector<BBShipModel*>& list){
}