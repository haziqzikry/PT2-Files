#include <iostream>
using namespace std;

class Rectangle{
	private:
		double width, length;
	public:
		//exception class -  thrown as an exception by a member function
		class NegativeSize{ }; // - empty class declaration
		
		// default constructor 
		Rectangle(){
			width=0.0;
			length=0.0;
		}
		// mutator functions
		void setWidth(double w){
			if(w>=0)	width=w;
			else		throw NegativeSize();
		}
		void setLength(double l){
			if(l>=0)	length=l;
			else		throw NegativeSize();
		}
		// accessor functions
		double getWidth() const{
			return width;
		}
		double getLength() const{
			return length;
		}
		double getArea() const{
			return width*length;
		}
};

int main(){
	double wid, len;

	//create rectangle object
	Rectangle rec;

	cout<<"Enter the rectangle's width: ";
	cin>>wid;
	cout<<"Enter the rectangle's length: ";
	cin>>len;
	
	// store these in the Rectangle object rec
	try{
		rec.setWidth(wid);
		rec.setLength(len);
		cout<<"The rectangle's area: "<<rec.getArea()<<endl;
	}
	catch(Rectangle::NegativeSize){
		cout<<"Error: A negative value was entered.\n";
	}
	return 0;
}
