// This program is meant to perform division only for positive numbers

#include <iostream>
using namespace std;

int main(){
	int n1,n2, num3;
	cout << "Enter two positive numbers => ";
	cin >> n1 >> n2;
	try
	{
		if (n2<=0)
			throw (0);
		else{   
			num3= n1/n2;
			cout << num3;
		}		
	}
	catch (int x){ 
		cout << "Cannot divide number with zero or less than zero";
	}
	return 0;
}
