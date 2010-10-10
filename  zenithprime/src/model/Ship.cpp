#include <string>
using namespace std;

#include "..\..\inc\model\ship.h"

Ship::Ship()
  :/*engine('\0'), */size(0)
{}

Ship::Ship(/* Engine* engine1, */ int size1, string name1, float mass1)
  :/* engine(engine1), */ size(size1), name(name1), mass(mass1)
{}

// getters
float Ship::getSpeed()
{
  return 0;
  //getforceOfAllEngines() / mass;
}
int Ship::getSize()
{
  return size;
}
float Ship::getMass()
{
	return mass;
}
string Ship::getName()
{
  return name;
}
/*Engine* Ship::getEngine()
{
	return engine;
}*/

// setters
void Ship::setSize(int size1)
{
	size = size1;
}
void Ship::setName(string name1)
{
	name = name1;
}
void Ship::setMass(float mass1)
{
	mass = mass1;
}
/*void Ship::setEngine(Engine* engine1)
{	
	engine = engine1;
}*/