#include "BBPhysics.h"

BBPhysics::BBPhysics()
{
		pPhysicsSDK = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION);

		if ( pPhysicsSDK != NULL ){
		 pPhysicsSDK->getFoundationSDK().getRemoteDebugger()->connect ("localhost", 5425);
		}
		else
			return;

		NxSceneDesc sceneDesc;
		sceneDesc.gravity.set ( 0, 0, 0 );

		pScene = pPhysicsSDK->createScene(sceneDesc);

		NxPlaneShapeDesc planeDesc;
		// plane equation : ax + by + cz + d = 0
		planeDesc.normal = NxVec3 ( 0, 1, 0 );
		planeDesc.d = 0.0f;
		// actor descriptor with collection of shapes
		NxActorDesc actorDesc;
		actorDesc.shapes.pushBack( &planeDesc );
		// NxScene creates actor and returns a pointer.
		pActor = pScene->createActor( actorDesc );
		//pActor->userData = NULL;
}

BBPhysics::~BBPhysics(){
	pPhysicsSDK->release();
}


NxRaycastHit BBPhysics::CastRay(float x, float y, float z, float dx, float dy, float dz){
	NxRay worldRay; 
	worldRay.orig = NxVec3(x,y,z);
	worldRay.dir = NxVec3(dx,dy,dz);
	worldRay.dir.normalize(); //Important!!

	NxRaycastHit hit;
	pScene->raycastClosestBounds(worldRay,NX_ALL_SHAPES, hit);
	return hit;
}
