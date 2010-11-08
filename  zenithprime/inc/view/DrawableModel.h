#pragma once
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

class DrawableModel{
public:
	DrawableModel(int cacheModel);
	~DrawableModel();

	int cacheModel;
	GLuint cacheTexture;

	static DrawableModel* NULLDrawableModel();
};