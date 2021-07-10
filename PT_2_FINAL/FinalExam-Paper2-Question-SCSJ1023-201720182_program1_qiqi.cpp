////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Final Exam, Paper 2 (Practical), Question 1
// Template file
//
// program1.cpp
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>

using namespace std;

// Task 1: class Polygon
class Polygon 
{  protected:
		int w, h;
		
	public:
		Polygon(int w=0, int h=0){
			this->w = w;
			this->h = h;
		}
		
		// Define the method display
		virtual void display() const{
			cout << "Generic polygon:\n";
		}

		// Define the method calcArea
		//____________________________
		virtual int calcArea() const{
			return 0;
		}
};

// Task 2: class Rectangle

// Specify the class as a child of class Polygon

class Rectangle : public Polygon
{  public:
		
		// Complete the definition of the constructor
		Rectangle(int width=0, int length=0) : Polygon(width,length)
		{
			
		}
		
		// Complete the definition of the method display
		void display() const  
		{
			cout << "Rectangle:\n" 
				 << "\tWidth  = " << w
				 << ", Length = " << h
				 << endl; 
		}	
		
		// Complete the definition of the method calcArea
		int calcArea() const 
		{
			return w*h;
		}
};

// Task 3: class Triangle

// Specify the class as a child of class Polygon

class Triangle : public Polygon
{   public:

		// Complete the definition of the constructor
		Triangle(int base=0, int height=0) : Polygon (base, height)
		{
			
		}

		// Complete the definition of the method display
		void display() const
		{
			cout << "Triangle:\n" 
				 << "\tBase = " << w
				 << ", Height = " << h
				 << endl; 
		}

		// Complete the definition of the method calcArea
		int calcArea() const 
		{
			return (w*h)/2;
		}
};

int main()
{
  // Task 4: An array of pointers to polygons.
  const int SIZE = 4;      // The size of the array
  
  // Declare the array and fill in it with the polygons.
  //____________________________
  Polygon *p [SIZE]= { new Triangle (10,20), new Rectangle (20,20), new Polygon , new Rectangle (15,10)};

  
  // Task 5: Display the polygons and calculate the total area.
  
  cout << fixed << setprecision(2);	
  int totalArea = 0;
  
  for (int i = 0; i < SIZE; i++)
  {
      cout << "Polygon #" << (i+1) << endl;
      
	  // Display the polygon's information
      //____________________________
	  p[i] ->display ();
      
      // Display the polygon's area
      //____________________________
	 cout << "\tArea = " << p[i]->calcArea();

	  
	  // Calculate the total area
	  //____________________________
	  totalArea += p[i]->calcArea();
	  cout << endl;
	  
	  cout << endl << endl;
  }
    
  cout << "The total area of all polygons = " << totalArea << endl;

  return 0;
}

