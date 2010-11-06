
#include "DrawableModelLoader.h"

using namespace std;

DrawableModel* DrawableModelLoader::LoadOBJModel(std::string filename){
	OBJModel* temp = OBJloader::loadModelFromFile(filename);
	int id = OBJloader::CacheOBJModel(*temp);

	delete temp;
	return new DrawableModel(id);
}