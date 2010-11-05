#ifndef BBCONTROLER_H
#define BBCONTROLER_H

#include "BBModel.h"

class BBControler
{
public:
	BBControler(BBModel* battleBoard1);
	void LeftMouseClick(int x, int y);
	void RightMouseClick(int x, int y);
	void MouseHover(int x, int y);
	void LeftMouseDrag(int xStart, int yStart, int xEnd, int yEnd);

private:
	BBModel* battleBoard;
};

#endif