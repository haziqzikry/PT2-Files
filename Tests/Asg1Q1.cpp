#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Name {
	string firstName, lastName;
	
	public:
		Name(string, string);
		string getFullName();
};

class Address {
	string street, city, state;
	int postcode;
	
	public:
		Address(string, string, int, string);
		string getAddress();
};

class HealthInfo {
	int height, weight;
	
	public:
		HealthInfo (int, int);
		int getHeight();
		int getWeight();
};

class Doctor {
	string staffId;
	Name name;
	
	public:
		Doctor(string, string, string);
		string getFullName();
};

class Patient {
	string patientID, gender;
	int age;
	Name name;
	HealthInfo pHealth;
	Doctor *doctor;
	Address *address;
	
	public:
		static int numPatient;
		Patient(string="", string="", string="", string="", int=0, int=0, int=0, Address *a=NULL);
		string getPatientID();
		int getWeight();
		int getHeight();
		string getFullName();
		string getGender();
		int getAge();
		Address* getAddress();
		Doctor* getDoctor();
		void attendBy(Doctor *);
};

//Member function definition for class Name
Name::Name(string fn, string ln): firstName(fn), lastName(ln) {}

string Name::getFullName() {
	string full = firstName + " ";
	full += lastName;
	return full; 
}
		
//Member function definition for class Address
Address::Address(string st, string ct, int pc, string s): street(st), city(ct), postcode(pc), state(s) {}

string Address::getAddress() {
	string add = street + ", ";
	add += to_string(postcode);
	add += " ";
	add += state;
	add += ", ";
	add += city;
	return add;
}

		
//Member function definition for class HealthInfo
HealthInfo::HealthInfo (int h, int w): height(h), weight(w) {}
		
int HealthInfo::getHeight() {
	return height;
}

int HealthInfo::getWeight() {
	return weight;
}


//Member function definition for class Doctor
Doctor::Doctor(string s, string fn, string ln): staffId(s), name(fn, ln) {}

string Doctor::getFullName() {
	return name.getFullName();
}


//Member function definition for class Patient
int Patient::numPatient = 0;
 
Patient::Patient(string p, string g, string fn, string ln, int ag, int w, int h, Address *add): name(fn, ln), pHealth(w, h) {
	patientID = p;
	gender = g;
	age = ag;
	address = add;
	if (add != NULL) {
		numPatient++;
		cout << "Patient: " << name.getFullName() << " has been added!" << endl;
	}
		
}

string Patient::getPatientID() {
	return patientID;
}

int Patient::getWeight() {
	return pHealth.getWeight();
}

int Patient::getHeight() {
	return pHealth.getHeight();
}

string Patient::getFullName() {
	return name.getFullName();
}

string Patient::getGender() {
	return gender;
}

int Patient::getAge() {
	return age;
}

Address* Patient::getAddress() {
	return address;
}

Doctor* Patient::getDoctor() {
	return doctor;
}

void Patient::attendBy(Doctor *d) {
	doctor = d;
}

//This function display the record of the patient
void displayRecord(Patient pL[]) {
	cout << "\nPatient Record Management System" << endl
         << "================================" << endl << endl
         << setw(4) << "No" << setw(10) << "PatientID" << setw(15) << "Name" << setw(5) << "Age" << setw(8) << "Gender" 
		 << setw(37) << "Address" << setw(8) << "Height" << setw(8) << "Weight" << setw(20) << "Attend By" << endl
         << setw(4) << "--" << setw(10) << "---------" << setw(15) << "----" << setw(5) << "---" << setw(8) << "------" 
		 << setw(37) << "-------" << setw(8) << "------" << setw(8) << "------" << setw(20) << "---------" << endl;
	
    for(int i=0; i < Patient::numPatient; i++) 
         cout << setw(4) << (i+1) << setw(10) << pL[i].getPatientID() << setw(15) << pL[i].getFullName() << setw(5) << pL[i].getAge() 
		 	  << setw(8) << pL[i].getGender() << setw(37) << pL[i].getAddress()->getAddress() << setw(8) << pL[i].getHeight() 
			  << setw(8) <<  pL[i].getWeight() << "Dr. " << pL[i].getDoctor()->getFullName() << endl;

    cout << "\n-------------------" << endl;
    cout << "Total Patients: " << Patient::numPatient << endl;
}

int main() {
    
    Address add1("Jalan Pahlawan", "Skudai", 81300, "Johor");
    Address add2("Jalan Flora", "Skudai", 81300, "Johor");
    Address add3("Jalan Bakti", "Skudai", 81300, "Johor");
    Address add4("Jalan Mutiara", "Skudai", 81300, "Johor");
    Address add5("Jalan Indah", "Skudai", 81300, "Johor");

    Doctor d1("S0001", "Kumar", "Moorthy");
    Doctor d2("S0002", "Stephen", "Koh");

    Patient p1("P0001", "Male", "Akmal", "Adnan", 25, 180, 82, &add1);
    Patient p2("P0002", "Male", "Syafiq", "Yusof", 24, 186, 80, &add2);
    Patient p3("P0003", "Female", "Mei Ling", "Koh", 30, 168, 45, &add3);
    
	//Define an array to store objects of Patient
	Patient *patientList = new Patient[Patient::numPatient];

    p1.attendBy(&d1);
    p2.attendBy(&d2);
    p3.attendBy(&d1);

    patientList[0] = p1;
    patientList[1] = p2;
    patientList[2] = p3;

	cout << left;
    displayRecord(patientList);   

	return 0;
}

 
