////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SECJ/SCSJ1023 - Programming Technique II
// Semester 2, 2019/2020
// Final Exam, Problem Solving
// Template File
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#define DISC1 100 //Discount rate for infants
#define DISC2 20  //Discount rate for childrens & senior citizens
#define SIZE 50   //The maximum number of audiences
#define N 20      //The maximum number of seats
using namespace std;

//----------------------------------
// The Date class is FULLY given
class Date
{
	private:
		int day, month, year;

	public:
		void readDate()
		{
			char ch;
			cout << "Date [dd-mm-yyyy]: ";
			cin >> day >> ch >> month >> ch >> year;
		}

		void dispDate()
		{
			if (day < 10)
				cout << "0";
			cout << day << "-";

			if (month < 10)
				cout << "0";
			cout << month << "-" << year;
		}
};


//----------------------------------
// The Time class is FULLY given
class Time
{
	private:
		int hour, minute;


	public:
		void readTime()
		{
			char ch;
			cout << "Time [hour:min] using 24-hour format: ";
			cin >> hour >> ch >> minute; //Using 24-hour format
		}

		void dispTime()
		{
			int hh = hour;

			if (hour > 12)
				hour -= 12;

			if (hour < 10)
				cout << "0";

			cout << hour << ":";

			if (minute < 10)
				cout << "0";
			cout << minute;

			if (hh < 12)
				cout << " am";
			else
				cout << " pm";
		}
};


//----------------------------------
// The Audience class is PARTIALLY given
class Audience
{
	protected:
		//Complete member variables declaration
		string name;
		int age, seatNo;

	public:

		//Complete default arguments constructor
		Audience (string name = 0, int age = 0, int seatNo = 0)
		{
			this->name = name;
			this->age = age;
			this->seatNo = seatNo;
		}

		//TASK 1 (2.5 Marks)
		//TODO: Complete the definition of the Audience class

		//Task 1(a): Define the virtual displayDetails function [1.5 marks]
		//___________________________________
		virtual void displayDetails()
		{
			cout<<setw(25)<<name<<setw(7)<<age;
		}


		//Task 1(b): Define the pure virtual calcDisc function [1 mark]
		//___________________________________
		virtual double calcDisc()=0;
};


//----------------------------------
//Adults class is PARTIALLY given

//TASK 2 (7.5 Marks)
//TODO: Complete the definition of the Adults class

//Task 2(a): Specify the Adults class as a child of the Audience class [1 mark]
class Adults:public Audience
{
	public:

		//Task 2(b): Define the constructor with arguments [1.5 marks]
		//___________________________________
		Adults(string name, int age, int seatNo):Audience(name,age,seatNo) {		}


		//Task 2(c): Define the calcDisc function [2.5 marks]
		//___________________________________
		double calcDisc()
		{
			if(age>=60)
			{
				return DISC2;
			}
			else 
			{
				return 0;
			}
		}


		//Task 2(d): Redefine the displayDetails function [2.5 marks]
		//___________________________________
		void displayDetails()
		{
			cout<<setw(25)<<name<<setw(7)<<age<<setw(25)<<"-"<<setw(9)<<seatNo;
		}
};


//----------------------------------
//Kids class is PARTIALLY given

//TASK 3 (8 Marks)
//TODO: Complete the definition of the Kids class

//Task 3(a): Specify the Kids class as a child of the Audience class [1 mark]
//___________________________________

class Kids:public Audience 
{
	private:
		string parentName;

	public:

		//Task 3(b): Define the constructor with arguments [2 marks]
		//___________________________________
		Kids(string name, int age, int seatNo, string parentName):Audience(name,age,seatNo)
		{
			this->parentName=parentName;
		}


		//Task 3(c): Define the calcDisc function [2.5 marks]
		//___________________________________
		double calcDisc()
		{
			if(age<=2)
			{
				return DISC1;
			}
			else if(age<=12)
			{
				return DISC2;
			}
		}


		//Task 3(d): Redefine the displayDetails function [2.5 marks]
		//___________________________________
		void displayDetails()
		{
			cout<<setw(25)<<name<<setw(7)<<age<<setw(25)<<parentName<<setw(9)<<seatNo;
		}
};

//----------------------------------
// The Movie class is PARTIALLY given
class Movie
{
	//TASK 4 (19.5 Marks)
	//TODO: Complete the definition of the Movie class

