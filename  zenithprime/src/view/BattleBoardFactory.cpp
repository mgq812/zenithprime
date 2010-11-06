#include "BattleBoardFactory.h"

using namespace std;

BattleBoardView* BattleBoardFactory::CreateBoard(float width, float height){

	BBModel* model = new BBModel();
	model->setHeight(height);
	model->setWidth(width);

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	return view;
}