//exercise: class, objects, constructors, destructor - write a complete C++ program
//SECJ1023 PT2 - section 10
// Mohamad Haziq Zikry Bin Mohammad Razak A20EC0079
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

//create a class called studentPT2
class studentPT2
{
	//private member attributes are name,matricNumber,country, and function to append firstName and lastName 
	private:
		string name,matricNumber,country;
		void getName(string first, string last)
		{
			name = first + " " + last;
		}
	
	//public member functions are default constructor, passing argument to constructor (inline), copy constructor (inline), destructor, display	void getdata();
	public:
	//default constructor to allocate name (firstName lastName), matricNumber, and country
		studentPT2 ();
		//passing firstName, lastName, matricNumber, and country to the constructor
		studentPT2(string n, string mn,string c)
		{
			name = n;
			matricNumber = mn;
			country = c;
		}
		//call the private function of append firstName and lastName in the constructor
		studentPT2(string first, string last, string mn, string c)
		{
			getName(first, last);
			matricNumber = mn;
			country = c;
		}

		//copy constructor (use &object for copy constructor)
		studentPT2 (const studentPT2 &x)
		{
			name = x.name;
			matricNumber =x.matricNumber;
			country = x.country;
		}
		
		//destructor
	~studentPT2(){
		cout << "\n4. Destructor called:" << endl;
		cout<< "-------------------------" << endl;
		cout << "Information for " << name << " (" << matricNumber << ")" <<"-" << country << " is destroyed" << endl;
		getch ();
	}	
		//display
	void displayData();
	

};
//definition of default constructor from class studentPT2
studentPT2::studentPT2 ()
{
	name = "Kenny Alvin" ;
	matricNumber = "A21CS0001";
	country = "UK";
}

//definition of display function from class studentPT2
void studentPT2::displayData()
	{
	cout << "\n-------------------------" << endl
	<< "Name\t: " << name << endl
	<< "Matric\t: " << matricNumber << endl
	<< "Country\t: " << country << endl
	<< "-------------------------" << endl;
	}
	
	

int main()
{
	cout<<"----PT2 Students List----" << endl;
	//call default constructor
	studentPT2 s1;
	//call display
	cout<<"1. Default constructor called: ";
	s1.displayData();
	//call passing argument to constructor
	studentPT2 s2 ("Alan Jack","B21CS2001","USA");
	//call display
	cout <<"\n2. Parameterized constructor called: ";
	s2.displayData();
	//call copy constructor - e.g., className objectName3(objectName1)
	studentPT2 s3(s1);
	//call display
	cout<<"\n3. Copy constructor called: ";
	s3.displayData();
	//call copy constructor - e.g., className objectName3=objectName1
	studentPT2 s4=s2;
	//call display
	cout<<"\n3. Copy constructor called: ";
	s4.displayData();
	cout<<"\n-----------End-----------\n";
	return 0;
}

/*
output
----PT2 Students List----
1. Default constructor called:
-------------------------
Name    : Kenny Alvin
Matric  : A21CS0001
Country : UK
-------------------------

2. Parameterized constructor called:
-------------------------
Name    : Alan Jack
Matric  : B21CS2001
Country : USA
-------------------------

3. Copy constructor called:
-------------------------
Name    : Kenny Alvin
Matric  : A21CS0001
Country : UK
-------------------------

3. Copy constructor called:
-------------------------
Name    : Alan Jack
Matric  : B21CS2001
Country : USA
-------------------------

-----------End-----------

4. Destructor called:
-------------------------
Information for Alan Jack (B21CS2001)-USA is destroyed

4. Destructor called:
-------------------------
Information for Kenny Alvin (A21CS0001)-UK is destroyed

4. Destructor called:
-------------------------
Information for Alan Jack (B21CS2001)-USA is destroyed

4. Destructor called:
-------------------------
Information for Kenny Alvin (A21CS0001)-UK is destroyed

*/