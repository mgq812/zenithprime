#include "FactoryVisitor.h"
#include "DrawableModelLoader.h"
#include "TextureLoader.h"
#include <time.h>


void FactoryVisitor::AddBackground(BBModel* model){
	DrawableModel* backgroundModel = DrawableModelLoader::LoadOBJModel("content/backgrounds/planetbackground.obj");
	Texture::LoadBitmap("content/backgrounds/best/blueplanet.bmp", backgroundModel->cacheTexture);

	model->setBackground(backgroundModel);
}
void FactoryVisitor::AddLights(BBModel* model){

}
void FactoryVisitor::AddPlayers(BBModel* model){

}
void FactoryVisitor::AddShips(BBPlayerModel* playerModel, BBModel* model){
	
	srand(time(NULL));
	const int numShips = 3;

	DrawableModel* models[numShips];
	OBJModel* objs[numShips];

	objs[0] = OBJloader::loadModelFromFile("content/ShipModels/tayShip2.obj");
	models[0] = DrawableModelLoader::LoadOBJModel(objs[0]);

	objs[1] = OBJloader::loadModelFromFile("content/Cryslis1.dat");
	models[1] = DrawableModelLoader::LoadOBJModel(objs[1]);

	objs[2] = OBJloader::loadModelFromFile("content/ShipModels/ship5.obj");
	models[2] = DrawableModelLoader::LoadOBJModel(objs[2]);

	//objs[3] = OBJloader::loadModelFromFile("content/ships/ghouledited.obj");
	//models[3] = DrawableModelLoader::LoadOBJModel(objs[3]);

	//objs[4] = OBJloader::loadModelFromFile("content/ships/awing.obj");
	//models[4] = DrawableModelLoader::LoadOBJModel(objs[4]);

	//objs[5] = OBJloader::loadModelFromFile("content/ships/combatship.obj");
	//models[5] = DrawableModelLoader::LoadOBJModel(objs[5]);

	Texture::LoadBitmap("content/ShipModels/tayShip2.bmp", models[0]->cacheTexture);
	Texture::LoadBitmap("content/ShipModels/BlueGrayCarbonScoring.bmp", models[1]->cacheTexture);
	Texture::LoadBitmap("content/ShipModels/Ship5.bmp", models[2]->cacheTexture);
	/*Texture::LoadBitmap("content/ships/ghoul_map.bmp", models[3]->cacheTexture);
	Texture::LoadBitmap("content/ships/AWHuVen.bmp", models[4]->cacheTexture);
	Texture::LoadBitmap("content/ships/NAVE.bmp", models[5]->cacheTexture);*/

	for(int i = 0; i < 10; i++)
		for(int j = 0; j<3; j++){
			BBShipModel* ship = new BBShipModel(i*20,j*40+200, 0, 1, models[j], playerModel, objs[j]);

			playerModel->addShip(ship);
		}

	for(int i = 0; i < 10; i++)
		for(int j = 0; j<3; j++){
			BBShipModel* ship = new BBShipModel(i*20,model->getHeight()-200- j*40, 180, 1, models[2-j], playerModel, objs[2-j]);

			playerModel->addShip(ship);
		}


	/*OBJModel* planetOBJ = OBJloader::loadModelFromFile("content/ShipModels/betterPlanetSide.obj");
	DrawableModel* planetModel = DrawableModelLoader::LoadOBJModel(planetOBJ);
	Texture::LoadBitmap("content/ShipModels/Earth.bmp", planetModel->cacheTexture);
	BBShipModel* planet = new BBShipModel(200, 100, 0, 50, planetModel, playerModel, planetOBJ);

	playerModel->addShip(planet);*/

	OBJModel* planetOBJ1 = OBJloader::loadModelFromFile("content/planets/planet.obj");
	DrawableModel* planetModel1 = DrawableModelLoader::LoadOBJModel(planetOBJ1);
	Texture::LoadBitmap("content/planets/planettexture.bmp", planetModel1->cacheTexture);
	BBShipModel* planet1 = new BBShipModel(model->getWidth(),model->getHeight(), 0, 10, planetModel1, playerModel, planetOBJ1);

	playerModel->addShip(planet1);
}
