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

void cerc::show(void){

	punct::show();

	std::cout << "r = " << getR() << std::endl;

}