	private:
		//Task 4(a): Define all the member variables [3.5 marks]
		//___________________________________
		string title;
		bool seat[N];
		double price;
		int numAdults;
		int numKids;
		int numAudience;
		int hallNo;
		Audience *audienceList[SIZE];
		Date date;
		Time time;

	public:
		//Complete default constructor
		Movie()
		{
			numKids = 0;
			numAdults = 0;
			numAudience = 0;
			for (int i = 0; i < N; i++)
				seat[i] = true;
		}

		//Complete getTitle function
		string getTitle()
		{
			return title;
		}

		//Complete getSeat function
		bool getSeat(int ind)
		{
			return seat[ind];
		}

		//Complete setSeat function
		void setSeat(int ind)
		{
			seat[ind] = false;
		}

		//Complete getDateTime function
		void getDateTime()
		{
			cout << " (";
			date.dispDate();
			cout << ", ";
			time.dispTime();
			cout << ")";
		}

		//Incomplete readInput function
		void readInput()
		{
			//Task 4(b): Complete the definition of the readInput function [4 marks]
			//___________________________________
			cout<<"Title: ";
			getline(cin,title);
			cin.ignore();
			cout<<"Hall: ";
			cin>>hallNo;
			cout<<"Ticket Price: RM";
			cin>>price;
			date.readDate();
			time.readTime();
		}

		//Incomplete addAudience function
		void addAudience(Audience *p)
		{
			//Task 4(c): Complete the definition of the addAudience function [2.5 marks]
			//___________________________________

			if (dynamic_cast <Adults*> (p)) //To check if p is an instance of Adults
			{
				audienceList[numAudience]=p;
				numAudience++;
				numAdults++;
			}
			else
			{
				audienceList[numAudience]=p;
				numAudience++;
				numKids++;
			}
		}

		//Incomplete displayInfoMovie function
		void displayInfoMovie()
		{
			//Task 4(d): Complete the definition of the displayInfoMovie function [3.5 marks]
			//___________________________________
			cout<<"Title\t: "<<title<<endl;
			cout<<"Hall\t: "<<hallNo<<endl;
			cout<<"Date\t:";
			date.dispDate();
			cout<<"\nTime\t:";
			time.dispTime();
			cout<<"\nPrice\t: RM"<<fixed<<setprecision(2)<<price<<endl;
		}

		//Incomplete displayInfoAudience function
		void displayInfoAudience()
		{
			double priceAftDisc, totalPrice = 0;

			if (numAudience == 0)
				cout << "\nNo audience!" << endl;
			else
			{
				cout << "\nNumber of Audience: " << numAudience << endl
					 << "Number of Adults  : "   << numAdults << endl
					 << "Number of Kids    : "   << numKids << endl << endl;

				cout << left;
				cout << setw(4)  << "No"
					 << setw(25) << "Name"
					 << setw(7)  << "Age"
					 << setw(25) << "Parent Name"
					 << setw(9)  << "Seat No"
					 << "Ticket (RM)" << endl;

				//Task 4(e): Complete the definition of the displayInfoAudience function [6 marks]
				//___________________________________
				for (int i=0;i<numAudience;i++)
				{
					cout<<setw(4)<<i+1;
					audienceList[i]->displayDetails();
					priceAftDisc=price-(audienceList[i]->calcDisc()/100*price);
					cout<<fixed<<setprecision(2)<<priceAftDisc<<endl;
					totalPrice+=priceAftDisc;
				}
				cout<<fixed<<setprecision(2);

				cout << "\nTotal ticket price = RM" << totalPrice
					 << endl << endl;
			}
		}
};

//----------------------------------
// The menu function is FULLY given
int menu()
{
	int task;

	cout << "========== Menu ==========" << endl
		 << "[1] Add Movie" << endl
		 << "[2] Add Audience" << endl
		 << "[3] Display Movies" << endl
		 << "[4] Display Audiences" << endl
		 << "[5] Exit" << endl
		 << "==========================" << endl
		 << "\nSelect task: ";

	cin >> task;
	cin.ignore();

	return task;
}

