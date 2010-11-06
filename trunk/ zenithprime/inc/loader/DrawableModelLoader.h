#pragma once
#include "DrawableModel.h"
#include "OBJloader.h"
class DrawableModelLoader
{
public:
	static DrawableModel* LoadOBJModel(std::string filename);
};