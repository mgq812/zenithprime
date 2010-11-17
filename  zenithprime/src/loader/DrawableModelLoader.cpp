
#include "DrawableModelLoader.h"

using namespace std;

DrawableModel* DrawableModelLoader::LoadOBJModel(std::string filename){
	OBJModel* temp = OBJloader::loadModelFromFile(filename);
	if(temp==NULL) return NULL;

	int id = OBJloader::CacheOBJModel(*temp);

	delete temp;
	return new DrawableModel(id);
}