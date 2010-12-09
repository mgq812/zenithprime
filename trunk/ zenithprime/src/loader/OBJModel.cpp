#include "OBJModel.h"

OBJModel::OBJModel(void)
{
}

OBJModel::~OBJModel(void)
{
}
static OBJModel* nullSingle = NULL;
OBJModel* OBJModel::NullOBJModel(){
	if(nullSingle==NULL){
		nullSingle = new OBJModel();
		nullSingle->largestX = .5;
		nullSingle->largestY = .5;
		nullSingle->largestZ = .5;
		nullSingle->smallestX = -.5;
		nullSingle->smallestY = -.5;
		nullSingle->smallestZ = -.5;
	}

	return nullSingle;
}