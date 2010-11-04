#ifndef BBSHIP_MODEL_H
#define BBSHIP_MODEL_H

#include "Position.h"
#include "Ship.h"

class BBShipModel
{
public:
	BBShipModel();
	BBShipModel(Position position1, float angle1, float scale1);
	BBShipModel(int x, int y, float angle, float scale);
	Position getPosition();
	void setPosition(Position position);
	float getAngle();
	void setAngle(float angle);
	float getScale();
	void setScale(float scale);
	Ship* getShip();
	void setShip(Ship* ship);

private:
	Position position;
	float angle;
	float scale;
	//Bitmap texture;
	//3DModel model;
	Ship* ship;

};

#endif