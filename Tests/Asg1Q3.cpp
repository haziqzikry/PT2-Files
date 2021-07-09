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
   This class store the 'name' of a store and 'sales' data (for 12 months) of a store

   There is a member called 'id' which is set based on an internal counter '_counter'

   get*** functions are accessors while set*** functions are mutators

   The class overloads operator<< to enable easy display of its internal data (via cout)
   such as 'id', 'name', and 'sales'
*/

class StoreData {
	static int	_counter;						/* internal counter */
	int			id;								/* store id, value is derived from _counter */
	char		name[MAX_STORE_NAME];			/* store name */
	float		sales[MAX_MONTH];				/* sales data for every month */

public:
	StoreData();
	StoreData(const char name[], float sales[]);

	int		getId() const;
	char*	getName() const;
	float*	getSales() const;

	void setCounter(int c);
	void setName(char name[]);							
	void setSales(float sales[]);

	friend ostream& operator<<(ostream& os, const StoreData& dt);	/* display all data */
};


/* StoreManager
   ------------
	This class store manages a dynamically allocated array of 'storedata'.

	'store_data_count' keeps track of the number of StoreData pointed by 'storedata'

	'addStore' adds StoreData s into the array 'storedata;

	'deleteStore' deleted StoreData pinter by 'storedata' which matched the given 'id'

	'modifyStore' will update 'name' and 'sales' of StoreData pointed by 'storedata' 
	which matched the given 'id' with StoreData in 's'

	'putStoreData' will update 'storedata' and 'store_data_count' with 's' and 'count'

	'printStore' will print out data from each of the StoreData in 'storedata' using operator<<

	'getStoreData' is an accessor for 'storedata'

	'getStoreDataLength' is an accessor for 'store_data_count'
*/

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

int StoreData::_counter = 0;	/* initialize internal counter _counter to 0 */


//---------------------------------------------------------------------------------------------
//
// TODO: Write a default constructor for StoreData that sets/initializes id, name, and sales to 0 
//
StoreData::StoreData()
{
	/* no modification made to _counter */
	/* set id, names, and sales data to 0*/
	id = 0;
	name[0] = 0;
	for (int i = 0; i < MAX_MONTH; i++)
		sales[i] = 0;
}

StoreData::StoreData(const char name[], float sales[])
{
	_counter++;			/* increment internal counter */
	id = _counter;		/* set id to current value of  _counter*/

	/* initialize name from the 1st parameter of the constructor*/
	if (strlen(name) >= MAX_STORE_NAME)
	{
		/* Only copy the first (MAX_STORE_NAME - 1) characters if name if too large to fit  */
		for (int i = 0; i < MAX_STORE_NAME - 1; i++)
			this->name[i] = name[i];
		this->name[MAX_STORE_NAME] = 0;
	}
	else
	{
		//#pragma warning(suppress : 4996)  //ignore/comment this line if you are not using visual studio
		strcpy(this->name, name);
	}

	/* initialize sales data from the 2nd parameter of the constructor*/
	for (int i = 0; i < MAX_MONTH; i++)
	{
		this->sales[i] = sales[i];
	}
}

//---------------------------------------------------------------------------------------------
//
// TODO: Write an accessor function for StoreData's id 
//
int StoreData::getId() const			//accessors for id
{
	return id;
}

//---------------------------------------------------------------------------------------------
//
// TODO: Write an accessor function for StoreData's name 
//
char* StoreData::getName() const		//accessors for name
{
	return (char *)name;
}


//---------------------------------------------------------------------------------------------
//
// TODO: Write an accessor function for StoreData's sales 
//
float* StoreData::getSales() const		//accessors for sales
{
	return (float*)sales;
}


//---------------------------------------------------------------------------------------------
//
// TODO: Write a mutator function for StoreData's _counter 
//
void StoreData::setCounter(int c)				//mutators for _counter
{
	_counter = c;
}


//---------------------------------------------------------------------------------------------
//
// TODO: Write a mutator function for StoreData's name 
//
void StoreData::setName(char name[])			//mutators for name
{
	for (int i = 0; i < MAX_STORE_NAME; i++)
	{
		this->name[i] = name[i];
	}
}


//---------------------------------------------------------------------------------------------
//
// TODO: Write a mutator function for StoreData's sales 
//
void StoreData::setSales(float sales[])			//mutators for sales
{
	for (int i = 0; i < MAX_MONTH; i++)
	{
		this->sales[i] = sales[i];
	}
}

//---------------------------------------------------------------------------------------------
//
// TODO: overload operator<< to provide access to the value of id, name, and sales of StoreData 
//
ostream& operator<<(ostream& os, const StoreData& sd)
{
	//supply stream with: "[id] \t name \t sales data"

	os << "[" << sd.id << "]" <<"\t"<< sd.name<<"\t";

	for (int i = 0; i < MAX_MONTH; i++)
		os << " " << sd.sales[i];

	return os;
}


// -------------------------------------------------------------------------------------------------------------------
// Implementations for class StoreManager  ---------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
//
// TODO: Write a destructor for StoreManager that will deallocate any allocated memory for storedata, if any 
//
StoreManager::~StoreManager()
{
	if (storedata != 0)					//if there's allocated data
	{
		//free allocated memory 
		delete[] storedata;
	}
}

