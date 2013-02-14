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

void segment::show(void)	{

	punct::show();
	std::cout << "dx = " << dx << std::endl
		<<"dy = " << dy << std::endl; 

}

punct* segment::secondPoint(void){

	punct* p = new punct(this->x + this->dx, this->y + this->dy, this->color);

	std::cout << "x2 = " << p->getX() << std::endl
		<< "y2 = " << p->getY() << std::endl;

	return p;

}