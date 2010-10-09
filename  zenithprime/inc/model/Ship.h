#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship
{
 public:
   Ship();
   Ship(Engine* engine1, float size1, string name1);
   
   float getSize();        
   float getSpeed();
   string getSpeed();
   
 private:      
   // components of a ship
   Engine* engine;
   // This is an idea of future components
   // Structure* structure;
   // Armor* armor;
   // Shields* shields;
   // ShipSystem* system;
   // Attack* attack;    ??? these two might further split into beam 
   // Defence* defence;  ???   missle bomb and special
   // Weapon* weaponList; ??? this might replace attack
   // Specials* specials; ??? have no clue what this class is yet
   
   // attributes of a ship
   float size;
   string name;
};

#endif
