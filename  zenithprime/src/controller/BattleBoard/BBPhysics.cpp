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
}

BBPhysics::~BBPhysics(){
	pPhysicsSDK->release();
}
