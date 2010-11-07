
#include "DrawableModel.h"

DrawableModel::DrawableModel(int cache){
	cacheModel = cache;
	cacheTexture = -1;
}
DrawableModel::~DrawableModel(){
}

DrawableModel* DrawableModel::NULLDrawableModel(){
	static int nullModel = -1;
	static DrawableModel* nullDraw;

	if(nullModel<0)
	{
		nullModel = glGenLists(1);

		glNewList(nullModel,GL_COMPILE);

		GLUquadricObj* quadratic=gluNewQuadric();
		gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals ( NEW )

		gluSphere(quadratic, 0.5f, 12, 12);

		glEndList();

		nullDraw = new DrawableModel(nullModel);
	}

	return nullDraw;
}