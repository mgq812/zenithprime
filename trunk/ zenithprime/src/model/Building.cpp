#include <iostream>
#include <string>
#include "Building.h"

using namespace std;

void Building::display()
{
	cout << name << endl;
	cout << "  Cost: " << prodCost << endl;
	cout << "  Buffers: " << buffAmt << endl;

	for (int i = 0; i < buffAmt; i++)
	{
		cout << endl;
		buffPtr[i].display();
	}
}

void Building::setup(string name1, float prodCost1, int buffAmt1, Buff* buffPtr1)
{
	name = name1;
	prodCost = prodCost1;
	buffAmt = buffAmt1;
	buffPtr = buffPtr1;
}

void Building::addBuffs(Planet* p)
{
	for (int i = 0; i < buffAmt; i++)
	{
		// p->mod(buffPtr[i]->getType, buffPtr[i]->getValue(); buffPtr->getName());
	}
}