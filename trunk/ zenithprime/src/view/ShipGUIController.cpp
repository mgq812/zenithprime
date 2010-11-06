#include "ShipGUI.h"
#include "VectorMath.h"
#include <Math.h>

using namespace std;

ShipGUIController::ShipGUIController(DrawableModel* model){
	this->model = model;
	X = 0;
	Y = 0;
	Z = 0;
  
	rotateX = 45;
	rotateY = 0;

	srcX = X;
	srcY = Y+3;
	srcZ = Z+3;

	float dumb = MathLib::distance(srcX, srcY, srcZ, X, Y, Z);
	zoom = dumb;

	upX = 0;
	upY = 1;
	upZ = 0;

	//updateCamera();
  
	MIN_ZOOM = 2;
	MAX_ZOOM = 10;
  Mouse::getCurrentMouse()->addMouseListener(this);
  mouse_flag = true;
}

void ShipGUIController::setMouseEnabled(bool enabled){
	mouse_flag = enabled;
}
bool ShipGUIController::isMouseEnabled(){
	return mouse_flag;
}

void ShipGUIController::mouseMoved(int targetX, int targetY){
	if(!mouse_flag)return;
}


int old_X =-1;
int old_Y =-1;
void ShipGUIController::mouseDragged(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;

	if(buttons== MOUSE_RBUTTON){
		if(old_X>0){
				

			int d_X = targetX-old_X;
			int d_Y = targetY-old_Y;

			this->rotateCamera((float)d_Y, (float)-d_X);
		}
		old_X = targetX;
		old_Y = targetY;
	}
}
void ShipGUIController::mousePressed(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
}
void ShipGUIController::mouseReleased(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
	if((buttons & (MOUSE_RBUTTON | MOUSE_MBUTTON)) ==0)
	{
		old_X = -1;
		old_Y = -1;
	}
}
void ShipGUIController::mouseClicked(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
}
void ShipGUIController::mouseDoubleClicked(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
}
void ShipGUIController::mouseWheel(int targetX, int targetY, int delta){
	if(!mouse_flag)return;
	zoomCamera(-delta*.1);
}

void ShipGUIController::setCamera(float sourceX, float sourceY, float sourceZ,float targetX, float targetY, float targetZ, float up_x , float up_y, float up_z){
	setCameraTarget(targetX, targetY, targetZ);
	setCameraSource(sourceX, sourceY, sourceZ);
	setCameraUp(up_x , up_y, up_z);
}
void ShipGUIController::setCameraTarget(float targetX, float targetY, float targetZ){
	X = targetX;
	Y = targetY;
	Z = targetZ;
}
void ShipGUIController::setCameraSource(float sourceX, float sourceY, float sourceZ){
	srcX = sourceX;
	srcY = sourceY;
	srcZ = sourceZ;
}
void ShipGUIController::setCameraUp(float up_x , float up_y, float up_z){
	upX = up_x;
	upY = up_y;
	upZ = up_z;
}

void ShipGUIController::zoomCamera(float zoom){
	float oldDist = MathLib::distance(srcX, srcY, srcZ, X, Y, Z);
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
	this->zoom = MathLib::distance(srcX, srcY, srcZ, X, Y, Z);
	
}
void ShipGUIController::rotateCamera(float rotateX, float rotateY){

	this->rotateY += rotateY;
	if(this->rotateY>360 || this->rotateY<0){
		if(rotateY<0)
			this->rotateY = 360 + this->rotateY;
		else
			this->rotateY = this->rotateY - 360;
	}

	if(abs(rotateX + this->rotateX)<90)
		this->rotateX += rotateX;


	Vector3 offset = Vector3::Transform(Vector3(0,0,zoom), Matrix::CreateRotationX(-MathLib::toRadians(this->rotateX)));
	offset = Vector3::Transform(offset,  Matrix::CreateRotationY(MathLib::toRadians(this->rotateY)));
	srcX = offset.x+X;
	srcY = offset.y+Y;
	srcZ = offset.z+Z;
}

void ShipGUIController::enablePrespective(){
	gluLookAt(srcX, srcY, srcZ, X, Y, Z, upX, upY, upZ);
}

void ShipGUIController::updateCamera(){
	
}
