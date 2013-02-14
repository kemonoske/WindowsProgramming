#include "om.h"

void om::create(char *name, float h, float w)
{
	this->name = name;
	this->h = h;
	this->w = w;
}

char *om::getName()
{
	return this->name;
}

float om::getHeight()
{
	return this->h;
}

float om::getWeight()
{
	return this->w;
}

void om::setName(char *name)
{
	this->name = name;
}

void om::setheight(float h)
{
	this->h = h;
}

void om::setWeight(float w)
{
	this->w = w;
}

void om::show(void)
{

	std::cout << "Numele:" <<this->name << std::endl
		<< "Inaltimea: " << this->h << std::endl
		<< "Greutatea: " << this->w << std::endl; 

}

bool om::equals(om *a, om *b)
{
	if(a->getHeight() == b->getHeight() && a->getWeight() == b->getWeight())
		return true;
	return false;

}

om::om(void)
{
}

om::om(char *name,float h, float w)
{
	this->name = name;
	this->h = h;
	this->w = w;
}

om::~om(void)
{
	free(name);
}
