#pragma once
#include "punct.h"

class cerc :
	public punct
{
private:
	int r;
public:
	cerc(void);
	cerc(int x, int y, int color, int r);
	~cerc(void);

	void setR(int r);
	int getR(void);

	void draw(HDC hdc);
};
