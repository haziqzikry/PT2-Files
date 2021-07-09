#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Complex_Number
{
int i, j;
public:
Complex_Number(int a, int b){
i = a ;
j = b ; }
Complex_Number operator+(Complex_Number c){
i = this->i + c.i;
j = this->j + c.j;
return *this; }

void display(){
cout<<i<<" + i"<<j<<" , ";}
};
int main() {
Complex_Number c1(1,1), c2(2,2);
c2 = c1 + c2;
c1.display();
c2.display();
return 0;
}