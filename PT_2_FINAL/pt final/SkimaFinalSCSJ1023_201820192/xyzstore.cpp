#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

#define MAX_STORE_NAME	10
#define MAX_MONTH		12

/* StoreData
   ---------
   a) This class store the 'name' of a store and 'sales' data (for 12 months) of a store.
   b) There is a member called 'id' which is set based on an internal counter '_counter'.
   c) get*** functions are accessors while set*** functions are mutators.
   d) The class overloads operator<< to enable easy display of its internal data (via cout)
      such as 'id', 'name', and 'sales'. */

class StoreData {
	static int	_counter;						/* internal counter */
	int			id;								/* store id, value is derived from _counter */
	char		name[MAX_STORE_NAME];			/* store name */
	float		sales[MAX_MONTH];				/* sales data for every month */

public:
	StoreData();
	StoreData(const char name[], float sales[]);

	int		getId() const;
	char*	getName();
	float*	getSales();

	void setCounter(int c);
	void setName(char name[]);							
	void setSales(float sales[]);

	friend ostream& operator<<(ostream& os, const StoreData& dt);	/* display all data */
};

/* StoreManager
   ------------
	a) This class store manages a dynamically allocated array of 'storedata'.
	b) 'store_data_count' keeps track of the number of StoreData pointed by 'storedata'.
	c) 'addStore' adds StoreData s into the array 'storedata'.
	d) 'deleteStore' deleted StoreData pointed by 'storedata' which matched the given 'id'.
	e) 'modifyStore' will update 'name' and 'sales' of StoreData pointed by 'storedata' 
	    which matched the given 'id' with StoreData in 's'.
	f) 'putStoreData' will update 'storedata' and 'store_data_count' with 's' and 'count'.
	g) 'printStore' will print out data from each of the StoreData in 'storedata' using operator<<.
	h) 'getStoreData' is an accessor for 'storedata'.
	i) 'getStoreDataLength' is an accessor for 'store_data_count'. */
	
class StoreManager {
	unsigned long store_data_count;
	StoreData*	storedata;

public:
	StoreManager() : store_data_count(0), storedata(0) {};
	~StoreManager();

	void addStore(StoreData s);
	void deleteStore(int id);
	void modifyStore(int id, StoreData s);
	void putStoreData(StoreData* s, unsigned int count);

	void printStore() const;
	StoreData* getStoreData() const;
	unsigned long getStoreDataLength() const;
};

// -------------------------------------------------------------------------------------------------------------------
// Implementations for class Store Data  -----------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

int StoreData::_counter = 0;	/* Initialize internal counter _counter to 0 */


/* TOTAL MARKS:  5 marks */ //----------------------------------------------------------------------------------------
//
// Task 1: Write a default constructor for StoreData that sets/ initializes id, name, and sales to 0 (5M)
//
StoreData::StoreData()
{
	id=0;
	name[MAX_STORE_NAME]=0;
	sales[MAX_MONTH]=0;
}

StoreData::StoreData(const char name[], float sales[])
{
	_counter++;			/* increment internal counter */
	id = _counter;		/* set id to current value of  _counter */

	/* Initialize name from the 1st parameter of the constructor */
	if (strlen(name) >= MAX_STORE_NAME)
	{
		/* Only copy the first (MAX_STORE_NAME - 1) characters if name if too large to fit  */
		for (int i = 0; i < MAX_STORE_NAME - 1; i++)
			this->name[i] = name[i];
		this->name[MAX_STORE_NAME] = 0;
	}
	else
	{
		#pragma warning(suppress : 4996)  //ignore/ comment this line if you are not using visual studio
		strcpy(this->name, name);
	}

	/* Initialize sales data from the 2nd parameter of the constructor */
	for (int i = 0; i < MAX_MONTH; i++)
	{
		this->sales[i] = sales[i];
	}
}

/* TOTAL MARKS:  2 marks */ //----------------------------------------------------------------------------------------
//
// Task 2: Write an accessor function for StoreData's id (2M)
//

int StoreData::getId() const
{
	return id;
}



/* TOTAL MARKS:  2 marks */ //----------------------------------------------------------------------------------------
//
// Task 3: Write an accessor function for StoreData's name (2M)
//

char* StoreData::getName() 
{
	return name;
}





/* TOTAL MARKS:  2 marks */ //----------------------------------------------------------------------------------------
//
// Task 4: Write an accessor function for StoreData's sales (2M)
//

float* StoreData::getSales()
{
	return sales;
}




