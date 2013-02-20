#include "segment.h"
#include <iostream>

segment::segment(void)
{
}

segment::segment(int x, int y, long color, int dx, int dy) : punct(x, y, color){

	setDx(dx);
	setDy(dy);

}

segment::~segment(void)
{
}

void segment::setDx(int dx)	{

	this->dx = dx;

}

void segment::setDy(int dy)	{

	this->dy = dy;

}

int segment::getDx(void)	{

	return this->dx;

}

int segment::getDy(void)	{

	return this->dy;

}

void segment::draw(HDC hdc)
{
	HPEN hPen;
	hPen=CreatePen(PS_SOLID, 1, color);
	SelectObject(hdc, hPen);
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x+dx, y+dy);
	DeleteObject(hPen);
}

punct* segment::secondPoint(void){

	punct* p = new punct(this->x + this->dx, this->y + this->dy, this->color);

	std::cout << "x2 = " << p->getX() << std::endl
		<< "y2 = " << p->getY() << std::endl;

	return p;

}
