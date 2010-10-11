//------------------------------------------------------
//
//	file: Engine.cpp	Author: Alan Branch
//				Started: 9 Oct 2010
//
//	Source file for ship engines
//
//    	For use with ProjectZenithPrime
//
//------------------------------------------------------

#include "../inc/Engine.h"

Engine::Engine()
{
	tacSpeed = 1.0;
	galSpeed = 10.0;
	status = 100.0;	//1?
}

/*
 * Constructor
 */
Engine::Engine(Enums::Type make)
{
	initEngine(make);
}

void Engine::initEngine(Enums::type make)
{
	float GALMUL = 10.0;		// Galactic multiplier---make global final
	switch (make)
	{
		case(Enums::basicTest):
			type = make;
			mass = 1;
			tacSpeed = 10.0;
			galSpeed = tacSpeed*GALMUL;
			fuelCellCount = 2;
			status = 100.0;
			break;

		default:
			break;
	}
}

/*
 * Copy constructor
 */
Engine::Engine (const Engine &other)
{
	tacSpeed = other.tacSpeed;
	galSpeed = other.galSpeed;
	fuelCellCount = other.fuelCellCount;
	status = other.status;
}

/*
 * Destructor
 */
Engine::~Engine()
{
}

/*
 * Assignment operator
 */
Engine& Engine::operator = (const Engine &other)
{
	if (this !=&other)
	{
		tacSpeed = other.tacSpeed;
		galSpeed = other.galSpeed;
		fuelCellCount = other.fuelCellCount;
		status = other.status;
	}
	return *this;
}

/*******************************************
	Set Speeds
********************************************/
void Engine::setTacSpeed (float adjustSpeed)
{
	tacSpeed = adjustSpeed;
}


void Engine::setGalSpeed(float adjustSpeed)
{
	galSpeed = adjustSpeed;
}

/*******************************************
	Get Speeds
********************************************/
float Engine::getTacSpeed()
{
	return tacSpeed;
}


float Engine::getGalSpeed()
{
	return galSpeed;
}

/*******************************************
	Fuel Cells
********************************************/

void Engine::setCellCount(int addCells)
{
	fuelCellCount = addCells;
}


int Engine::getCellCount()
{
	return fuelCellCount;
}


void Engine::addFuelCell(int addCells)
{
	fuelCellCount = fuelCellCount + addCells;
}

/*******************************************
	Engine Status
********************************************/
void Engine::setEngineStatus (float percent)
{
	status = percent;
}

float Engine::getEngineStatus ()
{
	return status;
}

/*******************************************
	Engine Type
********************************************/

void Engine::setEngineType (Enums::Type make)
{
	type = make;
}

Enums::Type Engine::getEngineType()
{
	return type;
}


void Engine::setEngineMass(float mass)
{
	mass = mass;
}


float Engine::getEngineMass()
{
	return mass;
}

string Engine::typeToString()
{
	string engineSpec;
	engineSpec = "basicTest";
	return engineSpec;
}

string Engine::getSpecs()
{
	string engineSpec;
	engineSpec = "This engine is a default tester.\nTactical Speed: "<<tacSpeed<<"\nGalactic Speed: "<<galSpeed<<endl;
	return engineSpec;
}


/*
 * Tests functionality of Engine
 *
 * @Parameter: ostream
 *
 * Returns:
 * bool - True if all test cases pass
 *        False otherwise
 *
 * Verifies:
 *
 */
bool Engine::Test(ostream & os)
{
	bool success = true;

	return success;
}



