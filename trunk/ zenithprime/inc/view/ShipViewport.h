#pragma once
#include "OpenGLViewport.h"
#include "ShipGUI.h"

class ShipViewport : OpenGLViewport
{
public:
	ShipViewport(ShipView* sView, int offsetX, int offsetY, int width, int height);
	ShipViewport(ShipView* sView);
	~ShipViewport();

	virtual int Draw();
	virtual int Update();
	virtual int Resize(int width, int height);
	virtual int MoveTo(int offsetX, int offsetY);

	
	ShipView* shipView; 

private:
	int Width;
	int Height;
	int offsetX;
	int offsetY;
};