#ifndef BBSHIP_MODEL_H
#define BBSHIP_MODEL_H
#include "NxPhysics.h"
#include "BBPlayerModel.h"
#include "OBJModel.h"
#include "Position.h"
#include "DrawableModel.h"
#include "Ship.h"

class BBPlayerModel;

class BBShipModel
{

public:
	BBShipModel(BBPlayerModel* parent, OBJModel* bounds = NULL);
	BBShipModel(float angle1, float scale1, BBPlayerModel* parent, OBJModel* bounds = NULL);
	BBShipModel(float x1, float y1, float angle, float scale, BBPlayerModel* parent, OBJModel* bounds = NULL);
	BBShipModel(float x1, float y1, float angle, float scale, DrawableModel* drawModel1, BBPlayerModel* parent, OBJModel* bounds = NULL);
	float getX();
	void setX(float x1);
	float getY();
	void setY(float y1);
	float getAngle();
	void setAngle(float angle);
	float getScale();
	void setScale(float scale);
	Ship* getShip();
	void setShip(Ship* ship);
	DrawableModel* getDrawModel();
	
	/* this is for fun */
	bool xGoingMax;
	bool xGoingMin;
	bool yGoingMax;
	bool yGoingMin;

private:

	
	float x;
	float y;
	float angle;
	float scale;

	NxBodyDesc bodyDesc;
	NxActor* shipActor;
	DrawableModel* drawModel;
	BBPlayerModel* parentPlayer;
	Ship* ship;	

	void setupPhysics(OBJModel* model, float scale=1);
};

#endif