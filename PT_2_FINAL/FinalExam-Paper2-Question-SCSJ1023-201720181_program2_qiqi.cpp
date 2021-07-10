////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 1, 2017/2018
// Final Exam, Paper 2, Question 2  (Problem Solving)
// Prepared by: Jumail Bin Taliba (jumail@utm.my)
// 5 November 2017
//      The program itself = 60 marks
//      Able to run and proper writing 5 marks
//      Total = 65 marks
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#define PI 3.1415

// 6m (total). 1m each
class Point{
	private:
		double x;
		double y;
	public:
		Point() {}
		void set (double x, double y){
			x = x;
			y = y;
		}
		
		double getX() {return x;}
		double getY () {return y;}
};

// 5m (total). 1m each.
class Shape{  
	public:
		Shape(){} 

		virtual double getArea() = 0;

		virtual void read() = 0;
		
		virtual void print() = 0;

};


//  15 marks (total)
class  Circle : public Shape {  //inheritance
	private:
		 double radius;
		 Point center; //composition
	
	public:
		Circle (){}
		double getArea(){
			return radius * radius * PI;
		}
		void read(){
			double x,y;
			cout << "Enter the center coordinates of the circle (x y)=> " ;
			cin >> x >> y;
			center.set(x,y);
			cout << "Enter the circle's radius=> ";
			cin >> radius;

		}
		void print(){
			cout << "Circle's center: X=" << center.getX() << "  Y=" << center.getY() << endl;
			cout << "Circle's radius =" << radius << endl;
			cout << "Circle's area   =" << getArea() << endl;

		}

		
};

// 19 marks (total)
class Rectangle : public Shape{  
	private:
		Point topLeft;
		Point bottomRight;
		double getWidth(){
			return abs(bottomRight.getX() - topLeft.getX());
		}
		double getHeight(){
			return abs(bottomRight.getY()- topLeft.getY());
		}
	public:
		Rectangle(){}
		double getArea(){
			 return getWidth() * getHeight();
		}

		void read(){
			double x,y;
			cout << "Enter the top left corner coordinates of the rectangle (x y) => ";
			cin >> x >> y;
			topLeft.set(x,y);
			cout << "Enter the bottom right corner coordinates of the rectangle (x y) => ";
			cin >> x >> y;
			bottomRight.set(x,y);
		}

		void print(){
			cout << "Rectangle's top left corner: X=" << topLeft.getX() << "  Y=" << topLeft.getY() << endl;
			cout << "Rectangle's bottom right corner: X=" << bottomRight.getX() << "  Y=" << bottomRight.getY() << endl;
			cout << "Rectangle's width  = " << getWidth() << endl;
			cout << "Rectangle's height = " << getHeight() << endl;
			cout << "Rectangle's area   = " << getArea() << endl;
		}	
};

int menu()  
{
	int choice;
	
	cout << endl << endl;
	cout << "==========[MENU]============" << endl <<endl;
	cout << "1. Add a shape" << endl;
	cout << "2. Print all shapes" << endl;
	cout << "3. Calculate total area" << endl;
	cout << "4. Exit" << endl << endl;
	
	cout << "Enter your choice => ";
	cin >> choice;
	cout << endl;
	
	return choice;
}

int main()
{
	
	int shapeType;
	Shape *newShape;
	int choice,count = 0;
	double totalArea;
	Shape *ArrayShape[5];

do{
	choice = menu();
	if(choice == 1){
				cout << "What type of shape you want to enter?\n";
				cout << "     1. Circle\n";
				cout << "     2. Rectangle\n\n";
				cout << "Your choice => ";
				cin >> shapeType;
				cout << endl;

				switch(shapeType){
					case 1:
						newShape = new Circle;
						newShape->read();
						ArrayShape[count++] = newShape;
						break;
					case 2:
						newShape = new Rectangle;
						newShape->read();
						ArrayShape[count++] = newShape;
						break;
				}

			}
			else if(choice == 2){
				for(int i = 0; i < count; i++){
					cout << "Shape #" << i+1 << endl;
					ArrayShape[i]->print();
					cout << endl;
				}
			}
			else if(choice == 3){
				totalArea = 0;
				for(int i = 0; i < count; i++){
					totalArea += ArrayShape[i]->getArea();
				}
				cout << "Total Area= " << totalArea << endl;
			}

		}while(choice != 4);

	
	return 0;
}
