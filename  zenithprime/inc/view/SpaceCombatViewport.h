#pragma once
#include "OpenGLViewport.h"
#include "BattleBoardGUI.h"

class SpaceCombatViewport : OpenGLViewport
{
public:
	SpaceCombatViewport(BattleBoardView* bbView, int offsetX, int offsetY, int width, int height);
	SpaceCombatViewport(BattleBoardView* bbView);
	~SpaceCombatViewport();

	virtual int Draw();
	virtual int Update();
	virtual int Resize(int width, int height);
	virtual int MoveTo(int offsetX, int offsetY);

	
	BattleBoardView* battleBoardView; 

private:
	int Width;
	int Height;
	int offsetX;
	int offsetY;
};