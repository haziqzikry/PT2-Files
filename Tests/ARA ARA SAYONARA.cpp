////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 1, 2017/2018
// Skill-based Test 1
// October 12, 2017
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//ARASAYOOO YANG COMEL
//QIQI BUSUK

// Task 1: Complete the definition of class Date.
class Date 
{
	private: 
		string description;
		int day;
		int month;
		int year;	
	
	public:
		Date(){description = "", day = 0; month = 0; year = 0;}
		Date(string desc, int d=0, int m=0, int y=0){description = desc, day = d; month = m; year = y;}
		int getday() const{return day;}
		int getmonth() const{return month;}
		int getyear() const{return year;}
		Date operator-(const Date& x)
		{
			Date a;
			a.day = this->day - x.day;
			a.month = this->month - x.month;
			a.year = this->year - x.year;
			return a;
		}
		friend ostream & operator<< (ostream &, const Date &);	
		friend istream & operator>> (istream &, Date &);
};

// Task 1(e): The following function is partialy given. 
//              Complete the code of the operator >>.

istream & operator>> (istream &inp, Date &obj) 
{
	cout << "Enter your date (day, month, year): ";
	inp >> obj.day >> obj.month >> obj.year;
	cout << endl;		
	return inp; 
}	

// Task 1(f): The following function is partialy given. 
//              Complete the code of the operator <<
ostream & operator<< (ostream &out, const Date &obj) 
{
	out << obj.description << ": " << obj.day << "-" << obj.month << "-" << obj.year << endl;
	return out; 
}

// Task 2: The following function is partialy given. 
//           Complete the code of the function displayDiff.

void displayDiff(Date d) 
{
	cout << "The difference: ";
	if(d.getyear())
		cout << d.getyear() << " year(s)" << endl << endl;
	else if(d.getmonth())
		cout << d.getmonth() << " month(s)" << endl << endl;
	else if(d.getday())
		cout << d.getday() << " day(s)" << endl << endl;
}

int main()
{
	// Task 3:  
	Date date[3] = {Date("SBT"), Date("Test"), Date("Final")};
	
	// Task 4: 
	for(int i = 0; i < 3; i++)
		cin >> date[i];
	
	// Task 5: 
	Date date1("TODAY",5,3,2018);
	Date date2("Date of birth",28,4,2001);
	
	// Task 6:
	
	cout << date1 << endl;
	
	cout << date2;
	date2 = date1 - date2;
	displayDiff(date2);
	
	for(int x = 0; x < 3; x++)
	{
		cout << date[x];
		displayDiff(date[x]-date1);
	}
	return 0;
}
