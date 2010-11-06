#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
	int x; 
	int y;
	Position()
		:x(0), y(0)
	{}
	Position(int x1, int y1)
		:x(x1), y(y1)
	{}

private:
};

#endif