#include "BattleBoard.h"

class BattleBoardFactory
{
public:
	static BattleBoardView* CreateBoard(float width, float height);
};