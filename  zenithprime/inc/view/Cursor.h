#pragma once

#define NOMINMAX
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "Mouse.h"

class DrawCursor
{
public:
	virtual void Draw(int X, int Y) = 0;
};

class Cursor
{
public:
	static void Draw();
	static DrawCursor* GetCurrentCursor();
	static void SetCurrentCursor(DrawCursor* cursor);
private:
	Cursor();
	DrawCursor* currentCursor;
};

class NullCursor : public DrawCursor
{
public:
	virtual void Draw(int X, int Y);
};