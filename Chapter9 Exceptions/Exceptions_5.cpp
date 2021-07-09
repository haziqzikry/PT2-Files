// using online cpp compiler: https://www.onlinegdb.com/online_c++_compiler
// use dev c++: error exists

#include <iostream>     	// std::cout
#include <new>          	// std::bad_alloc
#include <typeinfo>       	// std::bad_cast, std::bad_typeid
#include <exception>      	// std::bad_exception, std::set_unexpected
#include <functional>   	// std::function, std::plus, std::bad_function_call
#include <memory>			// std::bad_weak_ptr
#include <cstddef>
#include <string>
#include <cstring>
#include <vector>         	// std::vector
#include <bitset>   	    // std::bitset
#include <stdexcept>		// std::logic_error, std::out_of_range, std::length_error, std::domain_error, std::range_error, std::runtime_error, std::overflow_error, std::undeflow_error, std::invlid_argument
using namespace std;

//#define NULL nullptr //since C++11

// code fragment for bad_typeid
/*struct S { // The type has to be polymorphic
    virtual void f();
};*/

// code fragment for bad_cast
/*class Base {virtual void member(){}};
class Derived:public Base {};*/

// code fragment for bad_exception
/*void myunexpected () {
  cerr << "unexpected handler called\n";
  throw;
}
void myfunction () throw (int,exception) {
  throw 'x'; // throws char (not in exception-specification)
}*/

int main () {
	//vector<int> myvector(10); // length_error
	// code fragment for bad_weak_ptr
	/*shared_ptr<int> p1(new int(42));
    weak_ptr<int> wp(p1);
    p1.reset();*/
	// code fragment for bad_typeid
	//S* p = nullptr;
	// code fragment for bad_function_call
	// function<int()> f = nullptr;
	// code fragment for bad_exception
	// set_unexpected (myunexpected);
  	try{
  		//myvector.at(20)=100; // length_error
  		//bitset<5> mybitset (string("01234")); // invlid_argument
  		//shared_ptr<int> p2(wp); // bad_weak_ptr
  		//cout << typeid(*p).name() << '\n'; // bad_typeid
  		//f(); // bad_function_call
  		//myfunction(); // bad_exception
  		/*Base b;
    	Derived& rd=dynamic_cast<Derived&>(b); // bad_cast */
  		while (true) {
            new int[100000000ul]; // bad_alloc
        }
  	}
  	catch (exception& e){
    	cerr<<"exception caught: "<<e.what()<<endl;
  	}
  	return 0;
}
