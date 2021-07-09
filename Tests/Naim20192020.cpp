//Muhammad Naim bin Abdul Jalil
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

class Person{
    private :
        string name;
        string NRIC;
        double height;
        double weight;
        double BMI;
        string weightStatus;

    public :
        Person(string n = "", double h = 0.0, double w = 0.0, string ic = ""){
            name = n;
            NRIC = ic;
            height = h;
            weight = w;
            calcBMI();
        }

        string getName() const {return name;}
        string getStatus(){
            if (BMI < 18.5)
                return "underweight";
            else if (BMI < 25)
                return "normal";
            else if (BMI < 30)
                return "overweight";
            else
                return "obese";  
        }

        string getRisk() const{
            if (BMI < 18.5)
                return "a risk of nutritional deficiency diseases and osteoporosis";
            else if (BMI < 25)
                return "low health risk";
            else if (BMI < 30)
                return "moderate health risk";
            else
                return "high health risk";
        }

        void calcBMI(){
            BMI = weight / pow(height,2);
            weightStatus = getStatus();
        }

        void readInput(){
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

        bool operator==(const Person &p){
            if (this->weightStatus == p.weightStatus)
                return true;
            else
                return false;
        }

        friend void dispInfo(const Person &);
        friend ostream & operator<< (ostream &,const Person &);
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

ostream & operator<< (ostream &out, const Person &p){
    out << "Hello, " << p.name << endl;
    dispInfo(p);
    out << endl;
    out << fixed << setprecision(2);
    out << "Your height is " << p.height << " meter\n";
    out << "Your weight is " << p.weight << " kg\n";
    out << "Your BMI is " << p.BMI << endl;
    out << "Your weight status is " << p.weightStatus << endl;
    out << "You have " << p.getRisk();
    return out;
}

int main(){
    Person p1;
    Person p2("Anis Hashim", 1.5, 50);

    cout << "BMI Calculator\n\n";
    cout << "<<< Input >>>\n";
    p1.readInput();
    
    cout << "\n<<< Output >>>\n";
    cout << p1;

    if (p2 == p1)
        cout << "\n\n**Note: " << p1.getName() << " and " << p2.getName() << " have same weight status.";
    else
        cout << "\n\n**Note: " << p1.getName() << " and " << p2.getName() << " have different weight status.";
    return 0;
}
