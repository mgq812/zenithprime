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
	for(unsigned int i = 0 ; i < matrix.size(); i++)
		temp = matrix[i] * temp;

	return Vector3(temp.Get(0,0), temp.Get(1,0), temp.Get(2,0));
}

double Vector3::getMagnitude()
{
        double magnitude = sqrt(x*x+y*y+z*z);
        return magnitude;
}

Vector3 Vector3::normalize()
{
        double length = this->getMagnitude();
        Vector3 temp;

        temp.x = this->x/length;
        temp.y = (this->y/length);
        temp.y = (this->z/length);

        return temp;
} 


Vector3 Vector3::Cross(const Vector3& first, const Vector3& second){
	Vector3 ret;
	ret.x = first.y*second.z - first.z*second.y;
	ret.y = first.z*second.x - first.x*second.z;
	ret.z = first.x*second.y - first.y*second.x;
	return ret;
}


Vector3 Vector3::operator-(const Vector3& other){
	Vector3 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;
	return ret;
}
Vector3 Vector3::operator+(const Vector3& other){
	Vector3 ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	ret.z = z + other.z;
	return ret;
}

Vector3& Vector3::operator=(const Vector3& other){
	if(this!=&other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	return *this;
}

Vector3 Vector3::Multiply(const Vector3& vec, float mul){
	Vector3 ret;
	ret.x =vec.x*mul;
	ret.y =vec.y*mul;
	ret.z =vec.z*mul;
	return ret;
}