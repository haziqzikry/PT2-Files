// https://www.cplusplus.com/reference/exception/exception/
#include <iostream>
#include <exception>
using namespace std;

//Standard exception class

/*C++ 98: C++ 1998/2003 Standard
class exception{
	public:
		exception() throw();
		exception(const exception&) throw();
		exception& operator=(const exception&) throw();
		virtual ~exception() throw();
		virtual const char* what() const throw();
};*/

/*C++ 11: C++ 2011 Standard
class exception {
	public:
  		exception () noexcept;
  		exception (const exception&) noexcept;
  		exception& operator= (const exception&) noexcept;
  		virtual ~exception();
  		virtual const char* what() const noexcept;
};*/

class myexception: public exception{
  	virtual const char* what() const throw(){
    	return "My exception happened";
  	}
} myex;

int main () {
  	try{
    	throw myex;
  	}
  	catch (exception& e){
    	cout << e.what() << '\n';
  	}
  	return 0;
}
