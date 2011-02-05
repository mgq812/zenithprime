#include "BattleBoardFactory.h"
#include "DrawableModelLoader.h"
#include "BBControllerInterface.h"
#include "BBControler.h"
#include "TextureLoader.h"

using namespace std;

static FactoryVisitor* visitor = new FactoryVisitor();
void BattleBoardFactory::SetFactory(FactoryVisitor* v){
	visitor = v;
}

BattleBoardView* BattleBoardFactory::CreateBoard(float width, float height)
{
	
	BBModel* model = new BBModel(width, height);
	visitor->AddBackground(model);
	visitor->AddLights(model);

	ZList<BBPlayerModel*> players = model->getPlayers();
	for (int i = 0; i < players.getSize(); i++)
	{
		visitor->AddShips(players.getHead()->getData(), model);
	}

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	view->setGridDivision(50,50);

	BBControllerInterface* BBInter = new BBControllerInterface(model, new BBControler(model));

	controller->setFacade(BBInter);
	return view;
}