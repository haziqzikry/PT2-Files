// This program is meant to perform division only for positive numbers

#include <iostream>
using namespace std;

double positiveDivision(double n1, double n2){
	if (n1 <= 0){
		cout << "Error**: The first number must be a positive value" << endl;
		return -1; // -1 indicates the first number is a non-positive
	}
	
	if (n2 <= 0){
		cout << "Error**: The second number must be a positive value" << endl;
		return -2; // -2 indicates the second number is a non-positive
	}
	
	return n1 / n2;  // This the core task of this function	
}

int main(){
	double d, n1,n2;
	
	cout << "Enter two positive numbers => ";
	cin >> n1 >> n2;

	d = positiveDivision(n1,n2);
	
	if (d>0){
		cout << "Division Result = " << d << endl;
	}else{
		cout << "Cannot perform division" << endl;
	}

	return 0;
}


