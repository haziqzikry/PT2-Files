#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;
    cout << "name: " << name << endl;

    string myName("Abu Bakar");
    cout << "myName(Abu Bakar): " << myName << endl;

    string yourName(myName);
    cout << "yourName(myName): " << yourName << endl;

    string aName(myName,5);
    cout << "aName(myName,5): " << aName << endl;

    string newName(myName,0,3);
    cout << "newName(myName,0,3): " << newName << endl;

    string repeat(30, '*');
    cout << "repeat(30, '*'): " << repeat << endl;

    return 0;
}
