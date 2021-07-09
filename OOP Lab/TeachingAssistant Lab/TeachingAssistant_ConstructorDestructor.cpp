// Mohamad Haziq Zikry Bin Mohammad Razak A20EC0079
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

class TeachingAssistant
{
	private:
		string name;
		char officenum[15];
		char phonenum[15];
		int age;
		char coursesubject[10];
	public:
			TeachingAssistant (string n, const char o[], const char p[], int a, const char c[]); //passing arguments to default constructor
			~TeachingAssistant() //destructor
			{
				cout << "\nTeaching Assistant Data" << endl
				<< "Name\t\t: " << name << endl
				<< "Office Number\t: " << officenum << endl
				<< "Phone Number\t: " << phonenum << endl
				<< "Age\t\t: " << age << endl
				<< "Course Subject\t: " << coursesubject << endl << endl;
				cout << "Teaching Assistant Data above has been destroyed." << endl;
				getch ();
			}
	void getData();
};
TeachingAssistant::TeachingAssistant(string n, const char o[], const char p[], int a, const char c[]) //constructor implementation
{
	name = n;
	strcpy (officenum, o);
	strcpy (phonenum, p);
	age = a;
	strcpy (coursesubject, c);

}
void TeachingAssistant::getData()
{
	cout << "\nYOUR TEACHING ASSISTANT DATA" << endl;
	cout << endl;
	cout << "Your full name is: " << name << endl;
	cout << "Your office number is: " << officenum << endl;
	cout << "Your phone number is: " << phonenum << endl;
	cout << "Your age is: " << age << endl;
	cout << "Your course subject is: " << coursesubject << endl;
	cout << endl;
}

int main (){
	
	TeachingAssistant ta("Haziq Ali","0182385036","0333466895",22,"3SECJH");
	ta.getData();
	TeachingAssistant ta2("Xafran Abu","0134634636","024138950",19,"1SECBH");
	ta2.getData();
	cout << "Click Enter to finish until the end. \n" << endl;
	return 0;
}