//----------------------------------
// The main function is PARTIALLY given
int main()
{
	//Local variables and instances
	char ch;
	int choice1; //Task chosen
	int choice2; //Movie chosen
	string name, pName;
	int age, seatNo, numMovie = 0;

	Movie movieObj; //Movie object
	Audience *audiencePtr; //Audience pointer
	Movie movieList[SIZE]; //Array of Movie objects

	//TASK 5 (25.5 Marks)
	//TODO: Complete the definition of the main function

	//Task 5(a): Enter the task chosen [1 mark]
	//___________________________________
	choice1=menu();	

	//The process will be repeated if user enter the value in range 1 to 4
	while (choice1 > 0 && choice1 < 5)
	{
		
		
		switch (choice1)
		{
			case 1:

				cout << "\n<<< Add Movie >>>" << endl;

				//Task 5(b-i): Enter the details of movie [1 mark]
				//___________________________________
				movieObj.readInput();


				//Task 5(b-ii): Add the Movie object into the Movie array [1 mark]
				//___________________________________
				movieList[numMovie]=movieObj;

				numMovie++;
				break;

			case 2:

				//Display an appropriate message if there is no movie
				if (numMovie == 0)
				{
					cout << "Sorry!! No movie, please add movie first..." << endl;
					break;
				}

				cout << "\n<<< Add Audience >>>" << endl
				 	 << "\nMovie list" << endl;

				//Task 5(c-i): Display the list of movies [3.5 marks]
				//___________________________________
				for (int i=0;i<numMovie;i++)
				{
					cout<<i+1<<") "<<movieList[i].getTitle();
					movieList[i].getDateTime();
					cout<<endl;
				}
				cout<<endl;

				cout << "\nSelect movie: ";
				cin >> choice2; //To enter the movie chosen
				cin.ignore();

				do
				{
					//To enter the details of audience
					cout << "\n--- Enter Audience Info ---" << endl;
					cout << "Name   : ";
					getline(cin, name);
					cout << "Age    : ";
					cin >> age;
					bool status = true; //Initial value of seat status

					if (age > 2)
					{
						do
						{
							cout << "Seat No: ";
							cin >> seatNo;

							//Task 5(c-ii): Check the seat availability. If the seat is available,
							//update the status of the seat. [5 marks]
							//___________________________________
							if(movieList[choice2-1].getSeat(seatNo))
							{
								movieList[choice2-1].setSeat(seatNo);
								status=!status;
							}

							else
								cout << "Seat unavailable, choose others!" << endl << endl;
						} while (status);
					}
					cin.ignore();


					//Task 5(c-iii): Dynamically allocates a new audience (an adult
					//or a kid) object. Use a polymorphic concept. [5 marks]
					//___________________________________

					if (age > 12) //To identify the audience category
					{
						audiencePtr=new Adults(name,age,seatNo);
						
					}
					else
					{
						string parentName;
						cout<<"Parent Name: ";
						getline(cin,parentName);
						cin.ignore();
						audiencePtr=new Kids(name,age,seatNo,parentName);
					}

					//Task 5(c-iv): Add the audience to the selected Movie object [2 marks]
					//___________________________________
					movieList[choice2-1].addAudience(audiencePtr);

					cout << "\nPress 'Y' to continue >> ";
					cin >> ch; //To enter a value to continue to add an audience
					cin.ignore();
					ch = toupper(ch);
				} while (ch == 'Y'); //The process will be continued if user enter the valid input
				break;

			case 3:

				//To display an appropriate message if there is no movie
				if (numMovie == 0)
					cout << "Sorry!! No movie data to display..." << endl;
				else
				{
					cout << "\n<<< Movie Info >>>" << endl;
					cout << "\nNumber of Movies: " << numMovie << endl;

					//Task 5(d): Display the list of movies' details [2.5 marks]
					//___________________________________
					for (int i=0;i<numMovie;i++)
					{
						cout<<"Movie #"<<i+1<<endl;
						movieList[i].displayInfoMovie();
					}
				}
				break;

			case 4:

				//To display an appropriate message if there is no movie
				if (numMovie == 0)
				{
					cout << "Sorry!! No movie, please add movie first..." << endl;
					break;
				}

				cout << "\n<<< Movie(s) and Audience(s) Info >>>" << endl;
				cout << "\nNumber of Movies: " << numMovie << endl;

				//Task 5(e): Display the list of audiences' details based on the movie [3.5 marks]
				//___________________________________
				
				for(int i=0;i<numMovie;i++)
				{
					cout<<"Movie #"<<i+1<<endl;
					movieList[i].displayInfoMovie();
					movieList[i].displayInfoAudience();
				}

		} //End switch

		cout << endl;

		//Task 5(f): Enter the task chosen (1 mark)
		//___________________________________
		choice1=menu();

	} //End while

	cout << "Thank you! :)" << endl;
	return 0;
}