void StoreManager::addStore(StoreData s)			
{
	if (storedata != 0)				//if space has already been allocated
	{
		StoreData* temp;
		
		//
		//TODO: Allocate memory to temp to contain current + new StoreData 
		//
		temp = new StoreData [store_data_count + 1];


		//
		//TODO: Copy existing StoreData to newly allocated space 
		//
		for (int i = 0; i < store_data_count; i++)
		{
			temp[i] = storedata[i];
		}

		//
		//TODO: Copy new StoreData s to end of newly allocated space 
		//
		temp[store_data_count] = s;

		//
		//TODO: Update store_data_count to mark current size of storedata 
		//
		store_data_count++;

		/* free previous allocated space in storedata */
		delete[] storedata;

		/* update storedat to point to newly allocated space */
		storedata = temp;
	}
	else							//no space allocated yet, this is the first item
	{
		//
		//TODO: Allocate memory for StoreData array of 1 element  
		//
		storedata = new StoreData[1];	//allocate array of 1 elem
		
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
			/* if current storedata id does not match 'id' */
			if (storedata[i].getId() != id)
			{
				/* copy storedata to newly allocated space */
				temp[j] = storedata[i];

				/* update j */
				j++;
			}
		}

		if (i == j) //if 'id' not in the list
		{
			cout << "Error !!! Id " << id << " not found !" << endl;

			/* delete newly allocated space */
			delete[] temp;
		}
		else
		{
			/* free previously allocated space */
			delete[] storedata;

			/* update store_data_count */
			store_data_count--;

			/* update storedata to point to newly allocated space */
			storedata = temp;
		}
	}
	else
	{
		cout << "Error ! no store data to delete !" << endl;
	}
}

void StoreManager::modifyStore(int id, StoreData s)			
{
	//
	// TODO: Search for StoreData in storedata with id matching the
	//	one given in the first parameter (id), and set it's name and sales
	//  to the one in second parameter. Exit the function once done. 
	//
	/* search for data with matching id */
	for (int i = 0; i < store_data_count; i++)		
	{
		if (storedata[i].getId() == id)				
		{
			storedata[i].setName(s.getName()); 			
			storedata[i].setSales(s.getSales());	

			/* exit function */
			return;									
		}
	}

	/* display error message */
	cout << "Error !!! Id of store not found !"<<endl;
}

void StoreManager::printStore() const			
{
	//
	// TODO: Print " No data to print ! " message if there is no StoreData added, and exit the function. 
	//
	if (store_data_count == 0)
	{
		cout << " No data to print ! " << endl;
		return;
	}


	cout << endl << "Sales data (id, name, sales) :" << endl;
	
	//
	// TODO: Print all StoreData in storedata 
	//
	for (int i = 0; i < store_data_count; i++)
	{
		cout << storedata[i] << endl;
	}
	
	
	cout << endl;
}


//---------------------------------------------------------------------------------------------
//
// TODO: Write an accessor function for StoreManager's storedata 
//
StoreData* StoreManager::getStoreData() const				//accessors for storedata
{
	return storedata;
}


unsigned long StoreManager::getStoreDataLength() const		//returns the size of data pointed by storedata in bytes
{
	return (store_data_count * sizeof(StoreData));
}


void StoreManager::putStoreData(StoreData* s, unsigned int count)		//update members with data given by parameters (for storedata, and store_data_count)
{
	/* free memory currently used by storedata, if any  */
	if (storedata != 0)
		delete[] storedata;

	/* update storedat and store_data_count with values from the parameters of this function */
	storedata = s;
	store_data_count = count;

	/* update counter so that _counter is one larger that the final id in 'storedata' */
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

void write(StoreManager& s)			
{
	string filename;				/* store name of file to be written to */

	cout << "[SAVE] Enter filename : ";
	getline(cin, filename);

	//
	//TODO: Open filename for output in binary mode 
	//
	ofstream fc(filename.data(), ios::binary);
	
	//
	//TODO: Write all StoreData in s to the file 
	//
	fc.write((char *)s.getStoreData(), s.getStoreDataLength());
	
	//
	//TODO: close the opened file 
	//
	fc.close();
}

void load(StoreManager& s)			
{
	string filename;				/* store name of file to be loaded */
	unsigned long file_length;		/* store length of file in bytes */
	unsigned int count;				/* store the number of StoreData records in filename */
	StoreData* temp;				/* store address of newly allocated memory */

	cout << "[LOAD] Enter filename : ";
	getline(cin, filename);

	//
	//TODO: Open filename for input in binary mode
	//
	ifstream fc(filename.data(), ios::binary);
	
	//
	//TODO: display an error message and exit function if unable to open file 
	//
	if (!fc)
	{
		cout << "Error !!! file not found : " << filename << endl;
		return;
	}

	//
	//TODO: Get size of file into file_length 
	//
	fc.seekg(0L, ios::end);
	file_length = fc.tellg();
	
	//
	//TODO: Calculate the number of StoreData object is in the file 
	//
	count = file_length / sizeof(StoreData);
	
	//
	//TODO: Allocate memory to contain all StoreData object  
	//
	temp = new StoreData[count];
	
	//
	//TODO: Read all data from the file into the newly allocated memory 
	//
	fc.seekg(0L);
	fc.read((char *)temp, file_length);
	
	//
	//TODO: close the opened file 
	//
	fc.close();
	
	
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
		case 0: break;
		case 1: 	/* add */
			add(stores);
			break;
		case 2: 	/* modify */
			modify(stores);
			break;
		case 3: 	/* delete */
			remove(stores);
			break;
		case 4: 	/* print */
			prints(stores);
			break;
		case 5: 	/* write */
			write(stores);
			break;
		case 6: 	/* load */
			load(stores);
			break;
		default:
			cout << "Unknown option !" << endl;
		}
	} while (choice != 0);

	cout << "Thank you ! :)" << endl;

	return 0;
}
