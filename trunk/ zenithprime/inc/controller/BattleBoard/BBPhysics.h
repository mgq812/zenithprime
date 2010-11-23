#pragma once
#include "NxPhysics.h"

class BBPhysics
{
public:
	NxPhysicsSDK* pPhysicsSDK;
	NxScene* pScene;
	NxActor* pActor;

	BBPhysics();
	~BBPhysics();

	bool isBoard();
	bool isShip();
	
	void Update();
	NxRaycastHit CastRay(float x, float y, float z, float dx, float dy, float dz);
};