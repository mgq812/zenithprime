//------------------------------------------------------
//
//	file: FuelCell.h	Author: Alan Branch
//				Started: 11 Oct 2010
//
//	CPP file for engine fuel cells
//
//    		For use with ProjectZenithPrime
//
//------------------------------------------------------

#include "FuelCell.h"

/*
 * Default constructor\par
 */
FuelCell::FuelCell()
{
}

/*
 * Constructor
 */
FuelCell::FuelCell(Enums::Cell cell)
{
	initCell(cell);
}

/*
 * Sets Engine parameters based on engine type
 */
void FuelCell::initCell(Enums::Cell cell)
{
	switch (cell)
	{
		case(Enums::STANDARD):
			cell = Enums::STANDARD;
			mass = 2.0;		// cell mass
			parsecs = 10.0;		// range
			break;

		case(Enums::HYDROGEN):
			cell = Enums::HYDROGEN;
			mass = 3.0;		// cell mass
			parsecs = 15.0;		// range
			break;

		case(Enums::DEUTERIUM):
			cell = Enums::DEUTERIUM;
			mass = 5.0;		// cell mass
			parsecs = 30.0;		// range
			break;

		case(Enums::ANTI_HYDROGEN):
			cell = Enums::ANTI_HYDROGEN;
			mass = 9.0;		// cell mass
			parsecs = 60.0;		// range
			break;

		case(Enums::MINI_BLACK_HOLE):
			cell = Enums::MINI_BLACK_HOLE;
			mass = 28.0;		// cell mass
			parsecs = 140.0;		// range
			break;

		default:
			break;
	}
}

/*
 * Copy constructor
 */
FuelCell::FuelCell (const FuelCell &other)
{
	cell = other.cell;
	mass = other.mass;
	parsecs = other.parsecs;
}

/*
 * Destructor
 */
FuelCell::~FuelCell()
{
}

/*
 * Assignment operator
 */
FuelCell& FuelCell::operator = (const FuelCell &other)
{
	if (this != &other)
	{
		cell = other.cell;
		mass = other.mass;
		parsecs = other.parsecs;
	}
	return *this;
}


/*******************************************
		Range
********************************************/


void FuelCell::setRange (float distance)
{
	parsecs = distance;
}


float FuelCell::getRange()
{
	return parsecs;
}

	
/*******************************************
		Type
********************************************/


void FuelCell::setCellType (Enums::Cell cell)
{
	cell = cell;
}

/* spelled Enums::Cel FuellCell supposed to be Enums FuelCell? */
//Enums::Cel FuellCell::getCellType()
//{
//	return cell;
//}
Enums FuelCell::getCellType()
{
	return cell;
}



void FuelCell::setCellMass(float mass)
{
	mass = mass;
}

float FuelCell::getCellMass()
{
	return mass;
}


/*
 * Returns cell attributes as a string
 * Parameters:
 * none
 *
 * Returns:
 * string - cell type converted to string
 */
string FuelCell::typeToString()
{
	string type = "Cell make/model";
	return type;
}


/*
 * Sets the cell specifications/description
 * Parameters:
 * string - the cell specs
 *
 * Returns:
 * void
 */
void FuelCell::setCellSpecs(string specs)
{
}


/*
 * Gets the cell specifications/description
 * Parameters:
 * none
 *
 * Returns:
 * string: the cell type specifications/description
 */
string FuelCell::getCellSpecs()
{
	string base = "Cell specificatiosn";
	return base;
}




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
bool FuelCell::Test(ostream & os)
{
	bool success = true;

	return success;
}
