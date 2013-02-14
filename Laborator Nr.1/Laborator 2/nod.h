#pragma once
#include "om.h"

class nod
{
private:
	om *o;
	nod *next;
public:
	nod * getNext(void);
	void setO(om *);
	om * getO(void);
	void setNext(nod *);
	nod(void);
	nod(om *);
	~nod(void);
};
