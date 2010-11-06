#include <iostream>

#include "BBControler.h"
#include "BBState.h"
#include "BBStateStart.h"
#include "BBStateShip.h"
#include "BBStateEnemyShip.h"

BBControler::BBControler(BBModel* battleBoard1)
	:battleBoard(battleBoard1), 
	state(new BBStateStart()), 
	curPlayer(battleBoard->getPlayers().getHead()->getData())
{}

// this is a square buffer used in collision detection
const int buff = 100;
void BBControler::LeftMouseClick(int x, int y)
{
	cout << "Moving from " << state->toString() << " to ";
	BBShipModel* shipSelected;
	BBPlayerModel* foundPlayer;
	if ((shipSelected = curPlayerShipAt(x, y)) != NULL)
	{
		BBState* nextState = state->LClickShip(battleBoard, shipSelected);
		delete state;
		state = nextState;
	}

	else if ((shipSelected = otherPlayerShipAt(x, y, foundPlayer)) != NULL)
	{
		BBState* nextState = state->LClickEnemy(battleBoard, foundPlayer, shipSelected);
		delete state;
		state = nextState;
	}

	else
	{
		BBState* nextState = state->LClickNothing(battleBoard);
		delete state;
		state = nextState;
	}

	cout << state->toString() << endl;
	system("pause");
}

void BBControler::RightMouseClick(int x, int y)
{}

void BBControler::MouseHover(int x, int y)
{}

void BBControler::LeftMouseDrag(int xStart, int yStart, int xEnd, int yEnd)
{}

BBShipModel* BBControler::curPlayerShipAt(int x, int y)
{
	ZList<BBShipModel*> ships = curPlayer->getShips();
	ZListNode<BBShipModel*>* temp = ships.getHead();

	while (temp != NULL)
	{
		BBShipModel* curShip = temp->getData();			
		if (curShip->getX() <= x + buff && 
			curShip->getX() >= x - buff && 
			curShip->getY() <= y + buff && 
			curShip->getY() >= y - buff)
			return curShip;
		temp = temp->getNext();
	}

	return NULL;
}

BBShipModel* BBControler::otherPlayerShipAt(int x, int y, BBPlayerModel* &foundPlayer)
{
	ZList<BBPlayerModel*> players = battleBoard->getPlayers();
	ZListNode<BBPlayerModel*>* tempPlayer = players.getHead();

	while (tempPlayer != NULL)
	{
		if (tempPlayer->getData() == curPlayer)
		{
			tempPlayer = tempPlayer->getNext();
			continue;
		}

		ZList<BBShipModel*> ships = tempPlayer->getData()->getShips();
		ZListNode<BBShipModel*>* curShip = ships.getHead();

		while (curShip != NULL)
		{
			BBShipModel* ship = curShip->getData();
			if (ship->getX() <= x + buff && 
				ship->getX() >= x - buff && 
				ship->getY() <= y + buff && 
				ship->getY() >= y - buff)
			{
				foundPlayer = tempPlayer->getData();
				return ship;
			}

			curShip = curShip->getNext();
		}

		tempPlayer = tempPlayer->getNext();
	}

	return NULL;
}