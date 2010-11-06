#pragma once
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <hash_map>

class DrawableModel{
	DrawableModel();
	~DrawableModel();

	int cacheModel;
	
	//hash_map<const char*, int> textures;
};