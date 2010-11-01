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


using namespace std;

class Enums
{

public:

//! Enumeration of Engines

	/* comments by J. Taylor Grimes */
	/* usually enum variables are in all caps.  That would be nice here! */
enum Type {FISSION_TYPE, pulse, FUSION_TYPE, /* sorry alan no - is allowed anti-matter that means anti minus matter */ anti_matter, phase};

enum Cell {standard, hydrogen, deuterium, anti_hydrogen, mini_black_hole};

	/* cannont enum one var twice with the same name */
enum Beam {laser, pulsed_laser, FUSION_BEAM, ion_cannon};

enum Missile {nuclear, mercolite, pulson, zeon};

enum Bomb {FISSION_BOMB, fusion_BOMB, anti_matter_BOMB, bioPulse, toxic};

enum Special{};


};

# endif

