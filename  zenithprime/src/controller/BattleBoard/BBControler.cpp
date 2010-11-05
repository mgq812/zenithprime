#include "BBControler.h"

BBControler::BBControler(BBModel* battleBoard1)
	:battleBoard(battleBoard1)
{}

void BBControler::LeftMouseClick(int x, int y)
{
	battleBoard->setHeight(0);
	battleBoard->setWidth(0);
}

void BBControler::RightMouseClick(int x, int y)
{}

void BBControler::MouseHover(int x, int y)
{}

void BBControler::LeftMouseDrag(int xStart, int yStart, int xEnd, int yEnd)
{}