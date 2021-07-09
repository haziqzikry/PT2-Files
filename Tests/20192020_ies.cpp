#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

class Person{
    private:
        string name;
        string nric;
        double height,weight,bmi;
        string statweight;
    public:
        Person(){
            name = "";
            nric = "";
            height = 0.0;
            weight = 0.0;
        }

        Person(string n, double h, double w){
            name = n;
            height = h;
            weight = w;
            bmi = calcBMI();
            statweight = getStatus();

        }

        string getName(){
            return name;
        }
        
        string getStatus(){
            if (bmi < 18.5)
                statweight = "Underweight";
                else if(bmi >= 18.5 && bmi < 25)
                    statweight = "Normal";
                    else if(bmi >= 25 && bmi < 30)
                        statweight = "Overweight";
                        else
                            statweight = "Obese";
            return statweight;
        }

        string getRisk(){
            string risk;
            if (bmi < 18.5)
                risk = "Risk of nutritional deficiency diseases and osteoporosis";
                else if(bmi >= 18.5 && bmi < 25)
                    risk =  "Low risk";
                    else if(bmi >= 25 && bmi < 30)
                        risk = "Moderate risk";
                        else
                            risk = "High risk";
            return risk;
        }

        double calcBMI(){
            return bmi = weight / pow(height,2);
        }

        void readInput(){
            cout << "<<< INPUT >>>\n";
            cout << "Name : ";
            getline(cin, name);
            cout << "NRIC Number (without hyphen'-) : ";
            getline(cin, nric);
            cout << "Height (in meter) : ";
            cin >> height;
            cout << "Weight (in kg) : ";
            cin >> weight;
        }

        bool operator==(const Person &obj){
            return (statweight == obj.statweight);
        }

        friend string dispInfo(const Person &);
        friend ostream &operator<<(ostream &out, Person &obj);
};

string dispInfo(const Person &p){
    string digit;
    digit.assign(p.nric,0,2);
    int year = atoi(digit.c_str());
    int age;
    if(year > 20){
        age = 1900 + year;
        age = 2020 - age;
    }
        else{
            age = 2000 + age;
            age = 2020 - age;
        }
    ostringstream ss;
    ss << age;
    string syear = ss.str();

    digit.assign(p.nric,11);
    int gen = atoi(digit.c_str());
    string gender;
    if (gen%2 == 0)
        gender = "Man";
        else
            gender = "Woman";
    string final;
    final = "Your are " + syear + "year old " + gender;

    return final;

}

ostream &operator<< (ostream &out, Person &obj){
    out << "<<< OUTPUT >>>\n";
    out << "Hello, " << obj.name << endl;
    out << dispInfo(obj) << endl;
    out << "Your height is " << obj.height << "meter\n";
    out << "Your weight is " << obj.weight << "kg\n";
    out << "Your BMI is " << obj.bmi << endl;
    out << "Your weight status is " << obj.getStatus() << endl;
    out << "Your have a " << obj.getRisk() << endl;
}

int main(){
    system("CLS");
    Person p1;
    Person p2("Anis Hashim", 1.5, 50);

    cout << "BMI Calculator\n";
    p1.readInput();
    cout << endl;

    cout << p1 << endl;
    if(p1 == p2)
        cout << "**Note : " << p1.getName() << " and " << p2.getName() << " have same weight status.\n";
        else
            cout << "**Note : " << p1.getName() << " and " << p2.getName() << " have different weight status.\n";
}
