#include "BattleBoardGUI.h"
#include "VectorMath.h"
#include <Math.h>

using namespace std;



BattleBoardController::BattleBoardController(BBModel* model){
	this->model = model;
	X = model->getWidth()/2;
	Y = 0;
	Z = model->getHeight()/2;
  
	rotateX = 45;
	rotateY = 0;

	srcX = X;
	srcY = Y+50;
	srcZ = Z+50;

	float dumb = MathLib::distance(srcX, srcY, srcZ, X, Y, Z);
	zoom = dumb;

	upX = 0;
	upY = 1;
	upZ = 0;

	//updateCamera();
  
	BBInfo.x = -1;

	facade = NULL;

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
	callFacade(targetX, targetY, 0, M_MOVED);
	callPan(targetX, targetY);
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
		callFacade(targetX, targetY, buttons, M_DRAGGED);

}
void BattleBoardController::mousePressed(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
	
	callFacade(targetX, targetY, buttons, M_PRESSED);
}
void BattleBoardController::mouseReleased(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
	if((buttons & (MOUSE_RBUTTON | MOUSE_MBUTTON)) ==0)
	{
		oldX = -1;
		oldY = -1;
	}

	
	callFacade(targetX, targetY, buttons, M_RELEASED);
}
void BattleBoardController::mouseClicked(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;
	
	callFacade(targetX, targetY, buttons, M_CLICKED);
}
void BattleBoardController::mouseDoubleClicked(int targetX, int targetY, int buttons){
	if(!mouse_flag)return;

	callFacade(targetX, targetY, buttons, M_DCLICKED);
}
void BattleBoardController::mouseWheel(int targetX, int targetY, int delta){
	if(!mouse_flag)return;
	zoomCamera((float)-delta*.1);
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

	float d_X = deltaX*cos( MathLib::toRadians(-rotateY)) - deltaY*sin( MathLib::toRadians(-rotateY));
	float d_Y = deltaX*sin( MathLib::toRadians(-rotateY))+ deltaY*cos( MathLib::toRadians(-rotateY));		

	d_X*= (zoom+MIN_ZOOM)/MAX_ZOOM;
	d_Y*= (zoom+MIN_ZOOM)/MAX_ZOOM;
	if(X+d_X>model->getWidth() || X +d_X<0)
		return;
	X+= d_X;
	if(Z+d_Y>model->getHeight() || Z+d_Y<0)
		return;


	Z+= d_Y;

	srcX+= d_X;
	srcZ+= d_Y;
}
void BattleBoardController::zoomCamera(float zoom){
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
	this->zoom =  MathLib::distance(srcX, srcY, srcZ, X, Y, Z);
	
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


	Vector3 offset = Vector3::Transform(Vector3(0,0,zoom), Matrix::CreateRotationX(- MathLib::toRadians(this->rotateX)));
	offset = Vector3::Transform(offset,  Matrix::CreateRotationY( MathLib::toRadians(this->rotateY)));
	srcX = offset.x+X;
	srcY = offset.y+Y;
	srcZ = offset.z+Z;
}

void BattleBoardController::enablePrespective(){
	gluLookAt(srcX, srcY, srcZ, X, Y, Z, upX, upY, upZ);
}

void BattleBoardController::Update(){

	static DWORD oldtime = 0;
	//60 fps updating
	if(oldtime==0)
		oldtime = GetTickCount();
	else{
		DWORD currentTime = GetTickCount();
		if((currentTime - oldtime)/(1000.0/30.0) > 1){ 
			callPan(Mouse::getCurrentMouse()->X, Mouse::getCurrentMouse()->Y);
			oldtime = currentTime;
		}
	}

	if(facade==NULL) return;
	facade->Update();
}

void BattleBoardController::setViewport(int x, int y, int width, int height, float viewAngle)
{
	BBInfo.x = x;
	BBInfo.y = y;
	BBInfo.width = width;
	BBInfo.height = height;
	BBInfo.angle = viewAngle;
}
void BattleBoardController::setFacade(BattleBoardGUIFacade* facade){
	this->facade = facade;
}

void BattleBoardController::callFacade(int targetX, int targetY, int buttons, int protocal){
	if(BBInfo.x<0 || this->facade ==NULL) return;

	float originX = srcX;
	float originY = srcY;
	float originZ = srcZ;

    Vector3 w = Vector3(srcX-X, srcY-Y, srcZ-Z).normalize();
	Vector3 u = (Vector3::Cross(Vector3(upX,upY,upZ), w)).normalize();
	Vector3 v = Vector3::Cross(w, u);

	double angConst = tan(BBInfo.angle/180* 3.141592);

    double dist = 1 / angConst;

    double aspect = (double)BBInfo.width / (double)BBInfo.height;
	double dx = ((targetX / (double)(BBInfo.width / 2) - 1))*aspect;
	double dy = (1.0 - targetY / (double)(BBInfo.height / 2)) ;

	Vector3 delta = Vector3(X,Y,Z) + Vector3::Multiply(u, (float)dx) + Vector3::Multiply(v, (float)dy) + Vector3::Multiply(w, -(float)dist);
    delta = delta.normalize();

	switch(protocal){
		case M_MOVED:
			facade->mouseMoved(originX, originY, originZ, delta.x, delta.y, delta.z);
			break;
		case M_DRAGGED:
			facade->mouseDragged(originX, originY, originZ, delta.x, delta.y, delta.z, buttons);
			break;
		case M_PRESSED:
			facade->mousePressed(originX, originY, originZ, delta.x, delta.y, delta.z, buttons);
			break;
		case M_RELEASED:
			facade->mouseReleased(originX, originY, originZ, delta.x, delta.y, delta.z, buttons);
			break;
		case M_CLICKED:
			facade->mouseClicked(originX, originY, originZ, delta.x, delta.y, delta.z, buttons);
			break;
		case M_DCLICKED:
			facade->mouseDoubleClicked(originX, originY, originZ, delta.x, delta.y, delta.z, buttons);
			break;
	}

  
}

void BattleBoardController::callPan(int targetX, int targetY){
	if(BBInfo.x<0) return;

	static int border = 37;
	float d_X = 0;
	float d_Y =0;

	float c =0;
	if(targetX<border){
		c = (border - targetX);
		d_X -= c*c*.01;
	}
	else if (targetX>BBInfo.width -border){
		c = (targetX - BBInfo.width + border);
		d_X +=c*c*.01;
	}

	if(targetY<border)
	{
		c = (border-targetY);
		d_Y-=c*c*.01;
	}
	else if(targetY>BBInfo.height -border){
		c = (targetY - BBInfo.height + border);
		d_Y+= c*c*.01;
	}
	this->moveCamera(d_X, d_Y, 0);

}