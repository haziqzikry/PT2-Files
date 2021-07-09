#include<iostream>
#include<fstream>

using namespace std;

class Lecturer{
	private:
		string name;		
	public:
		Lecturer(string n=""){name=n;}
		string getName() const{ return name;}
};

//(1) 
class Project{
	private:
		string title;          
		Lecturer *supervisor;  
	public:
		Project(){
			title="";           
			supervisor = NULL;  
		}
		
		string getTitle() const { return title;}
		void setTitle(string t){ title=t;}
		
		// Define the method getSupervisor 
		Lecturer* getSupervisor() const { 
			return supervisor;            
		}
		
		// Define the method setSupervisor 
		void setSupervisor(Lecturer* sv){ 
			supervisor = sv;              
		}
};

//(2) 
class Student{
	private:
		string name;      
		Project project;  
	public:
		Student(){ setName("");}
		void setName(string n) { name=n; }
		
		void setProject(string t) {  // t is project's title
			project.setTitle(t);     
		}

		void assignSupervisor(Lecturer* sv){  
			project.setSupervisor(sv);     
		}
		
		void print() const{
			cout << "Student    : " << name << endl;                 
			cout << "Project    : " << project.getTitle() << endl;   
			
			Lecturer *sv = project.getSupervisor();                  
						
			if (sv != NULL)                                                   
				cout << "Supervisor : " << sv->getName() << endl;    
				
			cout << endl;
		}
};

int main()
{
	//(3)Lecturer objects. There are only two lecturers. First lecturer = lect1, Second lecturer = lect2
	Lecturer lect1("Dr. Ali Bakar");                  
	Lecturer lect2("Prof. Dr. Abu Samah Abdullah");   
	
	//(4)
	Student studs[15];   // To hold the list of students
	int nStud = 0; // Number of students.  Initially, there is no student.

	//(5)Read the list of students from an input file and store them into the array.
	string fileName ="student_list2.txt";   //Change the file name to test with another file
	fstream fin; 
	string sname;      // Student's name
	string ptitle;     // Project's title
	
	fin.open(fileName.c_str(), ios::in);
	
	while ( getline(fin, sname,',' )){
		getline(fin, ptitle);
		
		studs[nStud].setName(sname);      
		studs[nStud].setProject(ptitle);  

		nStud++;
	}
	
	fin.close();
	
	//(6)Assign supervisors
	studs[0].assignSupervisor(&lect1);        
	studs[1].assignSupervisor(&lect1);        
	studs[nStud-1].assignSupervisor(&lect2);  
	
	//(7)Print the students

	for (int i=0; i<nStud; i++)  
		studs[i].print();        
		
	return 0;
}


