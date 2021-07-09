#include<iostream>
using namespace std;

class Parent{
	protected:
		string name;		
	public:
		Parent(string n=""){
			name = n;
		}
		~Parent(){
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
	delete ptr; // delete parent object
	// Although ptr is pointing to a Child object, 
	// deleting the object will call to the Parent’s destructor 
	// because the compiler performs static binding to the destructor.
	return 0;
}


