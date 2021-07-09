// This program is meant to perform division only for positive numbers
//using try....catch method

#include <iostream>
using namespace std;

double positiveDivision(double n1, double n2){
	if (n1 <= 0) throw -1; // -1 indicates the first number is a non-positive
	if (n2 <= 0) throw -2; // -2 indicates the second number is a non-positive
	
	return n1 / n2;  // This the core task of this function	
}

int main(){
	double d, n1,n2;
	
	cout << "Enter two positive numbers => ";
	cin >> n1 >> n2;

	try{
		d = positiveDivision(n1,n2);
		cout << "Division Result = " << d << endl;
	}
	catch (int e){
		if (e==-1) 
		  cout << "Error**: The first number must be a positive value" << endl;
		else if (e==-2) 
		   cout << "Error**: The second number must be a positive value" << endl;
		cout << "Cannot perform division" << endl;
	}
	
	return 0;
}


