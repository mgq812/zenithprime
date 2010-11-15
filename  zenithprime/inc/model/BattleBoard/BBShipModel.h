#ifndef BBSHIP_MODEL_H
#define BBSHIP_MODEL_H

#include "Position.h"
#include "DrawableModel.h"
#include "Ship.h"

class BBShipModel
{

public:
	BBShipModel();
	BBShipModel(float angle1, float scale1);
	BBShipModel(float x1, float y1, float angle, float scale);
	BBShipModel(float x1, float y1, float angle, float scale, DrawableModel* drawModel1);
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

	//Bitmap texture;
	DrawableModel* drawModel;
	Ship* ship;	
};

#endif