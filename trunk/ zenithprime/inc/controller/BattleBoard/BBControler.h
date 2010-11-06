#ifndef BBCONTROLER_H
#define BBCONTROLER_H

#include "BBModel.h"
#include "BBState.h"

class BBControler
{
public:
	BBControler(BBModel* battleBoard1);
	void LeftMouseClick(int x, int y);
	void RightMouseClick(int x, int y);
	void MouseHover(int x, int y);
	void LeftMouseDrag(int xStart, int yStart, int xEnd, int yEnd);

private:
	BBShipModel* curPlayerShipAt(int x, int y);
	BBShipModel* otherPlayerShipAt(int x, int y, BBPlayerModel* &foundPlayer);

	BBModel* battleBoard;
	BBPlayerModel* curPlayer;
	BBState* state;
};

#endif