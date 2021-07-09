// Program 2
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){ 
	string w; // user input
	string r; // reversed word
	int cap; // number of capital letters
	cout << "Enter a word: ";
	cin >> w;
	
	// Answer for question
	cap = 0; 
	r = "";
	for (int i = 0; i < w.length(); i++){
		if (w[i] == toupper(w[i])) cap++; 
		r = w.substr(i, 1) + r;
	}
	cout << "Number of capital letters: " << cap << endl;
	cout << "The reversed word: " << r << endl;
	return 0;
}// end of main
