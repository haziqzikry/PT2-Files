//Polymorphism - Virtual Functions

#include <iostream>
using namespace std;

class B{           
	public: 
		virtual void display(){cout<<"virtual-B\n";} 
};

class D1:public B{ 
	public: 
		void display(){cout<<"B::D1\n";} 
};

class D2:public B{ 
	public: 
		void display(){cout<<"B::D2\n";} 
};

int main(){
	cout<<"Polymorphism - Virtual Functions - pointer\n";
	B* p;
    p=new D1; 
	p->display(); 
	p->B::display();
    p=new D2; 
	p->display(); 
	p->B::display();
	return 0;
}
