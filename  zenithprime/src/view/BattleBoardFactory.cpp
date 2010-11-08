#include <time.h>
#include "BattleBoardFactory.h"
#include "DrawableModelLoader.h"
#include "TextureLoader.h"

using namespace std;

BattleBoardView* BattleBoardFactory::CreateBoard(float width, float height){
	
	srand(time(NULL));

	// create a list of ships
	ZList<BBShipModel*> shipList1;
	
	// create a bunch of ships
	DrawableModel* ship3dModel = DrawableModelLoader::LoadOBJModel("content/Cryslis1.dat");
	Texture::LoadBitmap("content/Cryslis1.bmp", ship3dModel->cacheTexture);
	int numShips = rand() % 20 + 1;
	for (int i = 0; i < 1000; i++)
	{
		BBShipModel* ship = new BBShipModel((float)(rand() % (int)width), 
											(float)(rand() % (int)height), 
											(float)(rand() % 360), 
											(float)(rand() % 5 + 1),
											ship3dModel);
		
		shipList1.insert(ship);
	}
	
	BBShipModel* planet = new BBShipModel(500, 100, 0, 500);
	shipList1.insert(planet);

	// create a list of players
	ZList<BBPlayerModel*> playerList1;

	// create one player
	BBPlayerModel* player1 = new BBPlayerModel(shipList1);
	playerList1.insert(player1);

	BBModel* model = new BBModel(width, height, playerList1);

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	return view;
}