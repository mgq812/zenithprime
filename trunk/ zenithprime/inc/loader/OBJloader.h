
#pragma once
#include <string>
#include "OBJModel.h"

class OBJloader
{
public:
	OBJloader(void);
	~OBJloader(void);
	static OBJModel* loadModelFromFile(std::string fileName);
	static OBJModel* loadModel(std::string objData);
	static void PrintModel(OBJModel& model);
};
