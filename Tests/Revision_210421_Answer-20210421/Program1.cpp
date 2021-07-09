//Program 1
#include <iostream>
using namespace std;

class Point{ 
	private:
		int x, y;
	public:
		Point(int _x=0, int _y=0) { x = _x; y = _y; }
		int getX() const { return x; }
		int getY() const { return y; }
		void input() { cin >> x >> y; }
		
		// Answer for question (1a)
		Point operator+(Point right){
			int _x = x + right.x;
			int _y = y + right.y;
			Point result(_x, _y);
			return result;
		}	
}; // end of class Point

// Answer for question (1b)
Point add(Point p1, Point p2){ 
	int x = p1.getX() + p2.getX();
	int y = p1.getY() + p2.getY();
	Point result(x, y); // Point result = p1 + p2;
	return result;
}

int main(){ 
	Point p, q, r;
	cout<<"Input 1 (e.g., key in 1 2)"<<endl;
	p.input();
	cout<<"Input 2"<<endl;
	q.input();
	// Answer for question (1c)
	r = p + q;
	r = add(p, q);
	cout<<"Result\n"<<r.getX()<<" "<<r.getY();
	return 0;
}// end of main
