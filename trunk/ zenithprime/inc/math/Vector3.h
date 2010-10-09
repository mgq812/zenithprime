#pragma once
#include <vector>

class Matrix;

class Vector3
{
public:
	Vector3(void);
	Vector3(float X, float Y, float Z);
	~Vector3(void);
	float x, y, z;

	static Vector3 Transform(Vector3 point, Matrix matrix);
	static Vector3 Transform(Vector3 point, std::vector<Matrix> matrix);
	static Vector3 One();
	static Vector3 Zero();
};
