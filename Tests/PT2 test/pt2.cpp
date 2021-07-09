#include <iostream>
#include "PT2.h"
#include <string>
using namespace std;

//Class Definition

void PT2::getName(string g)
{
	name=g;
}

void PT2::getA(int n)
{
	a=n;
}

int PT2::getC()
{
	return a;
}

string PT2::getD()
{
	return name;
}

int main()
{
	PT2 p;
	p.getName("Ali");
	p.getA(1);
	cout<<p.getC()<<endl;
	cout<<p.getD();
	return 0;
}
