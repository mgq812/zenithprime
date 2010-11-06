#pragma once
#include "DrawableModel.h"
class DrawableModelLoader
{
	static DrawableModel* LoadOBJModel(std::string filename);
};