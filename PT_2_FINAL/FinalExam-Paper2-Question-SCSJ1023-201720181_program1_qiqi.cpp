// SCSJ1023, Programming Technique II
// Semester 1, 2017/2018
//
// Final Exam, Paper 2
// Program 1
// Structured programming question

#include <iostream>
#include <exception>

using namespace std;
const int MAX = 3;   // The maximum number of elements the array can hold

class Array
{
	private:
  		int data[MAX];   // array elements
  		int count;       // the number of element currently held by the array
	
	public:
  		
		// Task 1: Define three exception classes named 'Full', 'Empty' and 'NegativeIndex'   (6 marks)
		  class Full {};
		  class Empty {};
		  class NegativeIndex {};
		
  		
  		Array(){ count = 0;}  
  		int getCount() const {return count;}

  		// Method add: To add an element to the array
		void add(int element)    
  		{
		   // Task 2: Throw a  'Full' exception if the array already holds the maximum number of elements. (4 marks).
		   if (count >= MAX)
				throw Full();
    
		   data[count] = element; 
		   count++;  
        }

		// To remove an element from the array.
		void remove()
		{
		   // Task 3: Throw an 'Empty' exception if the array is empty, i.e., no item held in the array)   (4 marks)
		   if (count == 0)
		   		throw Empty();
	
		   count--;
		}
		
		
		// Method displayElement: To display an element based on its index entered from the keyboard.
		void displayElement()
		{
			int index;
			
			cout << "Enter the index of the element you want to display => ";
			cin >> index;
			
			// Task 4: Throw a 'NegativeIndex' exception if the user entered a negative value for the index.  (4 marks)
			if (index < 0)
				throw NegativeIndex();
		

			// Task 5: Throw the index value entered by the user if the value is larger than the current number of items held by the array (4 marks)
			if (index >= count)
				throw index;
		
				
				
			cout << "Index: " << index << ", Element: " << data[index] << endl;
		}
};


int main()
{
    Array a;

	a.add(11); 
	cout << "Number 11 has been added. Current number of element = "  << a.getCount() << endl;

	a.add(22); 
	cout << "Number 22 has been added. Current number of element = "  << a.getCount() << endl;

	cout << endl;
	try{
		a.displayElement(); 
	}
	
	// Task 6: Handle the case where the user has entered a negative index. See the example output in Figure 1.2. (3 marks)
	catch(Array:: NegativeIndex){
		throw "Error! You have entered a negative index.";
	}
	
	// Task 7: Handle the case where the user has entered the index that is larger than the valid index. See the example output in Figure 1.3. (4 marks)
	catch (int exceptionIndex){
		cout << "Error! You have entered index value of" << exceptionIndex << "while the current number of elements is" << a.getCount() << endl;
	}
	
	catch (...){}
		
	cout << endl;
	try{
		a.add(33); 
		cout << "Number 33 has been added. Current number of element = "  << a.getCount() << endl;

		a.add(44); 
		cout << "Number 44 has been added. Current number of element = "  << a.getCount() << endl;
	}
	
	// Task 8: Handle the case where an element wants to be added but the array is already full. See the example output in Figure 1.1 to 1.3. (3 marks)
		catch (Array:: Full){
			cout << "The array is full." << endl;
		}
	
	
	catch (...){}
	
	cout << endl;
	try{
		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;

		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;

		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;

		a.remove(); 
		cout << "An element has been removed. Current number of element = "  << a.getCount() << endl;
	}
	
	// Task 9: Handle the case where an element wants to be removed but the array is empty. See the example output in Figure 1.1 to 1.3. (3 marks)
	catch (Array::Empty){
		cout << "The array is empty" << endl;
	}
	
	catch (...){}	

	return 0;

}
