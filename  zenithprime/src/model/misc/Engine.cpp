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

#include "Engine.h"

Engine::Engine()
	:GALMUL(-1)
{
	combatThrust = 1.0;
	/* gal Speed is undeclared? */
	// galSpeed = 10.0;
	status = 100.0;	//1?
}

/*
 * Constructor
 */
Engine::Engine(Enums::Type make)
		:GALMUL(-1)	
{
	initEngine(make);
}

void Engine::initEngine(Enums::Type make)
{

	//switch (make)
	//{
	//	case(Enums::fission):
	//		type = make;
	//		mass = 1;
	//		combatThrust = 10.0;
	//		hyperThrust = tacSpeed*GALMUL;
	//		status = 100.0;
	//		break;

	//	case(Enums::pulse):
	//		type = make;
	//		mass = 2;
	//		combatThrust = 15.0;
	//		hyperThrust = tacSpeed*GALMUL;
	//		status = 100.0;
	//		break;

	//	case(Enums::fusion):
	//		type = make;
	//		mass = 3;
	//		combatThrust = 20.0;
	//		hyperThrust = tacSpeed*GALMUL;
	//		status = 100.0;
	//		break;
	//		
	//	case(Enums::anti-matter):
	//		type = make;
	//		mass = 5;
	//		combatThrust = 40.0;
	//		hyperThrust = tacSpeed*GALMUL;
	//		status = 100.0;
	//		break;

	//	case(Enums::phase):	// acceleration from this drive not affected by mass?
	//		type = make;
	//		mass = 9;
	//		combatThrust = 80.0;
	//		hyperThrust = tacSpeed*GALMUL;
	//		status = 100.0;
	//		break;
	//	default:
	//		break;
	//}
}

/*
 * Copy constructor
 */
Engine::Engine (const Engine &other)
	:GALMUL(-1)
{
	/* no member tacSpeed */
	//combatThrust = other.tacSpeed;
	/* no member galSpeed */
	//hyperThrust = other.galSpeed;
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
		/* tacSpeed and gal Speed undefined */
		//combatThrust = other.tacSpeed;
		//hyperThrust = other.galSpeed;
		fuelCellCount = other.fuelCellCount;
		status = other.status;
	}
	return *this;
}

/*******************************************
	Set Speeds
********************************************/
void Engine::setCombatThrust (float adjustSpeed)
{
	combatThrust = adjustSpeed;
}


void Engine::setHyperThrust()
{
	hyperThrust = combatThrust*GALMUL;
}

/*******************************************
	Get Speeds
********************************************/
float Engine::getCombatThrust()
{
	return combatThrust;
}


float Engine::getHyperThrust()
{
	return hyperThrust;
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
	// tac and gal speed undefined
	//engineSpec = "This engine is a default tester.\nTactical Speed: "<<tacSpeed<<"\nGalactic Speed: "<<galSpeed<<endl;
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



