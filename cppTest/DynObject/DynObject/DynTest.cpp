#include "iostream"
#include "Shape.h"
#include "DynFactory.h"
#include <map>
#include <vector>

using namespace std;

void drawAll(vector<Shape *> v)
{
	vector<Shape *>::const_iterator it;
	for(it = v.begin(); it!= v.end(); ++it)
	{
		(*it)->draw();

	}
}

void deleteAll(vector<Shape *> v)
{
	vector<Shape *>::const_iterator it;
	for(it = v.begin(); it!= v.end(); ++it)
	{
		delete(*it);
	}
}

int main()
{
	vector<Shape *> v;

	Shape* s1 = static_cast<Shape*>(DynFactory::CreateObject("Circle"));
	v.push_back(s1);
	Shape* s2 = static_cast<Shape*>(DynFactory::CreateObject("Square"));
	v.push_back(s2);
	Shape* s3 = static_cast<Shape*>(DynFactory::CreateObject("Rectangle"));
	v.push_back(s3);

	drawAll(v);
	deleteAll(v);
	return 0;
}