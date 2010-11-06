
#pragma once
#include <string>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "OBJModel.h"

class OBJloader
{
public:
	OBJloader(void);
	~OBJloader(void);
	static OBJModel* loadModelFromFile(std::string fileName);
	static OBJModel* loadModel(std::string objData);
	static void PrintModel(OBJModel& model);
	static GLuint CacheOBJModel(OBJModel& model);
};
