#pragma once
#include "NxPhysics.h"

class BBPhysics
{
public:
	NxPhysicsSDK* pPhysicsSDK;
	NxScene* pScene;

	BBPhysics();
	~BBPhysics();
	
};