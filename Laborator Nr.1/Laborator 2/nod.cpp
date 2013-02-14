#include "nod.h"

nod * nod::getNext(void)
{
	return this->next;
}

void nod::setO(om * o)
{
	this->o = o;
}

om * nod::getO(void)
{
	return this->o;
}

void nod::setNext(nod *next)
{
	this->next = next;
}

nod::nod(om *o)
{
	this->o = o;
	this->next = NULL;
}
nod::nod(void)
{
	this->o = NULL;
	this->next = NULL;
}

nod::~nod(void)
{
	free(o);
	free(next);
}
