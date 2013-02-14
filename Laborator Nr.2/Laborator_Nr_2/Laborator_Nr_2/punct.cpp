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

void punct::show(void)	{

	std::cout << "x = " << this->getX() << std::endl
		<< "y = " << this->getY() << std::endl
		<< "Culoare = " << this->getColor() << std::endl;

}

void punct::translate(int a, int b)	{

	this->setX(this->getX() + a);
	this->setY(this->getY() + b);

}
