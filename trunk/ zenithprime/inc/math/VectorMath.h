#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "int3.h"
#include <cmath>

class MathLib{
public:
static float distance(float x1, float y1, float z1, float x2, float y2, float z2){
	float dx = x2- x1;
	float dy = y2-y1;
	float dz = z2-z1;

	float dist = sqrt(dx*dx+dy*dy+dz*dz);
	return dist;
}

static float toRadians(float angle){
	return angle * (float)3.14159265358/180;
}
};