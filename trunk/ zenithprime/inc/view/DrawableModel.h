#pragma once
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <hash_map>

class DrawableModel{
public:
	DrawableModel(int cacheModel);
	~DrawableModel();

	int cacheModel;
	int cacheTexture;
	//hash_map<const char*, int> textures;
};