// static or dynamic binding of data?
#include <iostream>
#include <string>
using namespace std;

class B{
	public:
		string s;
};

class D:public B{
  	public:
		string s;
};

int main(){
	B b;  
	b.s="B";
	cout<<"b.s = "<<b.s<<endl;
	D d;  
	d.s="D"; 
	d.B::s="B::D";
	cout<<"\nd.s = "<<d.s;
	cout<<"\nd.B::s = "<<d.B::s<<endl;
	cout<<"\nPolymorphism - No Virtual Data - pointer\n";
	//p->s picks up the s inside B not in D even when p points at a D
	B* p;
	p=&b;
	cout<<"p->s = "<<p->s;
	p=&d;
	cout<<"\np->s = "<<p->s;
	return 0;
}
