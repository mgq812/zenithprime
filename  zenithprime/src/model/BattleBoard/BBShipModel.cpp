#include "BBShipModel.h"

BBShipModel::BBShipModel()
	:angle(0), scale(0)
{
	drawModel = DrawableModel::NULLDrawableModel();
}

BBShipModel::BBShipModel(float angle1, float scale1)
	:x(0), y(0), angle(angle1), scale(scale1)
{
	drawModel = DrawableModel::NULLDrawableModel();
}

BBShipModel::BBShipModel(int x1, int y1, float angle1, float scale1)
	:x(x1), y(y1), angle(angle1), scale(scale1)
{
	drawModel = DrawableModel::NULLDrawableModel();
}

int BBShipModel::getX()
{
	return x;
}

int BBShipModel::getY()
{
	return y;
}

void BBShipModel::setX(int x1)
{
	x = x1;
}

void BBShipModel::setY(int y1)
{
	y = y1;
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