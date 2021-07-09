#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Lecturer;
class Project
{
	private:
		string title;
		Lecturer *lect;  // Aggregation
	public:
		Project()
		{
			title = " ";
			lect = NULL;
		}
		string getTitle()
		{
			return title;
		}
		void setTitle(string t)
		{
			title = t;
		}
		Lecturer* getSupervisor()
		{
			return lect;
		}
		void setSupervisor(Lecturer* super)
		{
			lect = super;
		}
};

class Lecturer
{
	private:
		string name;
	public:
		Lecturer(string n)
		{
			name = n;
		}
		string getName()
		{
			return name;
		}
};

class Student
{
	private:
		string name;
		Project project;   // Composition
	public:
		Student()
		{
			name = " ";
		}
		void setName(string n)
		{
			name = n;
		}
		void setProject(string t)
		{
			project.setTitle(t);
		}
		void assignSupervisor(Lecturer* super)
		{
			project.setSupervisor(super);
		}
		void print()
		{
			cout << "Student      : " << name << endl;
			cout << "Project      : " << project.getTitle() << endl;
			
			if (project.getSupervisor() != NULL)
			{
				cout << "Supervisor   : " << project.getSupervisor()->getName()
				     << endl << endl;
			}
			else
			{
				cout << endl;
			}
		}
};

int main()
{
	int i = 0;
	ifstream inp;
	string file;
	
	here:// recognition site
	Lecturer lect1("Dr. Ali Bakar"), lect2("Prof. Dr. Abu Samah Abdullah");
	Student student[15];
	string name;
	string proj;
	
	cout << endl;
	cout << "File name : \t student_list1.txt \n\t\t student_list2.txt";
	cout << "\nEnter the file name = ";
	getline(cin,file);
	inp.open(file.c_str());
	
	cout << endl;
	
	if (!inp.is_open())
	{
		cout << "Please enter a valid file " << endl;
		goto here;
	}
	
	cout << "Output for file " << file << endl << endl;
	while(getline(inp, name, ','))
	{
		student[i].setName(name);
		
		getline(inp, proj);
		student[i].setProject(proj);
		
		i++;
	}
	
	for (int j=0; j<i; j++)
	{
		if(j==0 || j==1)
		{
			student[j].assignSupervisor(&lect1);
		}
		if(j==(i-1))
		{
			student[j].assignSupervisor(&lect2);
		}
		
		student[j].print();
		
	}
	
	inp.close();
	
	return 0;
}


