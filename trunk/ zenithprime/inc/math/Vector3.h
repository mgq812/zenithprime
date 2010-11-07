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
	static Vector3 Cross(const Vector3& first, const Vector3& second);
	double getMagnitude();
	Vector3 normalize();
	
	static Vector3 Multiply(const Vector3& vec, float mul);

	Vector3& operator=(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator+(const Vector3& other);

};
