//pointers
#include <iostream>
using namespace std;

int main(){
	cout<<"Pointers\n--------"<<endl;
	int i=10;
	cout<<"int i=10;\n";
	cout<<"    i: "<<i<<endl; //10
	cout<<"    &i: "<<&i<<endl; //address of i
	int *iptr = &i;
	cout<<"int *iptr = &i;\n";
	cout<<"    iptr: "<<iptr<<endl; //address of i
	cout<<"    *iptr: "<<*iptr<<endl;//10
	return 0;
}
