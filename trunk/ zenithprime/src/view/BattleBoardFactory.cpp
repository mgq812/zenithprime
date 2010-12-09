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

BattleBoardView* BattleBoardFactory::CreateBoard(float width, float height){
	
	BBModel* model = new BBModel(width, height);
	visitor->AddBackground(model);
	visitor->AddLights(model);
	visitor->AddShips(model->getPlayers().getHead()->getData(), model);

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	view->setGridDivision(50,50);

	BBControllerInterface* BBInter = new BBControllerInterface(model, new BBControler(model));

	controller->setFacade(BBInter);
	return view;
}