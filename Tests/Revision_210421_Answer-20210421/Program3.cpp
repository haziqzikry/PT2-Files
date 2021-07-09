// Program 3
#include<iostream>
using namespace std;

class Rectangle{
	private:
		int x1,y1; // bottom-left corner
		int x2,y2; // top-right corner
	public:
		
		Rectangle(){ x1=y1=x2=y2=0; } // The default constructor
		Rectangle(int a, int b, int c, int d){ // The constructor that sets the bottom-left and top-right corners
			x1=a; y1=b;
			x2=c; y2=d;
		}
		// Define a constructor to create a rectangle with the bottom-left corner (0,0) 
		// and the width and height set as w and h, respectively.
		Rectangle(int w, int h){ 
			x1=y1=0; 
			x2=w; y2= h;
		}
		// Define a constructor to create a square with the bottom-left corner (x, y), and the side length of s.
		Rectangle(int x, int y, int s){ 
			x1=x; y1=y; 
			x2 = x1 + s; y2 = y1 + s; 
		}
		// Define a member function (method) that determines the width of the rectangle.
		int getWidth() const{ return x2 - x1; }
		// Define a member function (method) that determines the height of the rectangle.
		int getHeight() const{ return y2 - y1; }
		friend void inputRectangle(Rectangle&);
}; // End of class

// Write the definition code for the function inputRectangle to read the coordinates of a rectangle from the keyboard.
void inputRectangle(Rectangle &r) {
	cout << "Enter the rectangle's corners (e.g., 1 1 3 3): ";
	cin >> r.x1 >> r.y1 >> r.x2 >> r.y2; 
}

int main(){
	// Declare an array to hold 4 objects of Rectangle, and initialize the array as follow:
	// the first element is a rectangle with bottom-left and top-right corners of (1,2) and (3,4), respectively.	
	// the second element is a rectangle with bottom-left corner at (0,0), and width is 5 and height is 10 .	
	// the third element is a square with bottom-left corner at (3,4), and the side length is 5
	Rectangle rects[4] = { Rectangle(1,2,3,4), Rectangle(5,10), Rectangle(3,4,5) };
	// Read the data for the fourth element of the array from the keyboard.
	inputRectangle(rects[3]) ;
	// Using a loop, calculate the total area of the rectangles and print the result.
	int sumArea = 0; 
	for (int i=0; i<4; i++){ 
		int area = (rects[i].getHeight())*(rects[i].getWidth());
		sumArea += area; 
	}
	cout << "Total area = " << sumArea << endl; //Area(1,2,3,4)=4 //Area(5,10)=50 //Area(3,4,5)=25 //Area(1,1,3,3)=4 //4+50+25+4=83
	return 0;
}

