/* Assignment 1: Associations, Aggregations, and Compositions (5%)

Instructions: 
1.	You need to put your name and the description of the program at the top of your *.h and *.cpp files. 
2.	You are also required to give some comments regarding the program as your documentation. 
3.	// put all members names at the top of your header and cpp files

Note the company has set the rule that each customer can only rent one car at a time.
Create a C++ program to implement all three classes with the given attributes and operations.
Test the class by creating an object of Car and an array of customers:

Customer Name	Phone Number		Rented Car Plate
ABC				+60123456789		JJJ28
XYZ				+60109876543		

Group Members:
MUHAMMAD NAIM BIN ABDUL JALIL           -A20EC0096
MUHAMMAD ANIQ AQIL BIN AZRAI FAHMI	    -A20EC0083
MOHAMAD HAZIQ ZIKRY BIN MOHAMMAD RAZAK	-A20EC0079

Section 10
Lecturer's Name: Dr. Nies Hui Wen
*/

//headers
#include <iostream>
#include <string>
#include <iomanip>
//header file for each class
#include "phone.h"
#include "car.h"
#include "customer.h"
using namespace std;

//Main function
int main (){
	const int SIZE = 2;
	//Create an Object Car
	Car car1("JJJ28");
	//Create Object Phone
	Phone *p[SIZE] = {new Phone ("+60123456789"), new Phone ("+60109876543")};

	//Customer has a car and Phone is a part of Customer
	//Create an array of Customer
	Customer *cust[SIZE] = {new Customer("ABC", p[0],  &car1), new Customer("XYZ", p[1])};
	
	//Output
	cout << "Customer Name" << "\t" << "Phone Number" << "\t" << "Rented Car Plate" << endl;
	for (int i = 0; i < SIZE; i++)
		cust[i]->print();
	
	//Delete Customer Object and Phone Object (Composition)
	cout << endl;
	for (int i = 0; i < SIZE ; i++)
	{
		cout << cust[i]->getName() << " and " << p[i]->getPhone() << " was deleted\n";
		if (cust[i]->getCar() != "")
			cout << cust[i]->getName() << " has rented car " << cust[i]->getCar() << endl;
		
		//Dynamic Memory Allocation deletion
		delete cust[i];
		delete p[i];
	}

	//Car still exist
	cout << endl << "List of Car Plate" << endl;
	cout << car1.getPlate();

    return 0;
}

