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

void addEnginesOptions()
{
	cout << "1. Add existing engine" << endl;
	cout << "2. Add new engine" << endl;
	cout << "q. Back" << endl;
}

void addEngines()
{
	string q;

	while (q != "q" && q != "quit")
	{
		system("cls");
		addEnginesOptions();
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
	}
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
			addEngines();
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
		else if (q == "5")
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
			system("cls");

			cout << "Ship name: ";
			string name;
			getline(cin, name);

			int size = -1;
			while (true)
			{
				cout << "Ship size [0 - 10]" << endl; 
				string sSize;
				getline(cin, sSize);
				size = atoi(sSize.c_str());
				if (size >= 0 || size <= 10)
					break;
				cout << "Invalid Size" << endl;
				getline(cin, sSize);
			}

			Ship* ship = new Ship(name, size);
			makeShip();
		}
		else if (q == "2")
		{
			cout << "Not yet implemented" << endl;
		}
	}
}
/*
int main()
{
	while (true)
	{
		system("cls");
		string temp;
		cout << "Size [0 - 10] " << endl;
		getline(cin, temp);
	
		if (temp == "q")
			break;

		Ship s("bob", atoi(temp.c_str()));
		cout << "Base Mass = " << s.getMass() << endl;
		getline(cin, temp);
	}

	string enter;
	
	intro();
	getline(cin, enter);

	mainMenu();
	return 0;
}
*/