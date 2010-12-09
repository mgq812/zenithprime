#include "BBShipModel.h"
#include "BBPlayerModel.h"
#include "BBModel.h"
#include <time.h>

BBModel::BBModel(float width1, float height1)
	:width(width1), height(height1)
{
	setupNeutralPlayer();
	setupPhysics();
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


void BBModel::getAllShips(std::vector<BBShipModel*>& list)
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

			if (curX >= 1000)
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
			if(animate){
				if (singleShip->xGoingMax)
					singleShip->setX(curX += 2);
				if (singleShip->yGoingMax)
					singleShip->setY(curY += 2);
				if (singleShip->xGoingMin)
					singleShip->setX(curX -= 2);
				if (singleShip->yGoingMin)
					singleShip->setY(curY -= 2);
				
				singleShip->setAngle(singleShip->getAngle() + .1);
			}
			list.push_back(singleShip);

			shipNode = shipNode->getNext();
		}

		playerNode = playerNode->getNext();
	}
}
void BBModel::getAllGhostShips(std::vector<BBShipModel*>& list){
}
void BBModel::getSelectedShips(std::vector<BBShipModel*>& list){
}

void BBModel::setBackground(DrawableModel* back){
	background = back;
}
DrawableModel* BBModel::getBackground()
{
	return background;
}

NxRaycastHit BBModel::CastRay(float x, float y, float z, float dx, float dy, float dz){
	NxRay worldRay; 
	worldRay.orig = NxVec3(x,y,z);
	worldRay.dir = NxVec3(dx,dy,dz);
	worldRay.dir.normalize(); //Important!!

	NxRaycastHit hit;
	pScene->raycastClosestShape(worldRay,NX_ALL_SHAPES, hit);
	return hit;
}

void BBModel::setupPhysics(){
	pPhysicsSDK = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION);

	if ( pPhysicsSDK != NULL ){
		pPhysicsSDK->getFoundationSDK().getRemoteDebugger()->connect ("localhost", 5425);
	}
	else
		return;

	NxSceneDesc sceneDesc;
	sceneDesc.gravity.set ( 0, 0, 0 );

	pScene = pPhysicsSDK->createScene(sceneDesc);

	NxPlaneShapeDesc planeDesc;
		// plane equation : ax + by + cz + d = 0
	planeDesc.normal = NxVec3 ( 0, 1, 0 );
	planeDesc.d = 0.0f;
	planeDesc.userData = "BOARD";
		// actor descriptor with collection of shapes
	NxActorDesc actorDesc;
	actorDesc.shapes.pushBack( &planeDesc );

	NxPlaneShapeDesc planeDesc2;
	planeDesc2.normal = NxVec3 ( 0, -1, 0 );
	planeDesc2.d = 0.0f;
	actorDesc.shapes.pushBack( &planeDesc2 );

	actorDesc.userData = "ACTOR";
		// NxScene creates actor and returns a pointer.
	boardActor = pScene->createActor( actorDesc );
	//boardActor->userData = "BLANK";
}

void BBModel::setupNeutralPlayer(){
	players.insert(new BBPlayerModel(this));
}

NxScene* BBModel::getPScene(){
	return pScene;
}