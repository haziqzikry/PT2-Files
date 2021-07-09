#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string b = "testing";
    b.append ("Hello World" , 3,5);
    cout << b;
    return 0;
}