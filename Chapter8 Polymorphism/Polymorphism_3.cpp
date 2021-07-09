//Polymorphism - Virtual Functions

#include <iostream>
#include <vector>
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
	cout<<"Polymorphism - Virtual Functions - vector\n";
	vector <B*> a;
	a.push_back(new D1);
	a.push_back(new D2);
	a.push_back(new D2);
	a.push_back(new D1);
    for(int i=0; i<a.size(); ++i)
		a[i]->display();
	cout<<"\nPolymorphism - Virtual Functions - array\n";
	B *b[]={new D1, new D2, new D2, new D1};
 	for(int i=0; i<sizeof(b)/sizeof(b[0]); ++i)
 		b[i]->display();
    return 0;
}
