#include<iostream>
using namespace std;

#define PI 3.14

class Shape{
	public:
		Shape(){}
		virtual int getArea() const { return 0;} // virtual: dynamically bound
};
    
class Circle : public Shape{ // child class
	private:
		double r;
	public:
		Circle(int _r){r=_r;;}
		int getArea() const { return PI*r*r;} // overriden: getArea()
};

class Rectangle : public Shape{ // child class
	private:
		int width, length;
	public:
		Rectangle(int w, int l){width = w; length = l;}
		int getArea() const { return width * length;} // overriden: getArea()
};

int main(){
	Shape s;
	Circle c(10);
	Rectangle r(2,6);
	Shape *list[3] = { &s, &c, &r }; // array
	for (int i=0; i<3; i++)
		cout << "Area = " << list[i]->getArea() << endl; // arrow pointer: list[i]->getArea()
		// Dot(.) operator is used to normally access members of a structure or union
		// Arrow(->) operator exists to access the members of the structure or the unions using pointers.
	return 0;
}

