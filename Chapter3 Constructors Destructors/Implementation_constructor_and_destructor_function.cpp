// Implementation of constructor and destructor function
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
class date
{
 private :
  int day, year;
  char month[15];
 public :
  date(int a=10, const char b[]="November", int c=2020); // constructor
  ~date() // destructor (inline)
  { 
   cout << "\nObject with Date: " << day << "-" << month<< "-" << year << " is destroyed";
   getch();
  }
  void print();
};
 date::date(int a,const char b[],int c) // constructor implementation
{ 
 day = a;
 strcpy (month, b);
 year =  c;
}
void  date::print()
{ 
 cout << "\nThe date: " << day << "-" << month << "-" << year;
}
int main()
{
 date today(9,"November",2020);
 today.print();
 date registerDay(11,"November",2020);
 registerDay.print();
 cout<<"\n\nInstruction: Click Enter from your Keyboard until the end\n";
 return 0;
}
