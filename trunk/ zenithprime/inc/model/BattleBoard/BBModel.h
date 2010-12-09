#ifndef BBMODEL_H
#define BBMODEL_H
#include "NxPhysics.h"
#include "ZList.h"
#include <vector>
#include "BBPlayerModel.h"
#include "DrawableModel.h"

class BBPlayerModel;
class BBShipModel;

class BBModel
{
public:
	// Constructors
	BBModel(float width1, float height1);
	~BBModel();

	// Getters and setters
	float getWidth();
	float getHeight();
	void setWidth(float width1);
	void setHeight(float height1);

	// other functions
	ZList<BBPlayerModel*> getPlayers();
	void addPlayer(BBPlayerModel* player);
	void removePlayer(BBPlayerModel* player);

	void getAllShips(std::vector<BBShipModel*>& list);
	void getAllGhostShips(std::vector<BBShipModel*>& list);
	void getSelectedShips(std::vector<BBShipModel*>& list);
	void setBackground(DrawableModel* background);
	DrawableModel* getBackground();

	NxScene* getPScene();

	NxRaycastHit CastRay(float x, float y, float z, float dx, float dy, float dz);
	bool animate;
	float cursorX;
	float cursorY;


	float cursX, cursY, cursZ;
private:
	float width;
	float height;
	//Image Background;
	ZList<BBPlayerModel*> players;
	BBPlayerModel* curPlayer;
	DrawableModel* background;

	NxPhysicsSDK* pPhysicsSDK;
	NxScene* pScene;
	NxActor* boardActor;

	void setupPhysics();
	void setupNeutralPlayer();
};

#endif