/*
Write a C++ program to include
two different class named addition (use object pointer) and subtraction (use object array)

Both class need to include 
two integers, one parameterized constructor (put inline), one copy constructor, and one destructor
calculations (put outside class), friend display results
*/

#include <iostream>
using namespace std;

const int size=2;

//the difference between the two class is that 
class subtraction{ // this class uses arrays to pass
	private:
		int x, y;
	public:
		subtraction(){ //default constructor
			x=y=0;
		}
		subtraction(int n1, int n2){ //parameterized constructor - also in an inline function because it is inside the class
			x=n1;
			y=n2;
		}
		subtraction(const subtraction &tolak){ //copy constructor
			x=tolak.x;
			y=tolak.y;
		}
		~subtraction(){
			cout<<x<<" and "<<y<<" is destroyed from subtraction\n";
		}
		int subtract();
};

int subtraction::subtract(){ //this uses int to return the x-y answer
	return (x-y);
}

class addition{ //this class uses pointers
	private:
		int a, b;
	public:
		addition(){  //default constructor
			a=b=0;
		}
		addition(int n1, int n2){ 
			a=n1;
			b=n2;
		} 
		// const is used so that it doesnt alter the value of the function
		addition(const addition &tambah){ //copy constructor use the object as a constructor (from addition)
			a=tambah.a;
			b=tambah.b;
		}
		~addition(){
			cout<<a<<" and "<<b<<" is destroyed from addition\n";
		}
		int add();
		friend void display(addition &a, subtraction m[]); // friend prototype
};

int addition::add(){
	return (a+b);
}

void display(addition a, subtraction m){ // definition of friend of classes
	cout<<"\nRESULT\n------\n";
	cout<<"addition: "<<a.add()<<endl;
	cout<<"subtraction: "<<m.subtract()<<endl;
}

int main(){
	cout<<"here, use of pointer\n";
	//pointer only passes one argument
	addition total(3,5);
	addition *plus;
	plus = &total;
	
	cout<<"addition total(3,5)";
	plus->add(); //plus is an object, add () is the function that belongs to total 
	
	cout<<"\nhere, use of array\n";
	//arrays can pass more than one argument
	subtraction minus[size]={subtraction(1,11),subtraction(6,2)}; // size is the object
	cout<<"subtraction(1,11),subtraction(6,2)";
	
	for(int i=0; i<size; i++){
		minus[i].subtract();
		cout<<"\n\nhere, friend->display";
		display(*plus, minus[i]);
	}
	
	cout<<"\nhere, copy constructor\n";
	addition tt=*plus;
	cout<<"addition tt=*plus: "<<tt.add()<<endl;
	
	cout<<"\ndestructor\n-----------\n";;
	return 0;
}
