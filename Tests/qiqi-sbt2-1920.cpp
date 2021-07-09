#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace std;

class Person{

    private:
        string name, NRIC;
        string weightStatus;
        double weight, height,BMI;
    public:

    Person (string n = "",double h= 0.0, double w = 0.0, string ic = "")
            {
                name = n;
                height = h;
                weight =  w;
                NRIC = ic;
                calcBMI ();
                       
            }


        string getName() const {return name;};
        string getStatus() {
           if (BMI < 18.5)
                return "Underweight" ;
            else if (BMI >= 18.5 && BMI < 25.0)
                return "Normal";
            else if (BMI >= 25 && BMI < 30.0)
               return "Overweight";
             else 
                return "Obese";
           }

        string getRisk() const{
            if (BMI < 18.5)
                return "Risk of nutritional deficiency diseases and osteoporosis" ;
            else if (BMI >= 18.5 && BMI < 23.0)
                return "Low risk";
            else if (BMI >= 23 && BMI < 27.5)
                return "Moderate risk";
             else 
                return "High risk";
            }
        
        void calcBMI ()
        {
           BMI =  weight/(height*height);
           weightStatus = getStatus();
        }

        void readInput (){
            cout<<"<<<< Input >>>>\n";
            cout << "Name: ";
            getline(cin, name);
            cout << "NRIC Number (without hyphen'-'): ";
            cin >> NRIC;
            cout << "Height (in meter): ";
            cin >> height;
            cout << "Weight (in kg): ";
            cin >> weight;  
            calcBMI(); 
        }

        bool operator== (const Person& rhs){
           if (this ->weightStatus == rhs.weightStatus)
                return 1;
            else
                return 0;
            
        }

        friend void dispInfo(const Person &);
        
        friend ostream &operator<<(ostream &, const Person &) ;
                
      
};
        void dispInfo(const Person &p){

        string year(p.NRIC, 0,2);
        string gender(p.NRIC, 11, 1);
        int age;
        if(atoi(year.c_str()) > 20)
            age = 2020 - (1900 + atoi(year.c_str()));
        else
            age = 20 - atoi(year.c_str());
        
        if(atoi(gender.c_str())%2 == 0)
            cout <<  "You are " << age << " year old woman";
        else
            cout << "You are " << age <<  " year old man";

}

    ostream &operator<<(ostream &output,const Person &obj) {
        output << "\n<<< Output >>>" <<"\nHello, " << obj.name <<endl;
        dispInfo(obj);
        output << fixed << setprecision(2);
        output  << "\nYour height is "<<obj.height<<" meter"<<"\nYour weight is "<<obj.weight<<" kg"<<"\n";
        output << "Your BMI is " << obj.BMI << endl;
        output << "Your weight status is " << obj.weightStatus << endl;
        output << "Yo have " << obj.getRisk () << endl;
        return output;          
      }
int main ()
{
    Person p1;
    Person p2("Anis Hashim", 1.5,50);
    cout << "BMI Calculator" << endl << endl;
    p1.readInput();

    cout << p1;

    if(p2 == p1)
    {
        cout<<"\n***Note: "<<p1.getName()<<" and "<<p2.getName()<<" have same weight status.\n";
    }
    else
    {
        cout<<"\n***Note:"<<p1.getName()<<" and "<<p2.getName()<<" have different weight status.\n";
    }
    return 0;
}