//Mohamad Haziq Zikry Bin Mohammad Razak A20EC0079
#include <iostream>
using namespace std;

class student
{
	private:
		char matricNo[10];
		string firstName;
		string lastName;
		string emailAdd;
		int contactNo;
		char courseCode[4];
		int entryYear;
	public:
		void getData();
		void displayData();
		
};

void student::getData()
{
	cout << "PLEASE ENTER YOUR STUDENT DETAILS HERE\n" << endl;
	cout << "Enter your Matric Number (e.g., A18CS0001): ";
	cin >> matricNo;
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "Enter your E-mail address: ";
	cin >> emailAdd;
	cout << "Enter your contact number: ";
	cin >> contactNo;
	cout << "Enter your course code (e.g., SECJ, SECV, SECR, SECP, SECB): ";
	cin >> courseCode;
	cout << "Enter your year of entry (e.g., 2018): ";
	cin >> entryYear;
}

void student::displayData()
{
	cout << "\nYOUR PERSONAL STUDENT DATA" << endl;
	cout << endl;
	cout << "Your Matric Number is: " << matricNo << endl;
	cout << "Yyour first name is: " << firstName << endl;
	cout << "Your last name is: " << lastName << endl;
	cout << "Your E-mail address is: " << emailAdd << endl;
	cout << "Your contact number is: " << contactNo << endl;
	cout << "Your course code is: " << courseCode << endl;
	cout << "Your year of entry is: " << entryYear << endl;
	cout << endl;
}

int main (){
	
	student s;
	s.getData();
	s.displayData();
	
	return 0;
}
