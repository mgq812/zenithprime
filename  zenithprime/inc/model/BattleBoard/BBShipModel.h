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
	BBShipModel(int x1, int y1, float angle, float scale);
	int getX();
	void setX(int x1);
	int getY();
	void setY(int y1);
	float getAngle();
	void setAngle(float angle);
	float getScale();
	void setScale(float scale);
	Ship* getShip();
	void setShip(Ship* ship);
	DrawableModel* getDrawModel();
	
	DrawableModel* drawModel;

private:
	int x;
	int y;
	float angle;
	float scale;
	//Bitmap texture;
	Ship* ship;
	
};

#endif