
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
	static void PrintModel(Model& model);
	static int readOBJLine(std::string objLine, Model& model);
};
