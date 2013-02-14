#pragma once
#include "punct.h"

class segment :
	public punct
{
private:
	int dx;
	int dy;
public:
	segment(void);
	segment(int x, int y, long color, int dx, int dy);
	~segment(void);

	void setDx(int dx);
	void setDy(int dy);

	int getDx(void);
	int getDy(void);

	void show(void);

	punct* secondPoint(void);
};
