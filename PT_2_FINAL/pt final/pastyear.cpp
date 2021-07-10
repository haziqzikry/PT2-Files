#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
	public:
		Shape() {		}
		virtual double getArea()=0;
		virtual void read()=0;
		virtual void print()=0;
};

class Point
{
	private:
		double x;
		double y;
	public:
		Point()
		{
			x=0;
			y=0;
		}
		void set(double x, double y)
		{
			this->x=x;
			this->y=y;
		}
		double getX()
		{
			return x;
		}
		double getY()
		{
			return y;
		}
};

class Circle:public Shape
{
	private:
		double radius;
		Point Center;
	public:
		Circle()
		{
			radius=0;
		}
		double getArea()
		{
			return 3.1415*pow(radius,2);
		}
		void read()
		{
			double x,y;
			cout<<"Enter the center coordinates of the circle (x y) => ";
			cin>>x>>y;
			Center.set(x,y);
			cout<<"Enter the circle's radius=>";
			cin>>radius;
		}
		void print()
		{
			cout<<"Circle's center:\tX="<<Center.getX()<<"\tY="<<Center.getY()<<endl;
			cout<<"Circle's radius\t="<<radius<<endl;
			cout<<"Circle's area\t="<<getArea()<<endl<<endl;
		}
};

class Rectangle: public Shape
{
	private:
		double getWidth()
		{
			return abs(bottomRight.getX()-topLeft.getX());
		}
		double getHeight()
		{
			return abs(bottomRight.getY()-topLeft.getY());
		}
		Point topLeft;
		Point bottomRight;
	public:
		Rectangle() {		}
		double getArea()
		{
			return getWidth()*getHeight();
		}
		void read()
		{
			double x,y;
			cout<<"Enter the of top left corner coordinates of the rectangle (x y) => ";
			cin>>x>>y;
			topLeft.set(x,y);
			cout<<"Enter the of bottom right corner coordinates of the rectangle (x y) => ";
			cin>>x>>y;
			bottomRight.set(x,y);
		}
		void print()
		{
			cout<<"Rectangle's top left corner:\tX="<<topLeft.getX()<<"\tY="<<topLeft.getY()<<endl;
			cout<<"Rectangle's bottom right corner:\tX="<<bottomRight.getX()<<"\tY="<<bottomRight.getY()<<endl;
			cout<<"Rectangle's width\t= "<<getWidth()<<endl;
			cout<<"Rectangle's height\t="<<getHeight()<<endl;
			cout<<"Rectangle's area\t="<<getArea()<<endl<<endl;
		}
};

int main()
{
	Shape *shape[100];
	int counter=0;
	int choice=-99;
	while(choice!=4)
	{
		cout<<"==========[MENU]=========="<<endl<<endl;
		cout<<"1. Add a shape"<<endl;
		cout<<"2. Print all shapes"<<endl;
		cout<<"3. Calculate total area"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Enter your choice =>";
		cin>>choice;
		cout<<endl;
	
		switch(choice)
		{
			case 1:	cout<<"What type of shape you want to enter?"<<endl;
					cout<<"1. Circle"<<endl;
					cout<<"2. Rectangle"<<endl<<endl;
					cout<<"Your choice => ";
					int choice1;
					cin>>choice1;
					if(choice1==1)
					{
						shape[counter]=new Circle;
						shape[counter]->read();
						counter++;
					}
					else if(choice1==2)
					{
						shape[counter]=new Rectangle;
						shape[counter]->read();
						counter++;
					}
					cout<<endl;
					break;
					
			case 2:	for(int i=0;i<counter;i++)
					{
						cout<<"Shape #"<<i+1<<endl;
						shape[i]->print();
					}
					break;
			
			case 3:	double totalArea=0;
					for (int i=0;i<counter;i++)
					{
						totalArea+=shape[i]->getArea();
					}
					cout<<"Total Area= "<<totalArea<<endl<<endl;
					break;
			
		}
	}
	return 0;
}
