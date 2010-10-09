#pragma once
#include <vector>
#include "VectorMath.h"
class Matrix
{
public:
	~Matrix(void);
	Matrix(void);

	float Get(int row, int col);
	static void loadMatrix(Matrix* matrix, int width, int height, float values[]);

	Matrix operator*(const Matrix& other) const;
	Matrix& operator*=(const Matrix& other);
	Matrix& operator=(const Matrix& other);

	static Matrix CreateTranslation(Vector3 translation);
	static Matrix CreateScale(Vector3 scaler);
	static Matrix CreateScale(float scaler);
	static Matrix CreateRotationX(float beta);
	static Matrix CreateRotationY(float beta);
	static Matrix CreateRotationZ(float beta);
	static Matrix Identity(); 

private:
	static float multiplyCell(int col, int row, const Matrix& primary, const Matrix& secondary);
	static bool multiplyValid( const Matrix& primary, const Matrix& secondary, int* outRows, int* outColunms);

	int width;
	int hieght;

	std::vector<float> values;

};
