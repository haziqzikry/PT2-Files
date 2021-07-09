#include<iostream>
using namespace std;

#define PI 3.14

class Shape{ // parent class
	public:
		Shape(){}
		virtual int getArea() const { return 0;} // virtual: dynamically bound
};
    
class Circle : public Shape{ // child class
	private:
		double r;
	public:
		Circle(int _r){r=_r;;}
		int getArea() const { return PI*r*r;}
		void printRadius() const{
		    cout << "Radius: " << r << endl; 
		}
};

int main(){
	Shape *p; // pointer
	Circle c(10);
	p = &c;
	cout << "Area = " << p->getArea() << endl;
	p->printRadius(); // error: printRadius() belongs to child class
	// However, parent class pointers only knows about public members of the parent class.
	// The pointer cannot be used to refer to any member in the child classes.
	return 0;
}