/* TOTAL MARKS:  2 marks */ //----------------------------------------------------------------------------------------
//
// Task 5: Write a mutator function for StoreData's _counter (2M)
//

void StoreData::setCounter(int c)
{
	_counter=c;
}




/* TOTAL MARKS:  3 marks */ //----------------------------------------------------------------------------------------
//
// Task 6: Write a mutator function for StoreData's name (3M)
//

void StoreData::setName(char _name[])
{
	name[10]=_name[10];
}




/* TOTAL MARKS:  3 marks */ //----------------------------------------------------------------------------------------
//
// Task 7: Write a mutator function for StoreData's sales (3M)
//


void StoreData::setSales(float _sales[])
{
	sales[12]=_sales[12];
}





/* TOTAL MARKS:  5 marks */ //----------------------------------------------------------------------------------------
//
// Task 8: Overload operator<< to provide access to the value of id, name, and sales of StoreData (5M)
//

ostream& operator<<(ostream& os, const StoreData& dt)
{
	os << "\tId = " << dt.id << endl;
	os << "\tName     = " << dt.name << endl;
	os << "\tSales   = " << dt.sales << endl;
	
	return os;
}





















// -------------------------------------------------------------------------------------------------------------------
// Implementations for class StoreManager  ---------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------


/* TOTAL MARKS:  3 marks */ //----------------------------------------------------------------------------------------
//
// Task 9: Write a destructor for StoreManager that will deallocate any allocated memory for storedata, if any (3M)
//



StoreManager::~StoreManager()
{
	delete storedata;
}





/* TOTAL MARKS:  9 marks */ //----------------------------------------------------------------------------------------
void StoreManager::addStore(StoreData s)			
{
	if (storedata != 0)				//if space has already been allocated
	{
		StoreData* temp;
		//
		//Task 10(a): Allocate memory to temp to contain current + new StoreData (2M)
		//
		temp=new StoreData[store_data_count-1];
		//
		//Task 10(b): Copy existing StoreData to newly allocated space (2M)
		//
		
	
		
		
		

		//
		//Task 10(c): Copy new StoreData s to end of newly allocated space (2M)
		//
		storedata[store_data_count]=s;

		//
		//Task 10(d): Update store_data_count to mark current size of storedata (1M)
		//
		store_data_count++;

		/* Free previous allocated space in storedata */
		delete[] storedata;

		/* Update storedat to point to newly allocated space */
		storedata = temp;
	}
	else							//No space allocated yet, this is the first item
	{
		//
		//Task 10(e): Allocate memory for StoreData array of 1 element  (2M)
		//
		
		
		storedata[0] = s;
		store_data_count++;
	}
}

void StoreManager::deleteStore(int id)
{
	StoreData* temp;
	int i, j;

	if (store_data_count > 0) {
		temp = new StoreData[store_data_count];

		j = 0;
		for (i = 0; i < store_data_count; i++)
		{
			/* If current storedata id does not match 'id' */
			if (storedata[i].getId() != id)
			{
				/* Copy storedata to newly allocated space */
				temp[j] = storedata[i];

				/* Update j */
				j++;
			}
		}

		if (i == j) //If 'id' not in the list
		{
			cout << "Error !!! Id " << id << " not found !" << endl;

			/* Delete newly allocated space */
			delete[] temp;
		}
		else
		{
			/* Free previously allocated space */
			delete[] storedata;

			/* Update store_data_count */
			store_data_count--;

			/* Update storedata to point to newly allocated space */
			storedata = temp;
		}
	}
	else
	{
		cout << "Error ! no store data to delete !" << endl;
	}
}

/* TOTAL MARKS:  7 marks */ //----------------------------------------------------------------------------------------
void StoreManager::modifyStore(int id, StoreData s)			
{
	//
	// Task 11: Search for StoreData in storedata with id matching the
	//	one given in the first parameter (id), and set it's name and sales
	//  to the one in second parameter. Exit the function once done. (7M)
	//
	
	
	
	
	
	
	
	
	
	
	
	

	/* display error message */
	cout << "Error !!! Id of store not found !"<<endl;
}

/* TOTAL MARKS:  5 marks */ //----------------------------------------------------------------------------------------
void StoreManager::printStore() const			
{
	//
	// Task 12(a): Print " No data to print ! " message if there is no StoreData added, and exit the function. (3M)
	//

	
	
	
	


	cout << endl << "Sales data (id, name, sales) :" << endl;
	
	//
	// Task 12(b): Print all StoreData in storedata (2M)
	//

	
	
	
	
	
	cout << endl;
}

