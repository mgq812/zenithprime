#pragma once
#define NOMINMAX
#include <windows.h>


class Keyboard
{
public:
	Keyboard(void);
	~Keyboard(void);

	static Keyboard* getCurrentKeyboard();
	static void setCurrentKeyboard(Keyboard* selectKeyboard);
	void WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	void notify();

	bool Keys[256];
private:

	//static void* currentKeyboard;


	//static int hi[10];
};
