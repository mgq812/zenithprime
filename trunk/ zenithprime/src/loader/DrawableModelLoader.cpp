
#include "DrawableModelLoader.h"

using namespace std;

DrawableModel* DrawableModelLoader::LoadOBJModel(std::string filename)
{
	return LoadOBJModel(OBJloader::loadModelFromFile(filename));
}

DrawableModel* DrawableModelLoader::LoadOBJModel(OBJModel* model){
	if(model==NULL) return NULL;

	int id = OBJloader::CacheOBJModel(*model);

	return new DrawableModel(id);
}