/* TOTAL MARKS:  2 marks */ //----------------------------------------------------------------------------------------
//
// Task 13: Write an accessor function for StoreManager's storedata (2M)
//






unsigned long StoreManager::getStoreDataLength() const		//Returns the size of data pointed by storedata in bytes
{
	return (store_data_count * sizeof(StoreData));
}

//Update members with data given by parameters (for storedata, and store_data_count)
void StoreManager::putStoreData(StoreData* s, unsigned int count)	
{
	/* Free memory currently used by storedata, if any  */
	if (storedata != 0)
		delete[] storedata;

	/* Update storedat and store_data_count with values from the parameters of this function */
	storedata = s;
	store_data_count = count;

	/* Update counter so that _counter is one larger that the final id in 'storedata' */
	storedata->setCounter(s[count - 1].getId());
}

void menu()
{
	cout << endl
		<< "Welcome to XYZ Pvt Ltd -=<[XYZ]>=- " << endl
		<< "[1] Add new sales data" << endl
		<< "[2] Modify sales data" << endl
		<< "[3] Delete sales data" << endl
		<< "[4] Displays sales data" << endl
		<< "-" << endl
		<< "[5] Write sales data to file" << endl
		<< "[6] Load sales data from file" << endl
		<< "-" << endl
		<< "[0] Exit" << endl
		<< " Select task : ";
}

void add(StoreManager& s)
{
	string name;
	float sales[MAX_MONTH];

	cout << "Enter store name: ";
	getline(cin, name);

	cout << "Enter sales data : ";
	for (int i = 0; i < MAX_MONTH; i++)
		cin >> sales[i];

	StoreData temp(name.c_str(), sales);
	s.addStore(temp);
}

void modify(StoreManager& s)
{
	int id;
	string name;
	float sales[MAX_MONTH];

	cout << "Enter id of store to modify : ";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter new store name : ";
	getline(cin, name);

	cout << "Enter new sales data : ";
	for (int i = 0; i < MAX_MONTH; i++)
		cin >> sales[i];

	StoreData temp(name.c_str(), sales);
	s.modifyStore(id, temp);
}

void remove(StoreManager& s)
{
	int id;

	cout << "Enter id of store to Delete : ";
	cin >> id;

	s.deleteStore(id);
}

void prints(StoreManager& s)
{
	s.printStore();
}

/* TOTAL MARKS:  5 marks */ //----------------------------------------------------------------------------------------
void write(StoreManager& s)			
{
	string filename;				/* store name of file to be written to */

	cout << "[SAVE] Enter filename : ";
	getline(cin, filename);

	//
	//Task 14(a): Open filename for output in binary mode (1M)
	//

	
	//
	//Task 14(b): Write all StoreData in s to the file (3M)
	//

	
	//
	//Task 14(c): Close the opened file (1M)
	//

}

/* TOTAL MARKS:  10 marks */ //----------------------------------------------------------------------------------------
void load(StoreManager& s)			
{
	string filename;				/* Store name of file to be loaded */
	unsigned long file_length;		/* Store length of file in bytes */
	unsigned int count;				/* Store the number of StoreData records in filename */
	StoreData* temp;				/* Store address of newly allocated memory */

	cout << "[LOAD] Enter filename : ";
	getline(cin, filename);

	//
	//Task 15(a): Open filename for input in binary mode (1M)
	//

	
	//
	//Task 15(b): Display an error message and exit function if unable to open file (2M)
	//

	
	
	
	

	//
	//Task 15(c): Get size of file into file_length (2M)
	//

	
	
	//
	//Task 15(d): Calculate the number of StoreData object is in the file (1M)
	//

	
	//
	//Task 15(e): Allocate memory to contain all StoreData object  (1M)
	//

	
	//
	//Task 15(f): Read all data from the file into the newly allocated memory (2M)
	//

	
	
	//
	//Task 15(g): Close the opened file (1M)
	//

	
	
	s.putStoreData(temp, count);
}

int main()
{
	int choice;
	StoreManager stores;

	do {
		menu();
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (choice)
		{
		case 1: 	/* Add */
			add(stores);
			break;
		case 2: 	/* Modify */
			modify(stores);
			break;
		case 3: 	/* Delete */
			remove(stores);
			break;
		case 4: 	/* Print */
			prints(stores);
			break;
		case 5: 	/* Write */
			write(stores);
			break;
		case 6: 	/* Load */
			load(stores);
			break;
		default:
			cout << "Unknown option !" << endl;
		}
	} while (choice != 0);

	cout << "Thank you ! :)" << endl;

	return 0;
}
