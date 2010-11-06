#include "Matrix.h"

using namespace std;

Matrix::Matrix(void):  width(-1), hieght(-1){

}

Matrix::~Matrix(void){
	hieght = -2;
	width = -2;
}

float Matrix::Get(int row, int col){
	return values[row*width + col];
}
Matrix Matrix::operator *(const Matrix &other) const{
	Matrix returnMatrix;

	int endWidth = 0;
	int endHeight =0;
	if(!multiplyValid(*this, other, &endHeight, &endWidth))
		return returnMatrix;

	returnMatrix.hieght = endHeight;
	returnMatrix.width = endWidth;

	for(int i = 0; i<endHeight; i++)
		for(int j = 0; j<endWidth; j++)
		{
			returnMatrix.values.push_back( multiplyCell(j, i, *this, other));
		}
		
	return returnMatrix;
}


Matrix& Matrix::operator=(const Matrix& other){
	if(this!=&other)
	{
		
		values.clear();
		hieght = other.hieght;
		width = other.width;
		for(unsigned int i = 0 ; i < other.values.size(); i++)
			values.push_back(other.values[i]);

	}

	return *this;
}


Matrix& Matrix::operator*=(const Matrix& other) {

	return *this = other * *this;
}

float Matrix::multiplyCell(int col, int row, const Matrix &primary, const Matrix &secondary){
	
	float retVal = 0;
		for(int j = 0, i = 0; j<secondary.hieght && i < primary.width; i++, j++)
		{
			retVal += primary.values[primary.width*row + i] * secondary.values[secondary.width*j + col];
		}

		return retVal;
}	

bool Matrix::multiplyValid(const Matrix &primary, const Matrix &secondary,  int* outRows, int* outColunms){
	if(primary.width != secondary.hieght) return false;

	*outRows = primary.hieght;
	*outColunms = secondary.width;

	return true;
}

Matrix Matrix::CreateTranslation(Vector3 translation){
	Matrix retMatrix;
	
	float values[] = {1, 0, 0, translation.x,
					  0, 1, 0, translation.y,
					  0, 0, 1, translation.z,
					  0, 0, 0, 1};

	loadMatrix(&retMatrix, 4, 4, values);

	return retMatrix;
}
Matrix Matrix::CreateScale(Vector3 scaler){
	Matrix retMatrix;

	float values[] = {scaler.x, 0, 0, 0,
					  0, scaler.y, 0, 0,
					  0, 0, scaler.z, 0,
					  0, 0, 0, 1};

	loadMatrix(&retMatrix, 4, 4, values);

	return retMatrix;
}

Matrix Matrix::CreateScale(float scaler){
	Matrix retMatrix;

	float values[] = {scaler, 0, 0, 0,
					  0, scaler, 0, 0,
					  0, 0, scaler, 0,
					  0, 0, 0, 1};

	loadMatrix(&retMatrix, 4, 4, values);

	return retMatrix;
}

Matrix Matrix::CreateRotationX(float beta){
	Matrix retMatrix;

	float values[] = {1, 0, 0, 0,
					  0, cos(beta), -sin(beta), 0,
					  0, sin(beta), cos(beta), 0,
					  0, 0, 0, 1};

	loadMatrix(&retMatrix, 4, 4, values);

	return retMatrix;
}
Matrix Matrix::CreateRotationY(float beta){
	Matrix retMatrix;

	float values[] = {cos(beta), 0, sin(beta), 0,
					  0, 1, 0, 0,
					  -sin(beta), 0, cos(beta), 0,
					  0, 0, 0, 1};

	loadMatrix(&retMatrix, 4, 4, values);
	return retMatrix;
}
Matrix Matrix::CreateRotationZ(float beta){
	Matrix retMatrix;

	float values[] = {cos(beta), -sin(beta), 0, 0,
					  sin(beta), cos(beta), 0, 0,
					  0, 0, 1, 0,
					  0, 0, 0, 1};

	loadMatrix(&retMatrix, 4, 4, values);

	return retMatrix;
}
Matrix Matrix::Identity(){
	Matrix retMatrix;

	float values[] = {1, 0, 0, 0,
					  0, 1, 0, 0,
					  0, 0, 1, 0,
					  0, 0, 0, 1};

	loadMatrix(&retMatrix, 4, 4, values);

	return retMatrix;
}

void Matrix::loadMatrix(Matrix* matrix, int width, int height, float values[]){
	matrix->width = width;
	matrix->hieght = height;

	for(int i = 0; i<width*height ;i++)
	{
		matrix->values.push_back(values[i]);
	}
}

