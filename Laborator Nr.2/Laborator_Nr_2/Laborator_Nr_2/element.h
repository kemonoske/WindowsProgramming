#pragma once
#include "punct.h"

class element 
{ 
public: 
	element * urm; 
	int tip; 
	punct* p; 
	void show(); 
	element(punct *adr, int tp); 
	element(); 
	virtual ~element(); 
}; 