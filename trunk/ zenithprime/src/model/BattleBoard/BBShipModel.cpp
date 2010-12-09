#include "BBShipModel.h"

BBShipModel::BBShipModel(BBPlayerModel* parent,  OBJModel* bounds)
	:angle(0), scale(0)
{
	drawModel = DrawableModel::NULLDrawableModel();
	parentPlayer = parent;
	setupPhysics(bounds);
	setX(0);
	setY(0);
}

BBShipModel::BBShipModel(float angle1, float scale1, BBPlayerModel* parent,  OBJModel* bounds)
	:x(0), y(0), angle(angle1), scale(scale1)
{
	drawModel = DrawableModel::NULLDrawableModel();
	parentPlayer = parent;
	setupPhysics(bounds, scale1);
	setX(0);
	setY(0);
}

BBShipModel::BBShipModel(float x1, float y1, float angle1, float scale1, DrawableModel* drawModel1, BBPlayerModel* parent,  OBJModel* bounds)
	:x(x1), y(y1), angle(angle1), scale(scale1), drawModel(drawModel1)
{
	srand(x1);
	int temp = rand() % 2;
	if (temp == 1)
	{	
		xGoingMax = true;
		xGoingMin = false;
	}
	else
	{	
		xGoingMax = false;
		xGoingMin = true;
	}

	temp = rand() % 2;
	if (temp == 1)
	{	
		yGoingMax = true;
		yGoingMin = false;
	}
	else
	{	
		yGoingMax = false;
		yGoingMin = true;
	}

	parentPlayer = parent;
	setupPhysics(bounds, scale1);
	setX(x1);
	setY(y1);
}

BBShipModel::BBShipModel(float x1, float y1, float angle1, float scale1, BBPlayerModel* parent, OBJModel* bounds)
	: angle(angle1), scale(scale1)
{
	parentPlayer = parent;
	drawModel = DrawableModel::NULLDrawableModel();
	setupPhysics(bounds, scale1);
	setX(x1);
	setY(y1);
}

float BBShipModel::getX()
{
	if(shipActor!=NULL)
		x = shipActor->getGlobalPosition().x;
	return x;
}

float BBShipModel::getY()
{
	if(shipActor!=NULL)
		y = shipActor->getGlobalPosition().z;
	return y;
}

void BBShipModel::setX(float x1)
{
	x = x1;
	if(shipActor!=NULL)
		shipActor->setGlobalPosition(NxVec3(x, 0, y));
}

void BBShipModel::setY(float y1)
{
	y = y1;
	if(shipActor!=NULL)
		shipActor->setGlobalPosition(NxVec3(x, 0, y));
}

float BBShipModel::getAngle()
{
	return angle;
}

void BBShipModel::setAngle(float angle1)
{
	angle = angle1;
}

float BBShipModel::getScale()
{
	return scale;
}

void BBShipModel::setScale(float scale1)
{
	scale = scale1;
}

Ship* BBShipModel::getShip()
{
	return ship;
}

void BBShipModel::setShip(Ship* ship1)
{
	ship = ship1;
}

DrawableModel* BBShipModel::getDrawModel(){
	return drawModel;
}
void BBShipModel::setupPhysics(OBJModel* model, float scale){
	shipActor = NULL;
	if(parentPlayer ==NULL)
		return;
	
	if(model==NULL)
		model = OBJModel::NullOBJModel();

		NxBoxShapeDesc boxDesc;
		// plane equation : ax + by + cz + d = 0
		float cX = (model->smallestX + model->largestX)/2;
		float cY = (model->smallestY + model->largestY)/2;
		float cZ = (model->smallestZ + model->largestZ)/2;
		float width2 = model->largestX-cX;
		float height2 = model->largestY-cY;
		float depth2 = model->largestZ-cZ;

		boxDesc.dimensions.set(width2*scale, height2*scale, depth2*scale);
		boxDesc.mass = width2*height2*depth2*scale*scale*scale;
		boxDesc.localPose.t = NxVec3(cX, cY, cZ);
		boxDesc.userData = this;

		// actor descriptor with collection of shapes
		NxActorDesc actorDesc;
		actorDesc.shapes.pushBack( &boxDesc );
		actorDesc.density = 10;
		actorDesc.body = &bodyDesc;
		shipActor = parentPlayer->parentBoard->getPScene()->createActor(actorDesc);

		//shipActor->raiseBodyFlag(NX_BF_FROZEN_POS_Y);
		//shipActor->raiseBodyFlag(NX_BF_FROZEN_ROT_X);
		//shipActor->raiseBodyFlag(NX_BF_FROZEN_ROT_Z);
}