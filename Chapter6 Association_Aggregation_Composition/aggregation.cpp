#include <iostream>
#include <cstring>
using namespace std;

class Address {
	public:
		int houseNo;
		string city, state;
		Address(int hno, string city, string state)
		{ 
			this->houseNo = hno;
			this->city = city;
			this->state = state;
		}
};

class Person {
	private:
		Address* address;
	public:
		string name;
		Person(string name, Address* address)
		{
			this->name = name;
			this->address = address;
		}
		void display()
		{
			cout<<name<<"\t"<<address->houseNo<<", "<<address->city<<", "<<address->state<<endl;
		}
};

int main() {
	Address add1= Address(28,"SC","JHB");
	Person p1 = Person("Dr. PPL1",&add1);
	Person p2 = Person("Prof. PPL2",&add1);
	p1.display();
	p2.display();
	return 0;
}
