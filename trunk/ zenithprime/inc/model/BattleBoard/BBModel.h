#ifndef BBMODEL_H
#define BBMODEL_H
#include "NxPhysics.h"
#include "ZList.h"
#include <vector>
#include "BBPlayerModel.h"
#include "DrawableModel.h"
#include "BBShipController.h"

class BBPlayerModel;
class BBShipModel;
class BBShipController;

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

	void Update();

	void getAllShips(std::vector<BBShipModel*>& list);
	void getAllGhostShips(std::vector<BBShipModel*>& list);
	
	void getSelectedShips(std::vector<BBShipModel*>& list);
	void addSelectedShip(BBShipModel* ship);
	bool isSelectedShip();
	void removeSelectedShip(BBShipModel* ship);
	void clearSelectedShips();

	void getHighlightedShips(std::vector<BBShipModel*>& list);
	void addHighlightedShip(BBShipModel* ship);
	void removeHighlightedShip(BBShipModel* ship);
	void clearHighlightedShips();

	void setBackground(DrawableModel* background);
	DrawableModel* getBackground();

	BBShipController* getShipController();
	NxScene* getPScene();

	NxRaycastHit CastRay(float x, float y, float z, float dx, float dy, float dz);
	bool animate;
	float cursX, cursY, cursZ;

private:
	float width;
	float height;
	//Image Background;
	ZList<BBPlayerModel*> players;
	std::vector<BBShipModel*> selectedShips;
	std::vector<BBShipModel*> highlightShips;

	BBPlayerModel* curPlayer;
	DrawableModel* background;

	NxPhysicsSDK* pPhysicsSDK;
	NxScene* pScene;
	NxActor* boardActor;
	NxActor* boundsActor;

	NxBodyDesc hard;

	BBShipController* shipController;
	void setupPhysics();
	void setupNeutralPlayer();
};

#endif