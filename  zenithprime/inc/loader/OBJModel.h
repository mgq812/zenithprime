#pragma once
#include "VectorMath.h"
#include "Face.h"
#include <string>
#include <vector>

struct USEMTL{
  int startQuad;
  int endQuad;
  int startTri;
  int endTri;
  std::string var;
};

class OBJModel
{
public:
	OBJModel(void);
	~OBJModel(void);
	std::vector<Vector3> vertexXYZ;
	std::vector<Vector2> textureUV;
	std::vector<Vector3> normal;
	std::vector<Tri> Triangles;
	std::vector<Quad> Quads;
	std::vector<Line> Lines;
	std::vector<PolygonFace> Polygons;
	std::vector<int3> Points;

	std::vector<USEMTL> Materials;
	
	std::string objectName;
	std::string mtllib;
	
};


