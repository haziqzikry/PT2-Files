
#include <iostream>
#include<string>
 using namespace std; 
  class Employee{
      string name, city, state, country;
 int zipCode;

 public:
  Employee (string name) {
       name = name;

  }

  void setAddress (string, string, string, string);
 friend void displayAddress ();
friend ostream& operator<< (ostream&, const Employee&);

void setAddress(string cy, string st, string co, int zip) {
  city = cy;
     state = st ;
  country = co;
   zipCode = zip;
}
 friend void displayAddress(Employee e) {
     cout << "City :  " << e.city
                <<  "\nState :  " << e.state
                <<  " \nCountry :  " << e.country
            << "\ nZip code :  " << e . zipCode;}

ostream& operator<<(ostream& strm, const Employee& e){
          cout  <<  "Name :  " << e.name  << endl ;
 e.displayAddress ();
  return *this; 
}

 int main (){
     Employee emp = Employee ( "John ") ;
      emp.setAddress ( "Johor  Bahru ","Johor", "Malaysia" , 81300 ) ;
  cout<< " Employee  info :\ n-----------------\ n  "  << emp << endl;
     return 0;
     }
  
