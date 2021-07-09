////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 1, 2017/2018
// Skill-based Test 1
// October 12, 2017
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

// Task 1: Complete the definition of class Date.
class Date 
{
	private: 
		

    int day,month,year;
        
	public :
	
	Date(int dd,int mm,int yyyy) {
		
        	day=dd;
        	month=mm;
        	year=yyyy
        
        // variables
       


		friend ostream & operator<< (ostream &, const Date &d);	
		friend istream & operator>> (istream &, Date &d);
};
ostream & operator << (ostream &out, const Date &d)
{
    out << d.day<< endl;
    out << d.month << endl;
    out << d.year<< endl;
    return out;
}
  
istream & operator >> (istream &in,  Date &d)
{
    cout << "Enter Day ";
    in >> d.day;
    cout << "Enter Month ";
    in >> d.month;
    cout << "Enter Year ";
    in >>d.year;
    return in;

// Task 1(e): The following function is partialy given. 
//              Complete the code of the operator >>.

istream & operator>> (istream &inp, Date &obj1) 
{
	cout << "Enter your Date1 (day, month, year): ";
	cin>>obj1.day>>obj1.month>>obj1.year;
	

	return inp; 
}	

istream & operator>> (istream &inp, Date &obj2 )
{
	cout << "Enter your Date2 (day, month, year): ";
	cin>>obj2.day>>obj2.month>>obj2.year;
	
	cout<<" date2 is "<<obj2.dd2<<"/"<<obj2.mm2<<"/"<<obj2.yyyy2<<endl;
    cout<<"date1 is "<<obj1.dd1<<"/"<<obj1.mm1<<"/"<<obj1.yyyy1<<endl;
	

	return inp; 
}	

    //calculate
    yyyy=yyyy1-yyyy2;
    mm=mm1-mm2;
    dd=dd1-dd2;

   
    
    
    
    
// Task 1(f): The following function is partialy given. 
//              Complete the code of the operator <<
ostream & operator<< (ostream &out, const Date &obj) 
{

 //case if dd is negative 
    if(dd<0)
    {
       mm--;
       dd+=30;
    }

    //case if mm is negative 
    if (mm<0)
    {
        yyyy--;
        mm+=12;
    }

   
	return out; 
}




// Task 2: The following function is partialy given. 
//           Complete the code of the function displayDiff.

void displayDiff(Date d) 
{
			 //final output
    cout<<"Difference between dates is "<<dd<<" days "<<mm<<" months and "<<yyyy<<" years"<<endl;
   
	return out; 

}

int main()
{
	
	 Date dateObj1;
	 Date dateObj2;
	 



	
	// Task 3:  
	
	
	
	
	// Task 4: 
	
	
  Dates date []= {Date ("SBT","Test","Final" );
			                    
			                     
			                     
	
	
	// Task 5: 
	
	
	
	
	
	// Task 6: 

		
		
		
	return 0;
}
