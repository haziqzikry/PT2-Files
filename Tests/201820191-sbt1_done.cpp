// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// 18 Oct 2018
//
// Skill-Based Test 1

//done by qiqi sect10
#include <iostream>
using namespace std;

class Point
{
	private:
		double x, y;

	public: 
		Point(double _x=0, double _y=0) { 
			x = _x;
			y = _y; 
		}

//satu lagi cara
//use 'this' if nak guna variable yang sama dari private
// Point(double x = 0, double y = 0){
// 		this->x = x;
// 		this->y = y;
// 	}

		//Accessor
		double getX() const {return x;}
		double getY() const {return y;}
		//Mutator
		void setX(double _x)  {x = _x;}
		void setY(double _y)  {y = _y;}
		
	//overloaded operator +
	Point operator+ (const Point &point)
	{
		Point p1;
		p1.x = x + point.x;
		p1.y = y + point.y;
		return p1;
	}

	//overloaded operator /
	Point operator/ (const int div)
	{
		Point p1;
		p1.x = this-> x/div;
		p1.y = this-> y/div;
		return p1;
	};

};

int main()
{
	int SIZE;
	double x,y;

	cout << "How many points you want to enter =>";
	cin >> SIZE;
	
	Point *points = new Point[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter the coordinates (x and y) => ";
		cin >> x;
		cin >> y;
		points[i].setX(x);
		points[i].setY(y);
	}
	
	//Guna konsep total
	Point midpoint(0.0, 0.0); // total = 0;

	cout << "Point\t\tx\ty" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << "\t\t" << points[i].getX() << "\t" << points[i].getY() << endl;
		midpoint = midpoint + points[i]; //total = total + value;

	}
	midpoint = midpoint/SIZE ; //ni macam total = total/size ... guna operator 
	cout << endl;
	cout << "Middle Point\t" << midpoint.getX() << "\t" << midpoint.getY();

	cout << endl << endl;
	system("pause"); // Remove this line if you are using Dev C++
	return 0;
}
