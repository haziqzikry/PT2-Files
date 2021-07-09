#include<iostream>
using namespace std;

class Person{
	protected:
		string name;
	public:
		Person(string n="") : name(n){}
		// overloaded method: set()
		void set(string n) {name=n;}
		void set() { cout << "Enter the name => "; cin >> name; }
		void print() const{cout << "Person's Name: " << name << endl;}
		virtual void whoAmI() const{cout << "I am a Person" << endl; }
};
    
class Student : public Person{
	private:
		string matric;
	public:
		Student(string m="", string n="") : Person(n), matric(m) {}
		// redefined method: print()
		void print() const{ 
		   cout << "Student's Name  : " << name << endl; 
		   cout << "Student's Matric: " << matric << endl; 
		}
		// overriden method: whoAmI()	
		void whoAmI() const{ cout << "I am a Student" << endl; 	}
};

int main(){
	Student s("ali", "123");
	s.print();
	s.whoAmI();
	return 0;
}
