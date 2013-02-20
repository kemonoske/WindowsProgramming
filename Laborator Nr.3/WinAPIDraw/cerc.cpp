#include "cerc.h"
#include <iostream>

cerc::cerc(void)
{
}

cerc::cerc(int x, int y ,int color, int r) : punct(x, y, r)
{
	setR(r);
}

cerc::~cerc(void)
{
}

void cerc::setR(int r){

	this->r = r;

}

int cerc::getR(void){

	return this->r;

}

void cerc::draw(HDC hdc)
{
	HPEN hPen;
	hPen=CreatePen(PS_SOLID, 1, color);
	SelectObject(hdc, hPen);
	Ellipse(hdc, x-r, y-r, x+r, y+r);
	DeleteObject(hPen);
}
