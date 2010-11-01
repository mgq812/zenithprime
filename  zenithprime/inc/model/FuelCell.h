//------------------------------------------------------
//
//	file: FuelCell.h	Author: Alan Branch
//				Started: 11 Oct 2010
//
//	Header file for engine fuel cells
//
//    		For use with ProjectZenithPrime
//
//	If an engine has no fuel cells, the ship does not have 
//		interstellar capabilities
//
//------------------------------------------------------

#ifndef FUELCELL_H
#define FUELCELL_H

#include "Enums.h"
#include <string>

using namespace std;

class FuelCell
{

public:

	/*
	 * Default constructor\par
	 */
	FuelCell();

	/*
	 * Constructor
	 */
	FuelCell(Enums::Cell cell);

	/*
	 * Sets Engine parameters based on engine type
	 */
	void initEngine(Enums::Cell cell);

	/*
	 * Copy constructor
	 */
	FuelCell (const FuelCell &other);

	/*
	 * Destructor
	 */
	~FuelCell();

	/*
	 * Assignment operator
	 */
	FuelCell& operator = (const FuelCell &other);


/*******************************************
		Range
********************************************/

	/*
	 * Sets the range
	 *
	 * Parameters:
	 * float parsecs
	 *
	 * Returns:
	 * void
	 */
	void setRange (float distance);

	/*
	 * Gets the range
	 *  
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * float - range in parsecs
	 */
	float getRange();

	
/*******************************************
		Type
********************************************/

	/*
	 * Sets the fuel cell type
	 * Parameters:
	 * Enums Cell: cell
	 *
	 * Returns:
	 * void
	 */
	void setCellType (Enums::Cell cell);

	/*
	 * Gets the fuel cell type
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * Enums Cell: cell
	 */
	Enums getCellType();


	/*
	 * Sets the cell's mass
	 * Parameters:
	 * float mass;
	 *
	 * Returns:
	 * void
	 */
	void setCellMass(float mass);

	/*
	 * Gets the cell's mass
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * float - mass
	 */
	float getCellMass();


	/*
	 * Returns cell attributes as a string
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * string - cell type converted to string
	 */
	string typeToString();


	/*
	 * Sets the cell specifications/description
	 * Parameters:
	 * string - the cell specs
	 *
	 * Returns:
	 * void
	 */
	void setCellSpecs(string specs);


	/*
	 * Gets the cell specifications/description
	 * Parameters:
	 * none
	 *
	 * Returns:
	 * string: the cell type specifications/description
	 */
	string getCellSpecs();


	/* This was edited by me Taylor */
	/* missing initCell ? */
	void initCell(Enums::Cell cell);


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
	 * Setting and getting of ranges
	 *
	 */
	bool Test(ostream & os);


private:
	Enums cell;		// type of cell
	float mass;		// cell mass
	float parsecs;		// range


};

#endif
