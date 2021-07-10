////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Final Exam, Paper 2 (Practical), Question 2
// Template file
// 
// program2.cpp
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

// The class Person is FULLY given
// Do not change anything for this class
class Person
{ 
	protected:
		string name;
	public:
		Person(string name=""){ setName(name); }
		string getName() const{return name;}
		void setName(string name) {this->name = name;}
};


class Doctor : public Person
{ 
	string department;
	public:
		Doctor(string n="",string d="") : Person (n) // n is doctor's name,  d is department
		{
			department = d;
		}
		string getDepartment(){
			return department;
		}
};

class Guardian : public Person
{  
	string phone;
   public:
		Guardian(string n="", string p="") : Person (n) // n is guardian's name,  p is phone number
		{
			setPhone(p);
		}     

		string getPhone(){
			return phone;
		}  

		void setPhone(string p){
			phone =p;
		}
};


class Patient : public Person
{   
	string illness;
	Doctor *doc;
	Guardian guardian;

	public:
		Patient(string pn="", string pi="",   // patient's name and the illness
		        string gn="", string gp="" ) // guardian's name and phone number
				: guardian (gn, gp), Person (pn) 
		{     
			illness = pi;
			doc = NULL; 
	    }
	   
		virtual void print() const
		{          
			cout << "Patient's Name   :" << name << endl;
			cout << "Illness          :" << illness << endl;
			cout << "Guardian's Name  :" << guardian.getName() << endl;   
			cout << "Guardian's Phone :" << guardian.getPhone() << endl;  
			
			if(doc != NULL)
			{
				cout << "Doctor's Name    :" << doc->getName() << endl;
				cout << "Doctor's Dept.   :" << doc->getDepartment() << endl;
			}
			else
				cout << " *** No doctor assigned yet *** " << endl; 
	    }
		
		void assignDoctor (Doctor * doc){
			this-> doc = doc;
		}
};

class Outpatient : public Patient
{   
	string diagnosis;
	public:
		Outpatient( string pn="", string pi="",    // patient's name and illness
		            string gn="", string gp="",    // guardian's name and phone number
					string pdiagnosis="")          // diagnosis type
					: Patient (pn, pi, gn, gp)
        { 
			diagnosis = pdiagnosis;
		}					
					
		void print() const
		{  	
		    cout << "Patient Type:  OUTPATIENT " << endl;
			cout << "Diagnosis   :  "            << endl;
			cout << endl;
		} 		
};

class Inpatient : public Patient
{    
	string ward;
	public:
		Inpatient( string pn="", string pi="",    // patient's name and illness
		           string gn="", string gp="",    // guardian's name and phone number
				   string pward="")               // patient's ward 
				   : Patient (pn,pi,gn,gp)
        { 
			ward = pward;
		}					

		void print() const
		{   
			cout << "Patient Type:  INPATIENT "<< endl;
			cout << "Ward        :  "          << ward <<  endl;
			cout << endl;

			Patient:: print();
		} 		
};


// The menu function is fully given
int menu()
{
	cout << endl;
	cout << "========== Menu ==========" << endl;
	cout << "1. List Doctors"   << endl;
	cout << "2. List Patients" << endl;
	cout << "3. Assign Doctor"  << endl;
	cout << "4. Exit"  << endl;
	cout << endl;
	
	int choice;
	cout << "Choose an operation [1-4] => ";
	cin >> choice;
	
	cin.ignore();
	cout << endl;
	
	return choice;
}

int main()
{
	const int NDOC = 2;  // Number of of doctor. 
	const int NPATIENT   = 3;  // Number of patients. 
	
	// For convenience (for copy-and-paste purposes), the data of doctors and patients 
	//  are given at the bottom of this program.
	Doctor *d[NDOC] = {new Doctor("Dr. Ramli", "ICU"), new Doctor("Dr. Kamariah", "Radiology")};
	Patient *p[NPATIENT] = {new Outpatient("Rozita", "Sprained ankle", "Salleh", "4466", "X-ray"),
							new Inpatient("Nurdiana", "Respiratory failure", "Jalil", "7731", "ICU 101"),
							new Outpatient("Ali", "Coronary artery", "Bakar", "1234", "CT Scan")};
	
	// The program structure regarding the menu operation is given
	int c = menu();
	
	while (c!=4){
		
		switch (c){
			case 1: // List Doctors
				for (int i = 0; i < NDOC; i++)
					cout <<"Doctor's Name: " <<  d[i]->getName() << "\t"        
					     <<"Department: "   <<  d[i]->getDepartment() << endl;

				break;

			case 2: // List Patients

				for(int i = 0; i < NPATIENT; i++){
					cout << "Patient #" << i+1 << endl;
					p[i]->print();
					cout << endl;
				}
				break;

			case 3:  // Assign Doctor
				     // The operation regarding getting inputs from the user is given
				     // You must use the exception handling strategy 
				     // to handle the "out of range" error 
				
				int pIndex;   // The array index of the patient to be assigned with a doctor.
				int dIndex;   // The array index of the doctor to assign to the patient.
				
				cout <<"Enter the patient index and doctor index => ";
				cin >> pIndex >> dIndex;
				try{
					if(pIndex < 0 || pIndex >= NPATIENT || dIndex < 0 || dIndex >= NDOC)
						throw "Index is out of range";
					else
						p[pIndex]->assignDoctor(d[dIndex]);
				}
				catch(const char *exceptionString){
					cout << "** Error: " << exceptionString << endl;
				}
				break;
		}
		
		c = menu();
	}
	
	return 0;
}

/*

Doctors and patients data

Doctors:
name and department

Dr. Ramli , ICU 
Dr. Kamariah ,  Radiology

Patients:
name, illness,guardian'name, guardian's phone, diagnosis, ward number, and patient type

Rozita   , Sprained ankle , Salleh , 4466, X-ray , Outpatient
Nurdiana , Respiratory failure , Jalil, 7731, ICU 101, Inpatient
Ali , Coronary artery , Bakar , 1234 ,CT Scan, Outpatient 

*/
