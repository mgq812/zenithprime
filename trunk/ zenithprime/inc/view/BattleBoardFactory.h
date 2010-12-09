#include "BattleBoardGUI.h"
#include "FactoryVisitor.h"

class BattleBoardFactory
{
public:
	static void SetFactory(FactoryVisitor* visitor);
	static BattleBoardView* CreateBoard(float width, float height);
};