#pragma once
#include "OpenGLViewport.h"
#include "BattleBoard.h"

class SpaceCombatViewport
{
public:
	SpaceCombatViewport(int width, int height, int offsetX =0, int offsetY=0);
	~SpaceCombatViewport();

	virtual int Draw();
	virtual int Update();
	virtual int Resize(int width, int height);
	virtual int MoveTo(int offsetX, int offsetY);

	
	BattleBoardView* battleBoardView; 
	BattleBoardController* battleBoardController;

private:
	int Width;
	int Height;
	int offsetX;
	int offsetY;
};