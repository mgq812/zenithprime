// SYSTEM COMMANDS ARE WINDOWS ONLY NOT LINUX

#include <iostream>
#include <string>

#include "..\..\inc\model\Ship.h"

using namespace std;

void intro()
{
	cout << "Welcome to the Shipyard  Ver 1.0" << endl;
	cout << "..." << endl << endl << endl;
}

void makeShipOptions()
{
	cout << "1. Add Engines" << endl;
	cout << "2. Add Weapons" << endl;
	cout << "3. Add Defences" << endl;
	cout << "4. Add Specials" << endl;
	cout << "5. Save Ship" << endl;
	cout << "q. Back" << endl;
}

void makeShip()
{
	string q;

	while (q != "q" && q != "quit")
	{
		system("cls");
		makeShipOptions();
		cout << ": ";
		getline(cin, q);

		if (q == "1")
		{
			cout << "Not yet implemented" << endl;
		}
		else if (q == "2")
		{
			cout << "Not yet implemented" << endl;
		}
		else if (q == "3")
		{
			cout << "Not yet implemented" << endl;
		}
		else if (q == "4")
		{
			cout << "Not yet implemented" << endl;
		}
	}
}

void mainMenuOptions()
{
	cout << "1. Make a new ship" << endl;
	cout << "2. Mod an existing ship" << endl;
	cout << "q. Quit" << endl;
}

void mainMenu()
{
	string q;

	while (q != "q" && q != "quit")
	{
		system("cls");
		mainMenuOptions();
		cout << ": ";
		getline(cin, q);

		if (q == "1")
		{
			makeShip();
		}
		else if (q == "2")
		{
			cout << "Not yet implemented" << endl;
		}
	}
}

int main()
{
	string enter;
	
	intro();
	getline(cin, enter);

	mainMenu();
	
	return 0;
}