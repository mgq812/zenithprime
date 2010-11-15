#include "BBShipModel.h"
#include "BBPlayerModel.h"
#include "BBModel.h"
#include <time.h>

BBModel::BBModel()
	:width(0), height(0)
{}

BBModel::BBModel(float width1, float height1 /*,Image background1*/, ZList<BBPlayerModel*> players1)
	:players(players1), width(width1), height(height1)
{
}

BBModel::BBModel(float width1, float height1, ZList<BBPlayerModel*> players1, BBShipModel* background)
:players(players1), width(width1), height(height1), background(background)
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


void BBModel::getAllShips(vector<BBShipModel*>& list)
{
	ZList<BBPlayerModel*> players = getPlayers();
	ZListNode<BBPlayerModel*>* playerNode = players.getHead();

	while (playerNode != NULL)
	{
		ZList<BBShipModel*> ships = playerNode->getData()->getShips();
		ZListNode<BBShipModel*>* shipNode = ships.getHead();

		while (shipNode != NULL)
		{
			/* this if for fun */
			BBShipModel* singleShip = shipNode->getData();
			float curX = singleShip->getX();
			float curY = singleShip->getY();

			if (curX >= 2000)
			{
				singleShip->xGoingMin = true;
				singleShip->xGoingMax = false;
			}
			if (curX <= 0)
			{
				singleShip->xGoingMax = true;
				singleShip->xGoingMin = false;
			}
			if (curY >= 2000)
			{
				singleShip->yGoingMin = true;
				singleShip->yGoingMax = false;
			}
			if (curY <= 0)
			{
				singleShip->yGoingMax = true;
				singleShip->yGoingMin = false;
			}
			
			if (singleShip->xGoingMax)
				singleShip->setX(curX += .5);
			if (singleShip->yGoingMax)
				singleShip->setY(curY += .5);
			if (singleShip->xGoingMin)
				singleShip->setX(curX -= .5);
			if (singleShip->yGoingMin)
				singleShip->setY(curY -= .5);
			
			list.push_back(singleShip);

			shipNode = shipNode->getNext();
		}

		playerNode = playerNode->getNext();
	}
}
void BBModel::getAllGhostShips(vector<BBShipModel*>& list){
}
void BBModel::getSelectedShips(vector<BBShipModel*>& list){
}

BBShipModel* BBModel::getBackground()
{
	return background;
}