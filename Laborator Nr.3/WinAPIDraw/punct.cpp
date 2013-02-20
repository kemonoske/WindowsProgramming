#include "punct.h"
#include <iostream>

punct::punct(void)
{
}

punct::punct(int x, int y, long color)
{

	this->setX(x);
	this->setY(y);
	this->setColor(color);

}

punct::~punct(void)
{
}

void punct::setX(int x)	{

	this->x = x;

}

void punct::setY(int y)	{

	this->y = y;

}

void punct::setColor(long color)	{

	this->color = color;

}

int punct::getX(void)	{

	return this->x;

}

int punct::getY(void)	{

	return this->y;

}

long punct::getColor(void)	{

	return this->color;

}

void punct::draw(HDC hdc)	{
	HPEN hPen;
	hPen=CreatePen(PS_SOLID, 1, color);
	SelectObject(hdc, hPen);
	MoveToEx(hdc, x-4, y, NULL);
	LineTo(hdc, x+4, y);
	MoveToEx(hdc, x, y-4, NULL);
	LineTo(hdc, x, y+4);
	DeleteObject(hPen);
}


void punct::translate(int a, int b)	{

	this->setX(this->getX() + a);
	this->setY(this->getY() + b);

}
