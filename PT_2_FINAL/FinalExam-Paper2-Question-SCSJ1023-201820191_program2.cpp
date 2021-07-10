// FinalExam-Paper2-Question-SCSJ1023-201820191_program2
#include<iostream>
#include<string>
using namespace std;

// Constants needed for this program
// PI : to calculate circle's area
// SIZE: the size of the array used in the class "List"
#define PI 3.14
#define SIZE 5

//----------------------------------------------------
// The class Point is given. Do nothing on this class
//----------------------------------------------------
class Point{
 protected:
 double x, y;

 public:
 Point(double _x = 0, double _y = 0) : x(_x), y(_y)
 {}

 double getX() const { return x; }
 double getY() const { return y; }
 void setX(double value) {x = value;}
 void setY(double value) {y = value;}

 void input() { cout << "Enter x and y => "; cin >> x >> y; }
 void print() const { cout << "(" << x << "," << y << ")\t\t"; }

 // Operator for adding two points
 Point operator+(Point right) const { return Point(x + right.x, y + right.y); }

 // Operator for dividing a point with a number
 Point operator/(double right) const { return Point(x / right, y / right); }
};

class Shape{
 protected:


 public:

 do ubvilert xua, l y;void
};

class Circle 

class Rectangle

class List{
 protected:

 public:

 // Exception classes definitions

 // Exception handling
};

// The menu function is given
int menu()
{
 cout << endl;
 cout << "========== Menu ==========" << endl;
 cout << "1. Add circle" << endl;
 cout << "2. Add rectangle" << endl;
 cout << "3. Print list" << endl;
 cout << "4. Edit item" << endl;
 cout << "5. Exit" << endl;
 cout << endl;

 int choice;
 cout << "Choose an operation [1-5] => ";
 cin >> choice;

 cin.ignore();
 cout << endl;

 return choice;
}

int main()
{
 List list;

 // The program structure regarding the menu operation is given
 int operation = menu();

 while ( operation != 5 ){


 }


 // Exception handling 2m

 operation = menu();

 return 0;
}
