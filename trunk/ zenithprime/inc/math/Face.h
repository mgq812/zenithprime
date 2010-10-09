#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include "VectorMath.h"

class Tri
{
public:
	Tri(void);
	~Tri(void);
	int3 T1;
	int3 T2;
	int3 T3;
};

class Quad : public Tri
{
public:
	int3 T4;
};

class PolygonFace
{
public:
	std::vector<int3> T;
};

class Line
{
public:
	int3 Start;
	int3 End;
};

