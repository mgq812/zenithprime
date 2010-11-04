//------------------------------------------------------
//	file: Engine.h		Author: Alan Branch
//				Started: 9 Oct 2010
//
//	Enums for Engines et al
//
//    	For use with ProjectZenithPrime
//
//------------------------------------------------------

#ifndef ENUMS_H
#define ENUMS_H


//using namespace std;

class Enums
{

public:

//! Enumeration of Engines

	/* comments by J. Taylor Grimes */
	/* usually enum variables are in all caps.  That would be nice here! */
enum Type {FISSION_TYPE, PULSE, FUSION_TYPE, /* sorry alan no - is allowed anti-matter that means anti minus matter */ ANTI_MATTER, PHASE};

enum Cell {STANDARD, HYDROGEN, DEUTERIUM, ANTI_HYDROGEN, MINI_BLACK_HOLE};

	/* cannont enum one var twice with the same name */
enum Beam {LASER, PULSED_LASER, MASS_DRIVER, FUSION_BEAM, ION_CANNON, MAULER};

enum Missile {NUCLEAR, MERCOLITE, PULSON, ZEON};

enum Bomb {FISSION_BOMB, FUSION_BOMB, ANTI_MATTER_BOMB, BIOPULSE, TOXIC};

enum Special{};


};

# endif

