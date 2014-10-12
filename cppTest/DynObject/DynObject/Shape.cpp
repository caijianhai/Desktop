#include "Shape.h"
#include <iostream>

using namespace std;


void Square::draw()
{
	cout<<" Square::draw()"<<endl;
}
 Square::~Square()
{
	cout<<"Square::~Square()"<<endl;
}


 void Circle::draw()
{
	cout<<"Circle::draw()"<<endl;
}
 Circle::~Circle()
{
	cout<<"Circle::~Circle()"<<endl;
}

 void Rectangle::draw()
{
	cout<<" Rectangle::draw()"<<endl;
}
 Rectangle::~Rectangle()
{
	cout<<" Rectangle::~Rectangle()"<<endl;
}


FACTORY_REGISTER(Circle);
FACTORY_REGISTER(Square);
FACTORY_REGISTER(Rectangle);