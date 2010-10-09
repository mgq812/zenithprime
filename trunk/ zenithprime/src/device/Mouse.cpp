#include "Mouse.h"

Mouse::Mouse(void)
{
	buttonState = 0;
}

Mouse::~Mouse(void)
{
}

void Mouse::addMouseListener(MouseListener* mouseListener){
	mouseListeners.push_back(mouseListener);
}
void Mouse::removeMouseListener(MouseListener* mouseListener){
	std::vector<MouseListener*> changestack;

	for(int i = 0 ; i < mouseListeners.size(); i++){
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
	for(int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseMoved(targetX, targetY);

	X = targetX;
	Y = targetY;

	if(buttonState>0)
		mouseDragged(targetX,targetY, buttonState);
}
void Mouse::mouseDragged(int targetX, int targetY, int buttons){
	for(int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseDragged(targetX, targetY,buttons);
}
void Mouse::mousePressed(int buttons){
	for(int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mousePressed(X, Y,buttons);
}
void Mouse::mouseReleased(int buttons){
	for(int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseReleased(X, Y,buttons);
}
void Mouse::mouseClicked(int buttons){
	for(int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseClicked(X, Y,buttons);
}
void Mouse::mouseDoubleClicked(int buttons){
	for(int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseDoubleClicked(X, Y,buttons);
}
void Mouse::mouseWheel(int delta){
	for(int i = 0 ; i < mouseListeners.size(); i++)
		mouseListeners[i]->mouseWheel(X, Y,delta);
}

void Mouse::WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	int deltaX =0;
	int deltaY =0;

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
			mouseMoved(HIWORD(lParam), LOWORD(lParam));
			break;
		case WM_MOUSEWHEEL:
			mouseWheel(GET_WHEEL_DELTA_WPARAM(wParam));
			break;
	}

	
}
