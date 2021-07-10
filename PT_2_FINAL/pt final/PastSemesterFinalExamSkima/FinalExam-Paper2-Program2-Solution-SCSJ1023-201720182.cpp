////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Final Exam, Paper 2, Question 2  (Problem Solving)
// Prepared by: Jumail Bin Taliba (jumail@utm.my)
// 2 April 2018, Created on
// 5 April 2018, Tested by Lizawati
// 6 April 2018, Modified to reduce complexity
//
// SOLUTION TO Program 2
//
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

// The class Person is FULLY given
// Do not change anything for this class
class Person{ 
	protected:
		string name;
	public:
		Person(string n=""){ setName(n); }
		string getName() const{return name;}
		void setName(string n) {name = n;}
};

// B(i). ( marks).
// The class Doctor is PARTIALLY given
class Doctor : public Person{  // 1m goes to C(iii)-Inheritance
	private:
		string department;	  // 0.5m	
	public:
		Doctor(string n="",string d=""):Person(n), department(d){}   // 0.5m + 0.5m for C(iii)-Inheritance.
		string getDepartment() const{return department;}             // 1m
};

// B(ii). (marks)
class Guardian : public Person{ // 1m goes to C(iii)-Inheritance
	private:
		string phone;           // 0.5m
	public:
		Guardian(string n="", string p=""):Person(n), phone(p){}       // 0.5m  + 0.5m for C(iii)-Inheritance.
		string getPhone() const{return phone;}   // 1m
		void setPhone(string p) {phone=p;}       // 1m
};


// B(iii). (marks)
// The class Patient is PARTIALLY given
// Do update the code for this class according to the class diagram

class Patient : public Person{   // 1m goes to C(iii)-Inheritance
	protected:
		string illness;          // 0.5m
		Doctor *doctor;          // 1m goes to C(i)-Aggregation
		Guardian guardian;       // 1m goes to C(ii)-Composition
		
	public:
		Patient(string pn="", string pi="", 
		        string gn="", string gp=""){

			name = pn;             // 0.5m to C(iii)-Inheritance
			illness = pi;          // 0.5m
			guardian.setName(gn);  // 1m for C(ii)-Composition
			guardian.setPhone(gp); // 1m for C(ii)-Composition
			doctor=NULL;           // 1m
	   }
	   
		void assignDoctor(Doctor *doc) {doctor = doc;}  // 2m
		
		// partially given
		virtual void print() const{          // 1m for C(iv)-Polymorphism (virtual)               
			cout << "Patient's Name   :" << name    << endl;              // 0.5m
			cout << "Illness          :" << illness << endl;              // 0.5m  
			cout << "Guardian's Name  :" << guardian.getName() << endl;   // 1m for C(ii)-Composition
			cout << "Guardian's Phone :" << guardian.getPhone() << endl;  // 1m for C(ii)-Composition
			
			if (doctor){                                                       // 1m
				cout << "Doctor's Name   :" << doctor->getName()<< endl;       // 1m for C(i)-Aggregation
				cout << "Doctor's Dept.  :" << doctor->getDepartment()<< endl; // 1m for C(i)-Aggregation
			}
			else                                                               // 1m 
				cout << " *** No doctor assigned yet *** " << endl;            
			
		} 
};


// B(iv). (marks)
// The class Outpatient is PARTIALLY given
// Do update the code for this class according to the class diagram

class Outpatient : public Patient{    // 1m goes to C(iii)-Inheritance
	private:
		string diagnosis;             // 0.5m
	public:
		Outpatient( string pname="", string pillness="", 
		            string gname="", string gphone="", 
					string pdiagnosis="") : Patient(pname, pillness,gname, gphone) // 2m for C(iii)-Inheritance
        { diagnosis = pdiagnosis;}	// 0.5m
					
		
		void print() const{                                   
			cout << "Patient Type:  OUTPATIENT "    << endl;  
			cout << "Diagnosis   :  " <<  diagnosis << endl;  // 1m  + 0.5m for C(iv)-Polymorphism
			cout << endl;
			
			Patient::print();                                 // 1m for C(iii)-Inheritance + 0.5m for C(iv)-Polymorphism
		} 		
};

