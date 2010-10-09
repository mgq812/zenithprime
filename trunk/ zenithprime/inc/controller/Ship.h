#ifndef SHIP_H
#define SHIP_H

class Ship
{
 public:
   Ship();
   Ship(Engine* e, float s);
   
   float getSize();        
   float getSpeed();
   
 private:      
   Engine* engine;
   float size;
};

#endif
