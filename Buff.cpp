#include <string>
#include <iostream>
#include "Buff.h"

using namespace std;

void Buff::display()
{
	cout << "  Buffs: " << key << endl;
	cout << "  " << type << endl;
	cout << "  " << value << endl;
}

void Buff::setup(string type1, string value1, string key1)
{
	type = type1;	// the type of buff Ex: Production
	value = value1;	// the value applied from buff Ex: *.5
	key = key1;		// the name of the user Ex: Auto Factory
}