// B(v). ( marks)
// The class Inpatient is PARTIALLY given
// Do update the code for this class according to the class diagram
class Inpatient : public Patient{    // 1m goes to C(iii)-Inheritance
	private:
		string ward;                 // 0.5m
	public:
		Inpatient( string pname="", string pillness="", 
		            string gname="", string gphone="", 
					string pward="") : Patient(pname, pillness,gname, gphone)// 1.5m for C(iii)-inheritance
        { ward = pward;}	// 0.5m				

		void print() const{                             
			cout << "Patient Type:  INPATIENT "<< endl; 
			cout << "Ward        :  " <<  ward << endl; // 1m + 0.5m for C(iv)-Polymorphism
			cout << endl;
			
			Patient::print();                           // 1m for C(iii)-Inheritance + 0.5m for C(iv)-Polymorphism
		} 		
};

// The menu function is fully given

int menu(){
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

int main(){
	const int NDOC = 2;  // Number of of doctor. 
	const int NPATIENT   = 3;  // Number of patients. 

	// For convinience (for copy-and-paste purposes), the data of doctors and patients 
	//  are given at the bottom of this program.

	// D(i) (3 marks). Declaration of array (1m), initialization (1m each)
	Doctor doctors[NDOC]={ Doctor("Dr. Ramli", "ICU"), 
					       Doctor("Dr. Kamariah", "Radiology")	};
					   
	// D(ii). (4 marks). Declaration of array (1m), initialization (1m each)
	Patient *patients[NPATIENT] = { new Outpatient("Rozita",  "Sprained ankle", "Salleh", "4466", "X-ray"),
		                            new Inpatient("Nurdiana", "Respiratory failure", "Jalil", "7731","ICU 101"),
		                            new Outpatient("Ali", "Coronary artery", "Bakar", "1234","CT Scan")
	                        };
	
	// The program structure regarding the menu operation is given
	int c = menu();  
	
	while (c!=4){
		
		switch (c){
			case 1: // List doctors
				
				// D(iii). (4 marks)
				for (int i=0; i<NDOC; i++)   // 1m
					cout <<"Doctor's Name: " << doctors[i].getName() <<"\t"         // 1.5m
					     <<"Department: "    << doctors[i].getDepartment() << endl; // 1.5m
				cout << endl;
				break;

			case 2: // List patients
				
				// D(iv). (3 marks).
				for (int i=0; i<NPATIENT; i++){      // 1m
					cout << "Patient #" << (i+1) << endl; // 1m
					patients[i]->print();            //  1m + 1m goes to C(iv)-Polymorphism
					cout << endl;
				}
					
				break;

			case 3:  // Assign a doctor
				int pIndex;  // The array index of the patient to be assigned with a doctor.
				int dIndex;   // The array index of the doctor to assign to the patient.
				
				// D(v)-Assign a doctor. 3 marks
				try{                                             // 1m for D(vi)-Exception Handling
					cout <<"Enter the patient index  and doctor index => ";
					cin >> pIndex >> dIndex;
				
					if ( (pIndex <0) || (pIndex >=NPATIENT) ||    // 1m for D(vi)-Exception Handling
					     (dIndex <0) || (dIndex >=NDOC)           // 1m for D(vi)-Exception Handling
					   )   
						throw "Index is out of range";            // 1m for D(vi)-Exception Handling
				
					patients[pIndex]->assignDoctor(doctors + dIndex);  // 3m for D(v)
				}
				catch (const char *e){                                             // 1m for D(vi)-Exception Handling
					cout << "** Error: " << e << endl;                             // 1m for D(vi)-Exception Handling
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
Nurdiana , Respiratory failure , Jalil, 7731,ICU 101, Inpatient
Ali , Coronary artery , Bakar , 1234 ,CT Scan, Outpatient 

*/
