#include "BBShipController.h"

void BBShipController::MoveShip(BBShipModel* shipModel,float x, float y){
	
	ShipMove* move = new ShipMove();
	move->prev = NULL;
	move->next = NULL;
	move->step = 0;

	float startx = shipModel->getX();
	float starty = shipModel->getY();

	float deltaX = x - startx;
	float deltaY = y - starty;

	double dist = sqrt(deltaX*deltaX + deltaY*deltaY);
	double angle = atan2(deltaY,deltaX) ;

	double d_angle = angle * 180 / 3.141592;
	if(d_angle<0)
		d_angle = 360 + d_angle;
	
	shipModel->setAngle(d_angle);

	//angle = d_angle * 3.141592 / 180;
	move->shipModel = shipModel;
	shipModel->getAngle();

	float d=0;
	const float minstep = .01;
	const float maxstep = .1;
	float currentstep = .01;

	while(true){
		if(d>dist/2){
			move->path.push_back(NxVec3(cos(angle)*dist/2+startx, shipModel->getAngle(), sin(angle)*dist/2+starty));
			break;
		}

		move->path.push_back(NxVec3(cos(angle)*d+startx, shipModel->getAngle(), sin(angle)*d+starty));
		
		d += currentstep;
		currentstep *= 1.1;
		if(currentstep>maxstep)
			currentstep == maxstep;
	}

	d = dist/2;
	while(true){
		move->path.push_back(NxVec3(cos(angle)*d+startx, shipModel->getAngle(), sin(angle)*d+starty));
		d += currentstep/2;
		if(d>dist){
			move->path.push_back(NxVec3(x, shipModel->getAngle(), y));
			break;
		}
	}

	if(head!=NULL)	{
		ShipMove* currentMove= head;
		
		while(currentMove!=NULL)
		{
			if(currentMove->shipModel == shipModel)
			{
				ShipMove* nextmove = currentMove->next;

				if(currentMove->prev!=NULL)
					currentMove->prev->next = move;

				if(currentMove->next!=NULL)
					currentMove->next->prev = move;

				if(currentMove == head)
					head = move;

				delete(currentMove);
				
				return;
			}
			currentMove = currentMove->next;
		}

		head->prev = move;
		move->next = head;
		head = move;
	}
	else
	{
		head= move;
	}
}

void BBShipController::TryMoveShip(BBShipModel* shipModel,float x, float y){

}

BBShipController::BBShipController(BBModel *model1){
	model = model1;
	head = NULL;
}

void BBShipController::Update(){
	ShipMove* currentMove= head;
	while(currentMove!=NULL)
	{
		if(currentMove->step >= currentMove->path.size())
		{
			ShipMove* nextmove = currentMove->next;
			currentMove->shipModel->shipActor->putToSleep();

			if(currentMove->prev!=NULL)
				currentMove->prev->next = currentMove->next;

			if(currentMove->next!=NULL)
				currentMove->next->prev = currentMove->prev;

			if(currentMove == head)
				head = currentMove->next;

			delete(currentMove);
			currentMove = nextmove;
			continue;
		}
		currentMove->shipModel->setX( currentMove->path[currentMove->step].x);
		currentMove->shipModel->setY( currentMove->path[currentMove->step].z);
		//currentMove->shipModel->setAngle(currentMove->path[currentMove->step].y);
		currentMove->step++;// = shipMove.step +1;
		currentMove = currentMove->next;
	}
	/*if(travelPaths.size()>0)
		for(vector<ShipMove>::iterator it = travelPaths.begin(); it!=travelPaths.end(); ++it){
			if(it->step < it->path.size()){
				it->shipModel->setX( it->path[it->step].x);
				it->shipModel->setY( it->path[it->step].z);
				it->step++;// = shipMove.step +1;
			}

			if(it->step >= it->path.size()){
				it->shipModel = NULL;
				//travelPaths.erase(it, it+1);
			}
		}*/
}