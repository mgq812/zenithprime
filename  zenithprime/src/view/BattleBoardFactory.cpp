#include "BattleBoardFactory.h"

using namespace std;

BattleBoardView* BattleBoardFactory::CreateBoard(float width, float height){

	BattleBoardModel* model = new BattleBoardModel();
	model->hieght = height;
	model->width = width;

	BattleBoardController* controller = new BattleBoardController(model);

	BattleBoardView* view = new BattleBoardView(model, controller);
	return view;
}