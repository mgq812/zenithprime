#pragma once
#include <Windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

class OpenGLViewport
{
public:
	//OpenGLViewport(int width, int height, int offsetX =0; int offsetY=0);
	//~OpenGLViewport();

	virtual int Draw();
	virtual int Update();
	virtual int Resize(int width, int height);
	virtual int MoveTo(int offsetX, int offsetY);

protected:
	int Width;
	int Height;
	int offsetX;
	int offsetY;
};