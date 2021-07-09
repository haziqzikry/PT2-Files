//Polymorphism by Overriding

#include <iostream>
using namespace std;

class B{           
	public: 
		void display(){cout<<"B\n";} 
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
	cout<<"polymorphism\n";
	B b; 
	b.display(); 
	D1 d1;
	d1.display(); 
	d1.B::display();
	D2 d2;
	d2.display(); 
	d2.B::display();
	cout<<"\npolymorphism-object: pointer\n";
	B* p;
    p=new D1; 
	p->display(); 
	p->B::display();
    p=new D2; 
	p->display(); 
	p->B::display();
	return 0;
}
