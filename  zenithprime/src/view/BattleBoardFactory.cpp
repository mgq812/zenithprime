#include <time.h>
#include "BattleBoardFactory.h"

using namespace std;

BattleBoardView* BattleBoardFactory::CreateBoard(float width, float height){
	
	srand(time(NULL));

	// create a list of ships
	ZList<BBShipModel*> shipList1;
	
	// create a bunch of ships
	int numShips = rand() % 10 + 1;
	for (int i = 0; i < numShips; i++)
	{
		BBShipModel* ship = new BBShipModel((float)(rand() % 400), 
											(float)(rand() % 800), 
											(float)(rand() % 360), 
											(float)(rand() % 10 + 1));
		shipList1.insert(ship);
	}

	// create a list of players
	ZList<BBPlayerModel*> playerList1;

	// create one player
	BBPlayerModel* player1 = new BBPlayerModel(shipList1);
	playerList1.insert(player1);

	BBModel* model = new BBModel(400, 800, playerList1);

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	return view;
}