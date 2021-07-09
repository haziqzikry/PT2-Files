#include<iostream>
using namespace std;

#define PI 3.14

class Shape{ // parent class
	public:
		Shape(){}
		virtual int getArea() const { return 0;} // virtual: dynamic binding
};
    
class Circle : public Shape{ // child class
	private:
		double r;
	public:
		Circle(int _r){r=_r;;}
		int getArea() const { return PI*r*r;}
};

class Rectangle : public Shape{ // child class
	private:
		int width, length;
	public:
		Rectangle(int w, int l){width = w; length = l;}
		int getArea() const { return width * length;}
};

int main(){
	Shape *p;
	Shape s;
	Circle c(10);
	Rectangle r(2,6);
	p = &s;
	cout << "Shape area = "  << p->getArea() << endl;
	p = &c;
	cout << "Circle area = " << p->getArea() << endl;
	p = &r;
	cout << "Rectangle area = " << p->getArea() << endl;
	return 0;
}

