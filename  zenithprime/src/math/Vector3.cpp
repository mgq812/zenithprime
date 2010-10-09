#include "Vector3.h"
#include "Matrix.h"

Vector3::Vector3(void)
{
}

Vector3::~Vector3(void)
{
}
Vector3::Vector3(float X, float Y, float Z) :x(X), y(Y), z(Z) {
}
Vector3 Vector3::One(){
	return Vector3(1.0,1.0,1.0);
}
Vector3 Vector3::Zero(){
	return Vector3(0.0,0.0,0.0);
}

Vector3 Vector3::Transform(Vector3 point, Matrix matrix){
	Matrix temp;
	float vals[] = {point.x, point.y, point.z, 1};
	Matrix::loadMatrix(&temp, 1, 4, vals);
	temp = matrix * temp;

	return Vector3(temp.Get(0,0), temp.Get(1,0), temp.Get(2,0));
}
Vector3 Vector3::Transform(Vector3 point, std::vector<Matrix> matrix){
	Matrix temp;
	float vals[] = {point.x, point.y, point.z, 1};
	Matrix::loadMatrix(&temp, 1, 4, vals);
	for(int i = 0 ; i < matrix.size(); i++)
		temp = matrix[i] * temp;

	return Vector3(temp.Get(0,0), temp.Get(1,0), temp.Get(2,0));
}
