#ifndef SHIP_H
#define SHIP_H

#include <string>

using namespace std;

class Ship
{
 public:
   Ship();
   Ship(/* Engine* engine1, */ int size1, string name1, float mass1);
   
   int getSize();        
   float getSpeed();
   float getMass();
   string getName();
   // Engine* getEngine();
   
   void setSize(int size1);
   void setName(string name1);
   void setMass(float mass1);
   // void setEngine(Engine* engine1);

   
 private:      
   // components of a ship
   // Engine* engine;
   // Structure* structure;
   // Armor* armor;
   // Shields* shields;
   // ShipSystem* system;
   // Attack* attack;    ??? these two might further split into beam 
   // Defence* defence;  ???   missle bomb and special
   // Weapon* weaponList; ??? this might replace attack
   // Specials* specials; ??? have no clue what this class is yet
   
   // attributes of a ship
   int size;
   float mass;
   string name;
};

#endif
