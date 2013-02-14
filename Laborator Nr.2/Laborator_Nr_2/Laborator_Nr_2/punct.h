#pragma once

class punct
{
protected:
	int x;
	int y;
	long color;

public:
	punct(void);
	punct(int x, int y, long color);
	~punct(void);

	void setX(int x);
	void setY(int y);
	void setColor(long color);

	int getX(void);
	int getY(void);
	long getColor(void);

	virtual void show(void);
	void translate(int a, int b);
};
