#include "Keyboard.h"

Keyboard::Keyboard(void)
{
	for(int i = 0 ; i < 256; i++)
		Keys[i] = FALSE;
}

Keyboard::~Keyboard(void)
{
}
static Keyboard* currentKeyboard = NULL;

Keyboard*  Keyboard::getCurrentKeyboard(){
	return currentKeyboard; 
}
void Keyboard::setCurrentKeyboard(Keyboard* selectKeyboard){
	currentKeyboard = selectKeyboard;
}

void Keyboard::WindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch(message){
		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			Keyboard::getCurrentKeyboard()->Keys[wParam] = TRUE;					// If So, Mark It As TRUE
			break;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			Keyboard::getCurrentKeyboard()->Keys[wParam] = FALSE;					// If So, Mark It As FALSE
			break;								// Jump Back
		}
	}
}