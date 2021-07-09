#include <iostream>
using namespace std;

class Rectangle { // class 1
	int width, height;
	public:
		Rectangle(){
			width=0;
			height=0;
		}
		Rectangle(int w = 1, int h = 1):width(w),height(h){} 
		friend void display(Rectangle &); //fiend
		//int compare(Square &);
};
void display(Rectangle &r) {
	cout << "Rectangle: " << r.width * r.height << endl;
}

int main () {
	Rectangle rect(5,10);
	display(rect);
	//Square sq;
	//sq.display();
	//rect.compare(sq);
	return 0;
}
