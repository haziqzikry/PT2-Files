//Mohamad Haziq Zikry Bin Mohammad Razak A20EC0079
#include <iostream>

using namespace std;

int main() {


int age;
  
do
 {      

  cout <<"You need to verify your age before entering this place. \n";

  cout << "Enter age or -1 to quit : ";

  cin >> age;


try
 {

    if (age >=18) {

      cout << "Access granted - you can Enter now.\n\n";

    } 
else
 {

      
throw (age);

    }

  }

  
catch
 (int myNum) {

  	
if
 (myNum!= -1)

  	{  	

    	cout << "Access denied - You must be at least 18 years old.\n";

        cout << age<< " years old are not allowed to enter this place.\n\n";  

	}

  } 

  } 
while
 (age!= -1);

  cout << "Thank you." << endl;

  return 0;

}