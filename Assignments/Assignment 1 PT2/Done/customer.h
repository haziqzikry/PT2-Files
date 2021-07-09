/* Assignment 1: Associations, Aggregations, and Compositions (5%)

Instructions: 
1.	You need to put your name and the description of the program at the top of your *.h and *.cpp files. 
2.	You are also required to give some comments regarding the program as your documentation. 
3.	// put all members names at the top of your header and cpp files

Note the company has set the rule that each customer can only rent one car at a time.
Create a C++ program to implement all three classes with the given attributes and operations.
Test the class by creating an object of Car and an array of customers:

Customer Name	Phone Number		Rented Car Plate
ABC			    +60123456789		JJJ28
XYZ			    +60109876543		

Group Members:
MUHAMMAD NAIM BIN ABDUL JALIL           -A20EC0096
MUHAMMAD ANIQ AQIL BIN AZRAI FAHMI	    -A20EC0083
MOHAMAD HAZIQ ZIKRY BIN MOHAMMAD RAZAK	-A20EC0079

Section 10
Lecturer's Name: Dr. Nies Hui Wen
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<cstring>
#include<iostream>
//header file for to connnect Car and Phone class
#include "phone.h"
#include "car.h"
using namespace std;

//Declare Customer class
class Customer
{
	 //Private member attributes
    private:
        string name;
        Phone *phone;
        Car *car;
    public:
		//Constructor
        Customer (string n, Phone* phone, Car *car = NULL){		//inline function assigning parameter to private variables
        	name = n;
			this->phone = phone;
			this->car = car;
		}
		
		//Accessor
        string getName(){
			return name;										//inline function retruning name
		}
        
		//Accessor
        string getCar(){
        	if (car != NULL)									//inline function returning no.plate
				return car->getPlate();
			return "";
		}
		
		//Display output
        void print(){
        	cout << left << setw(13) << name << "\t" << phone->getPhone() << "\t"  << getCar() << endl;			//inline function displaying output
		}
};
#endif
