//Multiple Inheritance

#include <iostream>
using namespace std;

// Base class
class MyClass {
  public:
  	MyClass()  { cout << "MyClass's constructor called" << endl; }
    void myFunction() {
      cout << "dad and mum in parent class.\n" ;
    }
};

// Another base class
class MyOtherClass {
  public:
  	MyOtherClass()  { cout << "MyOtherClass's constructor called" << endl; }
    void myOtherFunction() {
      cout << "god-dad and god-mum in another class.\n" ;
    }
};

// Derived class
class MyChildClass: public MyClass, public MyOtherClass {
  public:
  	MyChildClass()  { cout << "MyChildClass's constructor called" << endl; }
};

int main() {
  MyChildClass myObj;
  cout<<endl;
  myObj.myFunction();
  myObj.myOtherFunction();
  return 0;
}
