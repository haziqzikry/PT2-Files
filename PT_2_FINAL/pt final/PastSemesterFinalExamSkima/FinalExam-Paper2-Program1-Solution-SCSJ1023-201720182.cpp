////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Final Exam, Paper 2 (Practical) 
// SOLUTION to Program 1
// Total Marks= 35 Marks
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>

using namespace std;

// Task 1: class Polygon (6 Marks)
class Polygon 
{  protected:
		int w, h;
		
	public:
		Polygon(int w=0, int h=0){
			this->w = w;
			this->h = h;
		}
		
		// Define the method display
		virtual void display() const  //2m
		{
			cout << "Generic polygon:" << endl;  //1m 			
		} 
		
		// Define the method calcArea
		virtual int calcArea() const //2m
		{
			return 0; //1m;
		} 
};

// Task 2: class Rectangle (9 Marks)

// Specify the class as a child of class Polygon
class Rectangle : public Polygon //2m
{  public:
		
		// Complete the definition of the constructor
		Rectangle(int width=0, int length=0)  
		{ w=width;  //1.5m
		  h=length; //1.5m
		}		
		
		/* // Alternative:
		Rectangle(int width=0, int length=0):Polygon(width, length) //3m 
		{}	
		*/

		// Complete the definition of the method display
		void display() const  
		{
			cout << "Rectangle:\n" 
				 << "\tWidth = "  << w // 1m
				 << ", Length = " << h // 1m
				 << endl; 
		}	
		
		// Complete the definition of the method calcArea
		int calcArea() const 
		{
			return w * h; //2m
		}
};

// Task 3: class Triangle (9 Marks)

// Specify the class as a child of class Polygon

class Triangle : public Polygon  //2m
{   public:
		Triangle(int width=0, int length=0)  
		{ w=base;   //1.5m
		  h=height; //1.5m
		}		
		
		/* // Alternative:
		Triangle(int base=0, int height=0):Polygon(base,height) // 3m
		{}
		*/

		//Redefine display function   
		void display() const
		{
			cout << "Triangle:\n" 
				 << "\tBase = "   << w // 1m
				 << ", Height = " << h // 1m
				 << endl; 
		}


		//Redefine calcArea function
		int calcArea() const 
		{
			return 0.5*w * h; // 2m
		}
};

int main()
{
  // Task 4: An array of pointers to polygons. (6 Marks)  
  const int SIZE = 4;      // The size of the array
  Polygon *polygons[SIZE] ={ //2m
    						  new Triangle(10, 20),  //1m
    						  new Rectangle(20, 20), //1m
    						  new Polygon(),         //1m
    						  new Rectangle(15, 10)  //1m
                           }; 

  // Task 5: Display the information of all polygons along with 
  //         their area and calculate the total area 
  //         of all the polygons.   (5 Marks)
  
  cout << fixed << setprecision(2);	
  int totalArea = 0;
  
  for (int i = 0; i < SIZE; i++)
  {
      cout << "Polygon #" << (i+1) << endl;
      
	  // Display the informations
      polygons[i]->display(); // 1.5m
      cout << "\tArea = " << polygons[i]->calcArea(); // 1.5m
	  cout << endl << endl;
	  
	  // Calcualte the total area
	  totalArea += polygons[i]->calcArea();  // 2m
  }
    
  cout << "The total area of all polygons = " << totalArea << endl;

  return 0;
}

