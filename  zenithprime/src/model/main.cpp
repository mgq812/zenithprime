#include <iostream>

#include "Buff.h"
#include "Building.h"
#include "Planet.h"
#include "SolarSystem.h"

using namespace std;

void initBuildings(Building* &buildings, int& numBuildings)
{
	// init the memory
	numBuildings = 5;
	buildings = new Building[5];

	// auto factories
	Buff* autoFactBuffs = new Buff[2];
	autoFactBuffs[0].setup("Production", "+ 5", "Auto Factory");
	autoFactBuffs[1].setup("Production", "* .15", "Auto Factory");

	buildings[0].setup("Automated Factory", 1500, 2, autoFactBuffs);
		
	// research Labs
	Buff* researchLabBuffs = new Buff[2];
	researchLabBuffs[0].setup("Research", "+ 5", "Research Lab");
	researchLabBuffs[1].setup("Research", "* .1", "Research Lab");

	buildings[1].setup("Research Lab", 1500, 2, researchLabBuffs);

	// Starport
	buildings[2].setup("Starport", 1000, 1, new Buff("Money", "* .5", "Starport"));

	// housing
	buildings[3].setup("Housing", 0, 1, new Buff("Population", "+ .1 * Production", "Housing"));

	// marine Barraks
	Buff* mBuffs = new Buff[2];
	mBuffs[0].setup("Moral", "+ 10%", "Marine Barraks");
	mBuffs[1].setup("Ground Troops", "+ .2", "Marine Barraks");
	buildings[4].setup("Marine Barraks", 2000, 2, mBuffs);
}

void initGame(Building* &buildings, int& numBuildings)
{
	initBuildings(buildings, numBuildings);
}

int main()
{
	Building* buildings = NULL;
	int numBuildings = 0;

	initGame(buildings, numBuildings);
	
	for (int i = 0; i < numBuildings; i++)
	{
		buildings[i].display();
		cout << endl << endl;
		cout << "____________________________________" << endl;
	}

	system("pause");

	delete [] buildings;
	return 0;
}