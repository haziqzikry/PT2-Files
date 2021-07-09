//Mohamad Haziq Zikry Bin Mohammad Razak A20EC0079
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

class software{
	private:
		 string *software1;
		 string *software2;
	public:
		software();
		software (string x, string y){
			software1 = new string;
			software2 = new string;
			software1 = &x;
			software2 = &y;
		}
		~software()
		{
		cout<< *software1 <<" and "<< *software2 <<" are destroyed from software\n";
		delete software1;
		delete software2;
		}
		
		software (const software &object)
		{
			software1 = new string;
			software2 = new string;
			*software1 = *object.software1;
			*software2 = *object.software2;
		}
		void getSoftware();
		void displaySoftware();
};

software::software(){
		software1 = new string;
		software2 = new string;
		*software1 = "python" ;
		*software2 = "matlab" ;
		cout << endl;
}

void software::getSoftware()
{
	cout << "Enter 2 software" << endl;
	getline (cin,*software1);
	getline (cin,*software2);
}

void software::displaySoftware()
{
	cout << *software1 << endl << *software2 << endl;
}

class hardware{
	private:
		char *hardware1 ;
		char *hardware2 ;
	public:
		hardware();
		hardware(char a[], char b[])
		{
			hardware1 = new char [30];
			hardware2 = new char [30];
			strcpy(hardware1,a);
			strcpy(hardware2,b);
		}
		~hardware()
		{
		cout<< hardware1 <<" and "<< hardware2 <<" are destroyed from hardware\n";

		delete [] hardware1;
		delete [] hardware2;
		}
		hardware (const hardware &object);
		void getHardware();
		friend ostream &operator << (ostream &, const hardware &);
};

hardware::hardware()
{
	hardware1 = new char [30];
	hardware2 = new char [30];
	strcpy(hardware1,"mouse pad");
	strcpy(hardware2,"headset");
}

hardware::hardware (const hardware &object)
	{
		hardware1 = new char [30];
		hardware2 = new char [30];
		strcpy(hardware1,object.hardware1);
		strcpy(hardware2,object.hardware2);
	}

void hardware::getHardware()
{
	cout << "Enter 2 hardware" << endl;
	cin.getline (hardware1,30);
	cin.getline (hardware2,30);
}

ostream &operator << (ostream &fileOut, const hardware &obj)
{
	fileOut << obj.hardware1 << endl;
	fileOut << obj.hardware2 << endl;
	return fileOut;
}

int main()
{
	//software
	cout << "Software" << "\n--------\n";
	cout << "Dev-C++ \n" << "RStudio\n\n";

	software s1;
	software s2 = s1;
	software *softwarepointer = &s2;
	s2.getSoftware();
	
	cout << endl;
	cout << "Software: Pointer of Object call" << endl;
	
	(*softwarepointer).getSoftware();

	cout << endl;
	cout << "Software: Copy constructor" << endl;
	s1.displaySoftware() ;
	
	//hardware
	cout << endl;
	cout << "Hardware" << "\n--------\n";
	cout << "laptop" << endl;
	cout << "mouse\n\n";
	
	hardware h1;
	hardware hardwareArr[2];
	hardware h2 = h1;
	h2.getHardware();

	cout << endl;
	cout << "Hardware: Array of Object call" << endl;
	hardwareArr[0].getHardware ();
	cout << endl;
	hardwareArr[1].getHardware ();

	cout << "\nHardware: Copy constructor" << endl;
	cout << h1;

	cout << "\n\nDestructor call\n";
	return 0;
}
