
#include <iostream>



using namespace std;


class Engine{


string capacity;



int cylinder;



public:


//write class constructor (1 mark) 


Engine(string ca,int cy)
 {


capacity = ca;



cylinder = cy;



cout<<"Engine specifications have been set."<<endl;



}



void displayEngineSpecifications(){



cout<<" Capacity : "<<capacity<<" , Cylinder : "<<cylinder<<endl;



}



};



class Vehicle{



//Set accessibility type (1 mark) 



protected
:



string RegNum;



public:


Vehicle(string RegNum){


// Complete code below (1 mark) 


this->
RegNum=RegNum;


cout<<"This is the base class constructor."<<endl;


}


// Complete function prototype (1 mark) 


virtual void
 diplayInfo(){


cout<<"Base class function."<<endl;


}

};



// Complete class definition (1 mark)  


class Car: public Vehicle
{

protected:


string make;



double price;



// make composition with class Engine (1 mark) 



Engine
 vehicle_engine;


public:


// Complete constructor prototype (1 marks) 



Car(string make, double price, string RegNum, string capacity, int cylinder):Vehicle(RegNum),
vehicle_engine(capacity,cylinder)


{



this->make=make; 



this->price=price; 


}


void diplayInfo(){


cout<<"Make : "<<make<<" , Price : "<<price;


// Complete code below (1 mark)


vehicle_engine
.displayEngineSpecifications();



}



};



//Complete checkPrice function (1 marks) 



int checkPrice(int car_price)


{



if (car_price <= 0)



throw
 "Invalid car price & default price will be given\n";

else



return car_price;



}



int main()



{



double car_price;



cout<<"Enter car price : ";



cin>>car_price;



try{



checkPrice(car_price); 



}



// Complete code below (1 mark) 



catch(const char* msg){



cout << "Error: " <<msg;



car_price=100;



}



Vehicle *ptr;



Car C("Honda",car_price,"AA22","2500cc",6);



// Add appropriate code below (1 mark)



ptr=&C
;



ptr->diplayInfo();



return 0;


}
