#ifndef BUILGING_H
#define BUILGING_H

#include <string.h>

#include "Buff.h"

using namespace std;

class Planet;

class Building
{
 public:

	void display();
	void setup(string name1, float prodCost1, int buffAmt1, Buff* buffptr1);
	void addBuffs(Planet* p);

	// constructors
	Building()
		:name(""), prodCost(0), buffAmt(0), buffPtr(NULL)
	{}
	Building(string name1, float prodCost1)
		:name(name1), prodCost(prodCost1)
	{}
	Building(string name1, float prodCost1, int buffAmt1, Buff* buffptr1);
		
	// getters and setters
	string getName(){return name;}
	void setName(string name1){name = name1;}
	
	float getProdCost(){return prodCost;}
	void setProdCost(float prodCost1){prodCost = prodCost1;}
	
	int getBuffAmt(){return buffAmt;}
	void getBuffAmt(int buffAmt1){buffAmt = buffAmt1;}
	
	Buff* getBuffs(){return buffPtr;}
	void setBuffs(Buff* buffs1){buffPtr = buffs1;}
	//--------------------------------------------------------
 
private:
   string name;
   float prodCost;
   int buffAmt;
   Buff* buffPtr;    
};

#endif
