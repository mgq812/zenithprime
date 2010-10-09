#include "Ship.h"

Ship::Ship()
  :engine('\0'), size(0)
{}

Ship::Ship(Engine* e, float s)
  :engine(e), size(s)
{}

float Ship::getSpeed()
{
  return size * engine->getSpeed();
}

float Ship::getSize()
{
  return size;
}
