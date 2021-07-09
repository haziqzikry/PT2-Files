#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
class Plane
{
 private:
  string airline, code, model, route;

 public:
  Plane(string airline ="Malaysia Airline", string code="MH720", string model="Boeing 737-800", string route="CGK - KUL"); // constructor

  ~Plane() // destructor (inline)
  {
   cout << "\n\nAircraft name by " << airline << " " << code << ", model: " << model << " has been erased from system.";
   getch();
  }
  void print();
};

Plane::Plane(string a, string c, string m, string r) // constructor implementation
{
 airline = a;
 code = c;
 model =  m;
 route = r;
}
void  Plane::print()
{
 cout << "Aircraft Information: \nAirline" << airline << " " << code << " \nModel: " << model<<"\nRoute: "<<route<<endl<<endl;
}
int main()
{
 Plane plane1;
 plane1.print();
 Plane plane2("Garuda Indonesia", "GA154", "Airbus A330-343", "CGK - BTH");
 plane2.print();
 cout<<"Instruction: Click Enter from your Keyboard until the end";
 return 0;
}
