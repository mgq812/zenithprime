#pragma once

#define NOMINMAX
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

class Texture
{
public:
	static bool LoadBitmap(LPTSTR szFileName, GLuint &texid);
};
