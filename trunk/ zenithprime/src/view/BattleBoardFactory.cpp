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
	DrawableModel* models[4];
	models[0] = DrawableModelLoader::LoadOBJModel("content/ShipModels/tayShip2.obj");
	models[1] = DrawableModelLoader::LoadOBJModel("content/ShipModels/TayHouse.obj");
	models[2] = DrawableModelLoader::LoadOBJModel("content/ShipModels/tay4.obj");
	models[3] = DrawableModelLoader::LoadOBJModel("content/Cryslis1.dat");
	Texture::LoadBitmap("content/ShipModels/tayShip2.bmp", models[0]->cacheTexture);
	Texture::LoadBitmap("content/ShipModels/TayHouse.bmp", models[1]->cacheTexture);
	Texture::LoadBitmap("content/Cryslis2.bmp", models[3]->cacheTexture);

	int numShips = rand() % 20 + 1;
	for (int i = 0; i < 100; i++)
	{
		BBShipModel* ship = new BBShipModel((float)(rand() % (int)width), 
											(float)(rand() % (int)height), 
											(float)(rand() % 360), 
											(float)(rand() % 2 + 5),
											models[rand() % 4]);
		
		shipList1.insert(ship);
	}
	
	DrawableModel* planetModel = DrawableModelLoader::LoadOBJModel("content/ShipModels/betterPlanetTop.obj");
	Texture::LoadBitmap("content/ShipModels/BetterPlanet.bmp", planetModel->cacheTexture);
	BBShipModel* planet = new BBShipModel(200, 100, 0, 50, planetModel);
	shipList1.insert(planet);

	// create a list of players
	ZList<BBPlayerModel*> playerList1;

	// create one player
	BBPlayerModel* player1 = new BBPlayerModel(shipList1);
	playerList1.insert(player1);

	// create background
	DrawableModel* backgroundModel = DrawableModelLoader::LoadOBJModel("content/backgrounds/starrybackground.dat");
	Texture::LoadBitmap("content/backgrounds/TayCustom1.bmp", backgroundModel->cacheTexture);
	BBShipModel* background = new BBShipModel(width/2,height/2,0,100000000, backgroundModel);

	BBModel* model = new BBModel(width, height, playerList1, background);

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	view->setGridDivision(100,100);
	return view;
}