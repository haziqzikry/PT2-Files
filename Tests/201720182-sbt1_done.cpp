////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 1, 2017/2018
// Skill-based Test 1
// October 12, 2017
////////////////////////////////////////////////////////////////////////////////

//done by qiqi Sect10
#include <iostream>
#include <cmath>

using namespace std;

// Task 1: Complete the definition of class Date.
class Date 
{
	private: 
			string description;
			int day, month, year;
	
	public:	
		//  Default constructor with default arguments 
		Date (string describe = "" ,int d = 0, int m = 0, int y = 0)
		{
			description = describe;
			day = d;
			month = m;
			year = y;
		};

/*
- satu lagi cara

- Default constructor
Date(){
            desc = " ";
            day = 0;
            month = 0;
            year = 0;
        }

- overloaded constructor (with arguments)
        Date(string _desc){
            desc = _desc;
            day = 0;
            month = 0;
            year = 0;
        }


- overloaded constructor (with arguments)
        Date(string _desc, int d, int m, int y){
            desc = _desc;
            day = d;
            month = m;
            year = y;

        }
		*/

		//accessor (c)
		int getDay() const {return day;};
		int getMonth() const {return month;};
		int getYear() const {return year;};

		// 1(d) - overloaded operator
		Date operator - (const Date& newDate)
		{
			Date minus;
			minus.day = abs(day - newDate.day);
			minus.month = abs(month - newDate.month);
			minus.year = abs(year - newDate.year);
			return minus;
		}

		friend ostream & operator<< (ostream &, const Date &);	
		friend istream & operator>> (istream &, Date &);
};


// Task 1(e): The following function is partialy given. 
//              Complete the code of the operator >>.

//enter date
istream & operator>> (istream &inp, Date &obj) 
{
	cout << "Enter your date (day, month, year): ";
	inp >> obj.day >> obj.month >> obj.year;
	return inp; 
}	

// Task 1(f): The following function is partialy given. 
//              Complete the code of the operator <<
//output date
ostream & operator<< (ostream &out, const Date &obj) 
{
	out << obj.description << ":" << obj.day << "-" << obj.month << "-" << obj.year;
	return out; 
}




// Task 2: The following function is partialy given. 
//           Complete the code of the function displayDiff.

void displayDiff(Date d) 
{
	cout << "The difference: ";
	if (d.getYear())
	{
		cout << d.getYear();
		cout << "year(s)";
	}
	else if (d.getMonth())
	{
		cout << d.getMonth();
		cout << "month(s)";
	}
	else  
	{
		cout << d.getDay();
		cout << "day(s)";
	}	
}

int main()
{
	// Task 3:  - Dia guna constructor Date (string)
	Date type[3] = {Date ("SBT"),Date ("Test"), Date ("Final")};
	
	// Task 4: 
	for (int i = 0; i < 3; i++)
		cin >> type[i]; // ni guna operator >>
	
	
	// Task 5: 
	//Dia guna constructor Date(string, int, int, int)
	Date date1 ("TODAY",5,3,2018);
	Date date2 ("dAte of birth",23,11,1999);

	// Task 6: 
	// ni guna operator <<
	cout << endl;
	cout << date1 << endl;
	cout << endl;
	cout << date2 << endl;

	displayDiff (date1 - date2);
		for (int i = 0; i < 3; i++)
		{
			cout << endl << type[i] << endl; // ni guna operator <<
			//difference to the object date1
			displayDiff(type[i] - date1); // ni guna operator -
		}
		
		
		
	return 0;
}
