#include <iostream>
#include <conio.h>
using namespace std;
const double PI = 3.14159;
/** @class Sphere Sphere.h "Sphere.h"
 * Definition of a class of Spheres. */
class Sphere
{
public:
   Sphere();
   Sphere(double initialRadius);
   ~Sphere(){
     cout<<"detroy\n";
   }
   void setRadius(double newRadius);
   double getRadius() const;
   double getDiameter() const;
   double getCircumference() const;
   double getArea() const;
   double getVolume() const;
   void displayStatistics() const;
private:
   /** The Sphere's radius */
   double theRadius;
};  // end Sphere
Sphere::Sphere() : theRadius(1.0)
{
 //theRadius=1.0;
}  // end default constructor
Sphere::Sphere(double initialRadius)
{
   if (initialRadius > 0)
      theRadius = initialRadius;
   else
      theRadius = 1.0;
}  // end constructor
void Sphere::setRadius(double newRadius)
{
   if (newRadius> 0)
      theRadius = newRadius;
   else
      theRadius = 1.0;
}  // end setRadius
double Sphere::getRadius() const
{
   return theRadius;
}  // end getRadius
double Sphere::getDiameter() const
{
   return 2.0 * theRadius;
}  // end getDiameter
double Sphere::getCircumference() const
{
   return PI * getDiameter();
}  // end getCircumference
double Sphere::getArea() const
{
   return 4.0 * PI * theRadius * theRadius;
}  // end getArea
double Sphere::getVolume() const
{
   double radiusCubed = theRadius * theRadius * theRadius;
   return (4.0 * PI * radiusCubed)/3.0;
}  // end getVolume
void Sphere::displayStatistics() const
{
   cout << "\nRadius = " << getRadius()
        << "\nDiameter = " << getDiameter()
        << "\nCircumference = " << getCircumference()
        << "\nArea = " << getArea()
        << "\nVolume = " << getVolume() << endl;
}  // end displayStatistics
int main()
{
   Sphere unitSphere;         // invoke constructor without parameter, radius is 1.0
   Sphere mySphere(5.1);      // invoke constructor with parameter, radius is 5.1
   cout <<  "\nInformation for the first sphere : "  << endl;
   unitSphere.displayStatistics();
   cout <<  "\nInformation for the second sphere : "  << endl;
   mySphere.displayStatistics();
   mySphere.setRadius(4.2);   // resets radius to 4.2
   cout <<  "\nNew diameter for mysphere = " << mySphere.getDiameter() << endl;
   getch();
   return 0;
}  // end main
