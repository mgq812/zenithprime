#include "Ship.h"

#include <string>

Ship::Ship()
  :engine('\0'), size(0)
{}

Ship::Ship(Engine* engine1, float size1, string name1)
  :engine(engine1), size(size1), name(name1)
{}

float Ship::getSpeed()
{
  return size * engine->getSpeed();
}

float Ship::getSize()
{
  return size;
}

string Ship::getName()
{
  return name;
}
