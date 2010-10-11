//------------------------------------------------------
//
//	file: Engine.h		Author: Alan Branch
//				Started: 8 Oct 2010
//
//	Header file for ship engines
//
//    		For use with ProjectZenithPrime
//
//------------------------------------------------------

#ifndef ENGINE_H
#define ENGINE_H

#include "Enums.h"
#include "FuelCell.h"
#include <string>

using namespace std;

class Engine
{

public:

	/*
	 * Default constructor\par
	 */
	Engine();

	/*
	 * Constructor
	 *
	 * Parameters:
	 * Enums:Type make - the type of engine
	 * FuelCell cell - fuel cell loaded into engine.
	 * int cellCount - the number of fuel cells loaded into engine
	 */
	Engine(Enums::Type make, FuelCell cell, int cellCount);

	/*
	 * Sets Engine parameters based on engine type
	 */
	void initEngine(Enums::type make);

	/*
	 * Copy constructor
	 */
	Engine (const Engine &other);

	/*
	 * Destructor
	 */
	~Engine();

	/*
	 * Assignment operator
	 */
	Engine& operator = (const Engine &other);


/*******************************************
		Speeds
********************************************/

	/*
	 * Sets the tactical speed
	 *
	 * Parameters:
	 * float adjustSpeed
	 *
	 * Returns:
	 * void
	 */
	void setTacSpeed (float adjustSpeed);

	/*
	 * Sets the Galactic travel speed
	 *  
	 * Parameters:
	 * float adjustSpeed
	 *
	 * Returns:
	 * void
	 */
	void setGalSpeed(float adjustSpeed);

	/*
	 * Gets the tactical speed
	 *
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * float tacSpeed
	 */
	float getTacSpeed();

	/*
	 * Gets the Galactic travel speed\par
	 *
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * float galSpeed
	*/
	float getGalSpeed();

/*******************************************
		Fuel
********************************************/

	/*
	 * Sets the number of fuel cells
	 *
	 * Parameters:
	 * int addCells
	 *
	 * Returns:
	 * void
	*/
	void setCellCount(int addCells);

	/*
	 * Gets the number of fuel cells
	 *
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * int fuelCellCount;
	*/
	int getCellCount();

	/*
	 * Adds a number of fuel cells to the current stock
	 *
	 * Parameters:
	 * int addCells
	 *
	 * Returns:
	 * void
	*/
	void addFuelCell(int addCells);

/*******************************************
		Status
********************************************/

	/*
	 * Sets the engine's efficiency
	 *
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * float galSpeed
	 */
	void setEngineStatus (float percent);


	/*
	 * Gets the engine's efficiency
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * float galSpeed
	 */
	float getEngineStatus ();

/*******************************************
		Type
********************************************/

	/*
	 * Sets the engine's make and model
	 * Parameters:
	 * Enums Type: make
	 *
	 * Returns:
	 * void
	 */
	void setEngineType (Enums::Type make);

	/*
	 * Gets the engine's make and model
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * Enums Type: type
	 */
	Enums::Type getEngineType();


	/*
	 * Sets the engine's mass
	 * Parameters:
	 * float mass;
	 *
	 * Returns:
	 * void
	 */
	void setEngineMass(float mass);

	/*
	 * Gets the engine's mass
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * float - mass
	 */
	float getEngineMass();


	/*
	 * Returns make and model as a string
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * string - engine type converted to string
	 */
	string typeToString();

	/*
	 * Gets the engine specifications/description
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * string: the engine type specifications/description
	 */
	string getSpecs();




/*******************************************
		Test
********************************************/

	/*
	 * Tests functionality of Coord
	 *
	 * @Parameter: ostream
	 *
	 * Returns:
	 * bool - True if all test cases pass
	 *        False otherwise
	 *
	 * Verifies:
	 * Constructors, Assignment operator
	 * Setting and getting of tactical and galactic speeds
	 * Setting and getting of engine status
	 *
	 */
	static bool Test(ostream & os);


private:
	Enums type;		// Engine make and model
	float mass;		// engine mass
	float tacSpeed;		// tactical combat speed
	float galSpeed;		// Galactic travel speed
	float status;		// health/effeciency of engine
	FuelCell cellType;	// Type of cells loaded into engine
	int fuelCellCount;	// Number of cells determines range on galactic map

};

#endif
