//inheritance

#include <iostream>
using namespace std;

class Point {
private:
   int x, y;  // Private data members
 
public:
   Point(int x = 0, int y = 0); // Constructor with default arguments
   int getX() const;  // Getter
   void setX(int x);  // Setter
   int getY() const;
   void setY(int y);
   void setXY(int x, int y);
   void print() const;
};

// Constructor - The default values are specified in the declaration
Point::Point(int x, int y) : x(x), y(y) { }
 
// Getters
int Point::getX() const { return x; }
int Point::getY() const { return y; }
 
// Setters
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }
 
// Public Functions
void Point::setXY(int x, int y) { this->x = x; this->y = y; }
 
void Point::print() const {
   cout << "Point @ (" << x << "," << y << ")";
}

class MovablePoint : public Point { // MovablePoint is a subclass of Point
private:
   int xSpeed, ySpeed;
 
public:
   MovablePoint(int x, int y, int xSpeed = 0, int ySpeed = 0);
   int getXSpeed() const;
   int getYSpeed() const;
   void setXSpeed(int xSpeed);
   void setYSpeed(int ySpeed);
   void move();
   void print() const;
};

MovablePoint::MovablePoint(int x, int y, int xSpeed, int ySpeed)
      : Point(x, y), xSpeed(xSpeed), ySpeed(ySpeed) { }
 
// Getters
int MovablePoint::getXSpeed() const { return xSpeed; }
int MovablePoint::getYSpeed() const { return ySpeed; }
 
// Setters
void MovablePoint::setXSpeed(int xs) { xSpeed = xs; }
void MovablePoint::setYSpeed(int ys) { ySpeed = ys; }
 
// Functions
void MovablePoint::print() const {
   cout << "Movable";
   Point::print(); // Invoke base class function via scope resolution operator
   cout << " Speed=" << "(" << xSpeed << "," << ySpeed << ")";
}
 
void MovablePoint::move() {
   // Subclass cannot access private member of the superclass directly
   // Need to go thru the public interface
   Point::setX(Point::getX() + xSpeed);
   Point::setY(Point::getY() + ySpeed);
}

int main() {
   Point p1(4, 5);  // superclass
   p1.print();      // Point @ (4,5)
   cout << endl;
 
   MovablePoint mp1(11, 22); // subclass, default speed
   mp1.print();       // MovablePoint @ (11,22) Speed=(0,0)
   cout << endl;
   mp1.setXSpeed(8);
   mp1.move();
   mp1.print();       // MovablePoint @ (19,22) Speed=(8,0)
   cout << endl;
 
   MovablePoint mp2(11, 22, 33, 44);
   mp2.print();  // MovablePoint @ (11,22) Speed=(33,44)
   cout << endl;
   mp2.move();
   mp2.print();  // MovablePoint @ (44,66) Speed=(33,44)
   cout << endl;
   return 0;
}
