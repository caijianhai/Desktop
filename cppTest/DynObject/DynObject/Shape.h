
#ifndef _SHAPE_H__
#define _SHAPE_H__

#include "DynFactory.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape
{
public:
	void draw();
	~Circle();
};

class Square : public Shape
{
public:
	void draw();
	~Square();
};

class Rectangle: public Shape
{
public:
	void draw();
	~Rectangle();
};



#endif // _SHAPE_H__