#pragma once
#include <windows.h>
#include <vector>

#define MOUSE_RBUTTON 1
#define MOUSE_MBUTTON 2
#define MOUSE_LBUTTON 4

class MouseListener;

class Mouse
{
public:
	Mouse(void);
	~Mouse(void);

	int buttonState;
	int X;
	int Y;
	int maxX;
	int maxY;

	static void setCurrentMouse(Mouse* mouse);
	static Mouse* getCurrentMouse();
	void WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	void addMouseListener(MouseListener* mouseListener);
	void removeMouseListener(MouseListener* mouseListener);

private:
	void mouseMoved(int targetX, int targetY);
	void mouseDragged(int targetX, int targetY, int buttons);
	void mousePressed(int buttons);
	void mouseReleased(int buttons);
	void mouseClicked(int buttons);
	void mouseDoubleClicked(int buttons);
	void mouseWheel(int delta);

	std::vector<MouseListener*> mouseListeners;

};

class MouseListener{
public:
	virtual void mouseMoved(int targetX, int targetY)=0;
	virtual void mouseDragged(int targetX, int targetY, int buttons)=0;
	virtual void mousePressed(int targetX, int targetY, int buttons)=0;
	virtual void mouseReleased(int targetX, int targetY, int buttons)=0;
	virtual void mouseClicked(int targetX, int targetY, int buttons)=0;
	virtual void mouseDoubleClicked(int targetX, int targetY, int buttons)=0;
	virtual void mouseWheel(int targetX, int targetY, int delta)=0;
};
