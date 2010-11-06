#include "BattleBoardGUI.h"
#include <Math.h>

using namespace std;

float distance(float x1, float y1, float z1, float x2, float y2, float z2){
	float dx = x2- x1;
	float dy = y2-y1;
	float dz = z2-z1;

	float dist = sqrt(dx*dx+dy*dy+dz*dz);
	return dist;
}

float toRadians(float angle){
	return angle * (float)3.14159265358/180;
}

BattleBoardController::BattleBoardController(BattleBoardModel* model){
	this->model = model;
	X = model->width/2;
	Y = 0;
	Z = model->hieght/2;
  
	rotateX = 45;
	rotateY = 0;

	srcX = X;
	srcY = Y+50;
	srcZ = Z-50;

	float dumb = distance(srcX, srcY, srcZ, X, Y, Z);
	zoom = dumb;

	upX = 0;
	upY = 1;
	upZ = 0;

	//updateCamera();
  
	MIN_ZOOM = 20;
	MAX_ZOOM = 500;
  Mouse::getCurrentMouse()->addMouseListener(this);
  mouse_flag = true;
}

void BattleBoardController::setMouseEnabled(bool enabled){
	mouse_flag = enabled;
}
bool BattleBoardController::isMouseEnabled(){
	return mouse_flag;
}

void BattleBoardController::mouseMoved(int targetX, int targetY){
	if(!mouse_flag)return;
}


int oldX =-1;
int oldY =-1;
void BattleBoardController::mouseDragged(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;

	if(buttons == MOUSE_MBUTTON){
	


		if(oldX>0){
				

			int d_X = targetX-oldX;
			int d_Y = targetY-oldY;

			this->moveCamera((float)-d_X, (float)-d_Y, 0);


		}
		oldX = targetX;
		oldY = targetY;
	}
	if(buttons== MOUSE_RBUTTON){
		if(oldX>0){
				

			int d_X = targetX-oldX;
			int d_Y = targetY-oldY;

			this->rotateCamera((float)d_Y, (float)-d_X);


		}
		oldX = targetX;
		oldY = targetY;
	}
}
void BattleBoardController::mousePressed(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
}
void BattleBoardController::mouseReleased(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
	if((buttons & (MOUSE_RBUTTON | MOUSE_MBUTTON)) ==0)
	{
		oldX = -1;
		oldY = -1;
	}
}
void BattleBoardController::mouseClicked(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
}
void BattleBoardController::mouseDoubleClicked(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
}
void BattleBoardController::mouseWheel(int targetX, int targetY, int delta){
	if(!mouse_flag)return;
	zoomCamera(-delta*.1);
}

void BattleBoardController::setCamera(float sourceX, float sourceY, float sourceZ,float targetX, float targetY, float targetZ, float up_x , float up_y, float up_z){
	setCameraTarget(targetX, targetY, targetZ);
	setCameraSource(sourceX, sourceY, sourceZ);
	setCameraUp(up_x , up_y, up_z);
}
void BattleBoardController::setCameraTarget(float targetX, float targetY, float targetZ){
	X = targetX;
	Y = targetY;
	Z = targetZ;
}
void BattleBoardController::setCameraSource(float sourceX, float sourceY, float sourceZ){
	srcX = sourceX;
	srcY = sourceY;
	srcZ = sourceZ;
}
void BattleBoardController::setCameraUp(float up_x , float up_y, float up_z){
	upX = up_x;
	upY = up_y;
	upZ = up_z;
}

void BattleBoardController::moveCamera(float deltaX, float deltaY, float deltaZ){
	float d_X = -deltaX;
	float d_Y = -deltaY;

	Y+= deltaZ;
	srcY+= deltaZ;

	if(rotateY!=0){
	d_X = deltaX*cos(toRadians(-rotateY)) - deltaY*sin(toRadians(-rotateY));
	d_Y = deltaX*sin(toRadians(-rotateY))+ deltaY*cos(toRadians(-rotateY));
	}
		
		

	d_X*= (zoom+MIN_ZOOM)/MAX_ZOOM;
	d_Y*= (zoom+MIN_ZOOM)/MAX_ZOOM;
	if(X+d_X>model->width || X +d_X<0)
		return;
	X+= d_X;
	if(Z+d_Y>model->hieght || Z+d_Y<0)
		return;


	Z+= d_Y;

	srcX+= d_X;
	srcZ+= d_Y;
}
void BattleBoardController::zoomCamera(float zoom){
	float oldDist = distance(srcX, srcY, srcZ, X, Y, Z);
	float ratio = (this->zoom+zoom)/oldDist;
	if(oldDist<MIN_ZOOM && ratio<1 || (oldDist>MAX_ZOOM && ratio>1))
		return;
	//float total = srcX + srcY +srcZ;
	float dX =srcX -X;
	dX*= ratio;
	srcX = X+ dX;

	float dY = srcY-Y;
	dY*= ratio;
	srcY = Y+ dY;

	float dZ =srcZ-Z;
	dZ*= ratio;
	srcZ = Z+ dZ;

	//srcX*= ratio;// * srcX/total;
	//srcY*= ratio;//* srcY/total;
	//srcZ*= ratio;//* srcZ/total;
	this->zoom = distance(srcX, srcY, srcZ, X, Y, Z);
	
}
void BattleBoardController::rotateCamera(float rotateX, float rotateY){

	this->rotateY += rotateY;
	if(this->rotateY>360 || this->rotateY<0){
		if(rotateY<0)
			this->rotateY = 360 + this->rotateY;
		else
			this->rotateY = this->rotateY - 360;
	}

	if(abs(rotateX + this->rotateX)<90)
		this->rotateX += rotateX;


	Vector3 offset = Vector3::Transform(Vector3(0,0,zoom), Matrix::CreateRotationX(-toRadians(this->rotateX)));
	offset = Vector3::Transform(offset,  Matrix::CreateRotationY(toRadians(this->rotateY)));
	srcX = offset.x+X;
	srcY = offset.y+Y;
	srcZ = offset.z+Z;
}

void BattleBoardController::enablePrespective(){
	gluLookAt(srcX, srcY, srcZ, X, Y, Z, upX, upY, upZ);
}

void BattleBoardController::updateCamera(){
	
}
