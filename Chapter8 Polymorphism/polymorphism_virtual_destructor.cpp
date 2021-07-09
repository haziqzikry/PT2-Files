#include<iostream>
using namespace std;

class Parent{
	protected:
		string name;		
	public:
		Parent(string n=""){
			name = n;
		}
		virtual ~Parent(){ // virtual destructor
		    cout << "Destroy Parent object" << endl; 
		}
};
    
class Child : public Parent{
	private:
		int age;
	public:
		Child(int a=0, string n="") : Parent(n){
			age = a;
		}
		~Child(){
		   cout << "Destroy Child object" << endl; 
		}
};

int main(){
	Parent *ptr;
	ptr = new Child(20, "Ali"); 	
	delete ptr;
	// Now, deleting the object will call to the Child’s destructor 
	// because the destructor is specified virtual (virtual ~Parent()). 
	// This allows C++ to perform dynamic binding to the destructor.
	return 0;
}


