#include "BBShipModel.h"
#include "Position.h"

BBShipModel::BBShipModel()
	:angle(0), scale(0)
{}

BBShipModel::BBShipModel(Position position1, float angle1, float scale1)
	:position(position1), angle(angle1), scale(scale1)
{}

BBShipModel::BBShipModel(int x, int y, float angle1, float scale1)
	:position(x, y), angle(angle1), scale(scale1)
{}

Position BBShipModel::getPosition()
{
	return position;
}

void BBShipModel::setPosition(Position position1)
{
	position.x = position1.x;
	position.y = position1.y;
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
