//#include "BBPlayer.h"

class BBModel
{
public:
	// Constructors
	BBModel();
	BBModel(int width1, int height1 /*,Image background1, BBPlayer* players1*/);

	// Getters and setters
	float getWidth(){return width;}
	float getHeight(){return height;}
	void setWidth(float width1){width = width1;}
	void setHeight(float height1){height = height1;}

	// other functions
	void LMouseClick(int x, int y);
	void RMouseClick(int x, int y);
	void MouseHover(int x, int y);
	void MouseDrag(int startX, int startY, int endX, int endY);

private:
	float width;
	float height;
	//Image Background;
	//BBPlayer* players;
	//BBPlayer* curPlayer;
};