// FinalExam-Paper2-Question-SCSJ1023-201820191_program1
#include<iostream>
#include<string>
using namespace std;

// Class Person is given. Do nothing on this class
class Person{
    protected:
        string name;
    public:
        Person(string _name="") : name(_name)
        {}

        string getName() const { return name;}
};

// Task 1
class Student : public Person{
    protected:
        string program;
    public:
        Student (string name = " ", string program = " ") : Person (name)
        {
            program = program;
        }

};

// Task 2
class Employee : public Person{

    protected:
        string company;
    public:
        Employee (string name = " ", string company = " ") : Person (name)
            {
                company = company;
            }

};

// Task 3
class Advisor : public Person{

    protected:
        string department;
    public:
        Advisor (string name = " ", string department = " ") : Person (name)
            {
                department = department;
            }

};

// Task 4
class PartTimeStudent : public Student, Employee{

    protected:
        string maxCredit;
        Advisor * advisor;

    public:
        PartTimeStudent(string n="", int maxc=0, string p="", string c="") : Student(n,program), Employee (n, company)
        {
            maxCredit = maxc;
            advisor = NULL;
        }

        void setAdvisor( Advisor * advisor)
        {
            advisor = advisor;
        }

        string getAdvisorName (){
            if (advisor != NULL)
                return advisor -> getName();
            else
                return " ";
        }


};

int main(){
system("pause");
return 0;
}
