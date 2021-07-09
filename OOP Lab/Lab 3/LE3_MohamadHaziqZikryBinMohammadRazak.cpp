/* Lab Exercise 3: Associations, Aggregations, and Compositions (2.5%)

Instructions:
1.	You need to put your name and the description of the program at the top of your *.cpp file.
2.	You are also required to give some comments regarding the program as your documentation.
Question:
Create a C++ program and complete the UML Class Diagram below.
The Course has a Student.

Mohamad Haziq Zikry Bin Mohammad Razak		-A20EC0079
Section 10
Lecturer's Name: Dr. Nies Hui Wen

*/

//headers
#include <iostream>
#include <cstring>
using namespace std;

//declare Student class
class Student{

    //private member attributes 
    private:
        string firstName;
        string lastName;
    public:
        //passing firstName, lastName using this pointer
        Student(string _firstName, string _lastName){
             this->firstName = _firstName;
			this->lastName = _lastName;
        }

        //function declaration to allocate firstName, lastName
        void setName(string, string);

        //destructor in class Student
        ~Student(){
		cout << firstName  << " " << lastName << " is destroyed" << endl;
        }

        //friend for class Course to access class Student private members and print in print function from class Course
        friend class Course;
};

//definition of setName function from class Student
void Student::setName(string _firstName, string _lastName){        
            this-> firstName = _firstName;
            this-> lastName = _lastName;
        }
        
//declare Course class
class Course{

    //private member attributes 
    private:
        string courseName;
        Student *student;
    public:
            //passing courseName, student
        Course(string _courseName , Student &student){
            courseName = _courseName;
            this -> student = &student;
        }

    //destructor in class Course
    ~Course(){
		cout << courseName << " is destroyed" << endl;
    }
        //inline member function to print output
        void print();
        
};

//definition of print function from class Course
  void Course::print(){
            cout << student->firstName << " " << student->lastName << endl;
            cout << courseName << endl;
            cout << endl;
        }

int main(){

    //call passing argument to constructor from class Student
    Student s ("Haziq", "Zikry");
    Student s1 ("Zafran", "Hazim");

    //call passing argument to constructor from class Course
    Course c ("1st Year Computer Science (Software Engineering)", s);
    Course c1 ("1st Year Computer Science (Data Engineering)", s1);
	
    //call display
    c.print();
    c1.print();
    
    //destructor 
    cout << "\nDestructor for:" << endl;
	cout<< "-------------------------" << endl;
    return 0;
}