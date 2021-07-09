#include <iostream>
#include <string>
using namespace std;

class Student{  
    string name;
public:    
    Student(string Name)    
    {      
        cout << "Student::constructor: " << name << endl;;      
        name = Name;    
    }    
    string Name()const    
    {      
        return(name);    
    }        
    ~Student()    
    {      
        cout << "Student::destructor "<< name << endl;      
    };
};

class Department{    
    string name;    
public:    
    Department(string Name)    
    {      
        cout << "Department::constructor: " << Name << endl;      
        name = Name;    
    }    
    string Name() const    
    {      
        return(name);    
    }
    ~Department()    
    {      
         cout << "Department::destructor: " << name << endl;
    }
};

class Course
{    
    Student * std_p;    
    Department * dept_p;    
    string coursename;    
    static unsigned int index;    
    static Course *courseList[4]; 
public:       
    Course(string crseName, Student* student, Department* dept) : coursename(crseName), std_p(student), dept_p(dept)    
    {      
        cout << "Course:constructor: " << coursename << endl;      
        if (index < 4)      
        {               
            courseList[index] = this;        
            ++index;      
        }      
        else      
        {        
            cout <<"Course list full" << endl;      
        }    
    };   
    ~Course()    
    {       
        cout << "Course:destructor: " << coursename << endl;     
            
    };
    static string findStudent(const char *crseName, const char* deptName)    
    {      
        for(int i=0; i<index; i++)      
        {        
            if ( (courseList[i]->getCourseName() == crseName) && (courseList[i]->getDeptName() == deptName) )        
            {          
                return(courseList[i]->getStdName());        
            }      
        }    
    }    
    string getStdName()const 
    {
        return(std_p->Name());
    };    
    string getDeptName() const 
    {
        return(dept_p->Name());
    };
    string getCourseName()const 
    {
        return(coursename);
    };
}; 

unsigned int Course::index =0;

Course* Course::courseList[4] = {0,0,0,0};

int main()
{  
    int i;  
    cout<<"\nExample of Association class...\n";   
    cout<<"We have got 4 students ...\n";  
    Student *studentNames[4] = {new Student("Student_1"), new Student("Student_2"), new Student("Student_3"), new Student("Student_4")} ;  

    cout<<"\nWe have got 2 Departments...\n";  
    Department *departNames[2] = {new Department("Mathemetics"), new Department("Computer Science")} ;    

    cout<<"\nHere class Course Associates Student and Department, with a Course name ...\n";  
    Course course1("Data Structure",studentNames[0], departNames[1]);  
    Course course2("Maths",studentNames[3], departNames[0]);  
    Course course3("Programming",studentNames[2], departNames[0]);  
    Course course4("Artificial Intelligence",studentNames[1], departNames[1]);  
    
    cout<<"\nFinding a Student using Course and Department...\n";  

    cout<<"Student who has taken Maths Course in Mathemetics Department is:"<<Course::findStudent("Maths", "Mathemetics")<<endl;    

    cout<<"\nDeletion of objects...\n\n";  
    for(i=0; i<4; ++i)  
    {    
        delete studentNames[i];  
    }  
    cout<<"\n";  
    for(i=0; i<2; ++i)  
    {    
        delete departNames[i];  
    }  
    cout<<"\n";  
    return(0);
}
