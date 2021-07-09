#include<iostream>
using namespace std;

#define PI 3.14

class Shape{
	public:
		virtual int getArea() const = 0; // pure virtual 
		// Now, we cannot create any object from the class Shape.
		// Thus the following code would result in an error: Shape s;
		// Child classes must override pure virtual methods
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

void displayArea(const Shape *p){ // parent class: pointer
	cout << "Area = "  << p->getArea() << endl;
}

int main(){
	//Shape s;  // Cannot create object for Shape as it an abstract class because of pure virtual
	Circle c(10);
	Rectangle r(2,6);
	displayArea(&c); // pass by reference
	displayArea(&r); // pass by reference
	return 0;
}

