#pragma once
#include <iostream>

class om
{

private:
	char *name;
	float h;
	float w;

public:
	void create(char *, float, float);
	/*get Methods*/
	char * getName();
	float getHeight();
	float getWeight();
	/*set Methods*/
	void setName(char *);
	void setheight(float);
	void setWeight(float);
	/*other Methods*/
	void show(void);
	static bool equals(om *, om *);
	/*constructors/destructors*/
	om(void);
	om(char *, float, float);
	~om(void);
};
