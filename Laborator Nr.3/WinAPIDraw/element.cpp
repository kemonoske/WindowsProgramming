#include "element.h"
#include <cstdio>
#include "cerc.h"
#include "segment.h"
#include <iostream>

element::element(void)
{
}

element::~element(void)
{
	delete this->p;
	delete this->urm;
}

element::element(punct *adr, int tp)
{
	this->p = adr;
	this->tip = tp;
	this->urm = NULL;
}
void element::draw(HDC hdc)
{
	if(dynamic_cast<cerc*>(p))
		std::cout << "Cerc:" << std::endl;
	else if(dynamic_cast<segment*>(p))
		std::cout << "Segment:" << std::endl;
	else
		std::cout << "Punct:" << std::endl;
	p->draw(hdc);
}
