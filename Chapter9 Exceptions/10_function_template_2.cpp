#include <iostream>
#include <string>
using namespace std;

// function template
template <class T>
T times10(T num)
{
	return 10 * num;
}

int main(){
	int ival = 3;
	double dval = 2.55;
	cout << times10(ival) << endl; // displays 30 
	cout << times10(dval); // displays 25.5
	return 0;
}
