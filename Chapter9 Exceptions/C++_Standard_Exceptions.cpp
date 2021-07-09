#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double *p;
	int count=0;
	int size=pow(2,20); // 1MB
	try{
		while(true){
			p=new double[size]; // An exception of bad_alloc will be thrown by the command new when there is not enough memory left.
			count++;
			cout<<"count = "<<count<<endl;
		}
	}
	catch(exception &e){
		cout<<"something bad happened! "<<e.what()<<endl;
	}
	return 0;
}
