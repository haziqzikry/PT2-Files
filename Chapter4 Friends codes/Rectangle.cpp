#include <iostream>
using namespace std;

class Square { //class 1
	int side;
	public:
		Square(int s = 1):side(s){} 
		void display() {
			cout << "Square: " << side * side << endl;
		}
		friend class Rectangle;
};

class Rectangle { // class 2
	int width, height;
	public:
		Rectangle(int w = 1, int h = 1):width(w),height(h){} 
		friend void display(Rectangle &); //friend
		int compare(Square &);
};

int Rectangle::compare(Square &sr){
	width=height=sr.side;
	cout << "Square:" <<width<<" and "<<height<<endl;
}

void display(Rectangle &r) {
	cout << "Rectangle: " << r.width * r.height << endl;
}

int main () {
	Rectangle rect(5,10);
	display(rect);
	Square sq;
	sq.display();
	rect.compare(sq);
	return 0;
}
