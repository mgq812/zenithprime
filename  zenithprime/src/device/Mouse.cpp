#include "Mouse.h"

int clicks;
Mouse::Mouse(void)
{
	buttonState = 0;
	clicks = 0;
	maxX = -1;
	maxY = -1;
}

Mouse::~Mouse(void)
{
}

void Mouse::addMouseListener(MouseListener* mouseListener){
	mouseListeners.push_back(mouseListener);
}
void Mouse::removeMouseListener(MouseListener* mouseListener){
	std::vector<MouseListener*> changestack;

	for(unsigned  int i = 0 ; i < mouseListeners.size(); i++){
		if(mouseListeners[i] == mouseListener)
		{
			continue;
		}
		changestack.push_back(mouseListeners[i]);
	}
	mouseListeners.clear();
	while(!changestack.empty()){
		mouseListeners.push_back(changestack.back());
		changestack.pop_back();
	}
}


static Mouse* currentMouse = NULL;
void Mouse::setCurrentMouse(Mouse* mouse){
	currentMouse = mouse;
}

Mouse* Mouse::getCurrentMouse(){
	return currentMouse;
}

void Mouse::mouseMoved(int targetX, int targetY){
	for(unsigned  int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseMoved(targetX, targetY);

	X = targetX;
	Y = targetY;

	clicks = 0;
	if(buttonState>0)
		mouseDragged(targetX,targetY, buttonState);
}
void Mouse::mouseDragged(int targetX, int targetY, int buttons){
	for(unsigned int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseDragged(targetX, targetY,buttons);
}
void Mouse::mousePressed(int buttons){
	buttonState = buttonState | buttons;

	clicks++;
	for(unsigned int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mousePressed(X, Y,buttons);
}
void Mouse::mouseReleased(int buttons){
	buttonState = buttonState & !buttons;

	for(unsigned int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseReleased(X, Y,buttonState);
	if(clicks>0)
		mouseClicked(buttons);
}
void Mouse::mouseClicked(int buttons){
	for(unsigned int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseClicked(X, Y,buttons);
	if(clicks>1)
		mouseDoubleClicked(buttons);
	clicks++;
}
void Mouse::mouseDoubleClicked(int buttons){
	for(unsigned int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseDoubleClicked(X, Y,buttons);
	clicks = 0;
}
void Mouse::mouseWheel(int delta){
	for(unsigned int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseWheel(X, Y,delta);
}

void Mouse::WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

	switch(message){
		case WM_RBUTTONDOWN:
			mousePressed(MOUSE_RBUTTON);
			break;
		case WM_RBUTTONUP:
			mouseReleased(MOUSE_RBUTTON);
			break;	
		case WM_LBUTTONDOWN:
			mousePressed(MOUSE_LBUTTON);
			break;
		case WM_LBUTTONUP:
			mouseReleased(MOUSE_LBUTTON);
			break;
		case WM_MBUTTONDOWN:
			mousePressed(MOUSE_MBUTTON);
			break;
		case WM_MBUTTONUP:
			mouseReleased(MOUSE_MBUTTON);
			break;
		case WM_MOUSEMOVE:	
			mouseMoved(LOWORD(lParam), HIWORD(lParam));
			break;
		case WM_MOUSEWHEEL:
			mouseWheel(GET_WHEEL_DELTA_WPARAM(wParam));
			break;
	}

	
}
