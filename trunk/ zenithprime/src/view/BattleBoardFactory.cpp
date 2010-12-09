#include "BattleBoardFactory.h"
#include "DrawableModelLoader.h"
#include "BBControllerInterface.h"
#include "BBControler.h"
#include "TextureLoader.h"

using namespace std;

static FactoryVisitor* visitor = new FactoryVisitor();
void BattleBoardFactory::SetFactory(FactoryVisitor* v){
	visitor = v;
}

BattleBoardView* BattleBoardFactory::CreateBoard(float width, float height){
	
	BBModel* model = new BBModel(width, height);
	visitor->AddBackground(model);
	visitor->AddLights(model);
	visitor->AddShips(model->getPlayers().getHead()->getData(), model);

	// create a list of ships
	ZList<BBShipModel*> shipList1;
	
	// create a bunch of ships
	const int numShips = 3;
	DrawableModel* models[numShips];
	/*models[0] = DrawableModelLoader::LoadOBJModel("content/ShipModels/tayShip2.obj");
	models[1] = DrawableModelLoader::LoadOBJModel("content/ShipModels/TayHouse.obj");
	models[2] = DrawableModelLoader::LoadOBJModel("content/ShipModels/tay4.obj");
	models[3] = DrawableModelLoader::LoadOBJModel("content/Cryslis1.dat");
	models[4] = DrawableModelLoader::LoadOBJModel("content/ShipModels/ship5.obj");
	Texture::LoadBitmap("content/ShipModels/tayShip2.bmp", models[0]->cacheTexture);
	Texture::LoadBitmap("content/ShipModels/TayHouse.bmp", models[1]->cacheTexture);
	Texture::LoadBitmap("content/Cryslis2.bmp", models[3]->cacheTexture);
	Texture::LoadBitmap("content/ShipModels/Ship5.bmp", models[4]->cacheTexture);*/
	models[0] = DrawableModelLoader::LoadOBJModel("content/ships/ghouledited.obj");
	models[1] = DrawableModelLoader::LoadOBJModel("content/convertedships/awing/awing.obj");
	models[2] = DrawableModelLoader::LoadOBJModel("content/convertedships/combatship/combatship.obj");
	//models[3] = DrawableModelLoader::LoadOBJModel("content/convertedships/shuttle/shuttle.obj");
	////models[1] = DrawableModelLoader::LoadOBJModel("content/convertedships/spacehawk/spacehawk.obj");
	////models[1] = DrawableModelLoader::LoadOBJModel("content/convertedships/spacejet/spacejet.obj");
	////models[1] = DrawableModelLoader::LoadOBJModel("content/convertedships/usswall/usswall.obj");
	////models[1] = DrawableModelLoader::LoadOBJModel("content/convertedships/xwing/xwing.obj");


	Texture::LoadBitmap("content/ships/ghoul_map.bmp", models[0]->cacheTexture);
	Texture::LoadBitmap("content/convertedships/awing/AWHuVen.bmp", models[1]->cacheTexture);
	Texture::LoadBitmap("content/convertedships/combatship/nave.bmp", models[2]->cacheTexture);


	for (int i = 0; i < 100; i++)
	{
		BBShipModel* ship = new BBShipModel((float)(rand() % (int)width), 
											(float)(rand() % (int)height), 
											(float)(rand() % 360), 
											(float)(rand() % 2 + 5),
									models[rand() % numShips]);
		
		shipList1.insert(ship);
	}
	
	/*DrawableModel* planetModel = DrawableModelLoader::LoadOBJModel("content/ShipModels/betterPlanetSide.obj");
	Texture::LoadBitmap("content/ShipModels/Earth.bmp", planetModel->cacheTexture);
	BBShipModel* planet = new BBShipModel(200, 100, 0, 50, planetModel);
	shipList1.insert(planet);*/

	DrawableModel* planetModel1 = DrawableModelLoader::LoadOBJModel("content/planets/planet.obj");
	Texture::LoadBitmap("content/planets/planettexture.bmp", planetModel1->cacheTexture);
	BBShipModel* planet1 = new BBShipModel(width, height, 0, 10, planetModel1);
	shipList1.insert(planet1);

	// create a list of players
	ZList<BBPlayerModel*> playerList1;

	// create one player
	BBPlayerModel* player1 = new BBPlayerModel(shipList1);
	playerList1.insert(player1);

	// create background
	DrawableModel* backgroundModel = DrawableModelLoader::LoadOBJModel("content/backgrounds/planetbackground.obj");
	Texture::LoadBitmap("content/backgrounds/best/blueplanet.bmp", backgroundModel->cacheTexture);
	BBShipModel* background = new BBShipModel(width/2,height/2,0,100000000, backgroundModel);

	BBModel* model = new BBModel(width, height, playerList1, background);

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	view->setGridDivision(100,100);

	BBControllerInterface* BBInter = new BBControllerInterface(model, new BBControler(model));

	controller->setFacade(BBInter);
	return view;
}