// This program is meant to show throwing different types of string

#include <iostream>
using namespace std;

int main(){
	int choice;
	cout << "Enter choice => ";
	cin >> choice;

	//try - to invoke code that throws an exception
	try	{  
			if (choice == 1) 
				throw "This is a const c-string"; //literal string - something like return but sends a signal that an error has occured
			if (choice == 2){
				char cStr[] = "This is a c-string";
				throw cStr; // c-string
			} 
			if (choice==3){
				string cppStr="This is a cpp-string";
				throw cppStr; // cpp string
			}
	}

	//catch - to detect and process exceptions thrown in from try block
	catch (const char *msg){
	    cout << "Caught msg1: " << msg;
	}
	catch ( char msg){
	    cout << "Caught msg2: " << msg;
	}
	catch (string msg){
	    cout << "Caught msg string: " << msg;
	}
	return 0;
}


