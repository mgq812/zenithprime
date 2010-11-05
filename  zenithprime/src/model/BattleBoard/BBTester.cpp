/* *******************************************************************
*	Created By: J. Taylor Grimes
*
*	Description: This class was made to test the BBControler so the 
*		right rules are inforced when it is hooked up with the BBView.
******************************************************************** */

#include <iostream>
#include <time.h>
#include "BBControler.h"
#include "BBModel.h"
#include "BBPlayerModel.h"
#include "BBShipModel.h"
#include "ZList.h"

using namespace std;


BBModel* initBBModel();	// initializes the battle board
BBControler* initBBControler(BBModel* battleBoard); // initializes the controler for the board
void disp(BBModel* model); // shows contents of a battle board

int main()
{
	BBModel* battleBoard = initBBModel();

	BBControler* bbControl = initBBControler(battleBoard);

	disp(battleBoard);
	system("pause");

	bbControl->LeftMouseClick(0, 0);

	disp(battleBoard);
	system("pause");
}

BBModel* initBBModel()
{
	srand(time(NULL));
	// create a list of ships
	ZList<BBShipModel*> shipList1;
	
	// create a bunch of ships
	int numShips = rand() % 10 + 1;
	for (int i = 0; i < numShips; i++)
	{
		BBShipModel* ship = new BBShipModel((float)(rand() % 500), 
											(float)(rand() % 500), 
											(float)(rand() % 360), 
											(float)(rand() % 10 + 1));
		shipList1.insert(ship);
	}

	// create a list of players
	ZList<BBPlayerModel*> playerList1;

	// create one player
	BBPlayerModel* player1 = new BBPlayerModel(shipList1);
	playerList1.insert(player1);

	// create one battle board with the player
	BBModel* battleBoard = new BBModel(500, 500, playerList1);

	return battleBoard;
}

BBControler* initBBControler(BBModel* battleBoard)
{
	return new BBControler(battleBoard);
}

void disp(BBModel* model)
{
	cout << "Battle Board..." << endl;
	cout << "Height: " << model->getHeight() << endl;
	cout << "Width: " << model->getWidth() << endl;

	ZList<BBPlayerModel*> players = model->getPlayers();
	ZListNode<BBPlayerModel*>* player = players.getHead();
	int playerNum = 1;
	while (player != '\0')
	{
		cout << "  Player " << playerNum++ << endl;

		ZList<BBShipModel*> ships = player->getData()->getShips();
		ZListNode<BBShipModel*>* ship = ships.getHead();
		int shipNum = 1;
		while (ship != '\0')
		{
			cout << "    Ship " << shipNum++ << endl;
			cout << "      Position" << endl;
			cout << "        X : " << ship->getData()->getPosition().x << endl;
			cout << "        Y : " << ship->getData()->getPosition().y << endl;

			ship = ship->getNext();
		}

		player = player->getNext();
	}
}
