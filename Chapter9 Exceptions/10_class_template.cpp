// class template
#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
	Stack(int = 10) ; 
	~Stack() { delete [] stackPtr ; }
	int push(const T&); 
	int pop(T&) ;  // pop an element off the stack
	int isEmpty()const { return top == -1 ; } 
	int isFull() const { return top == size - 1 ; } 
private:
	int size ;  // Number of elements on Stack
	int top ;  
	T* stackPtr ;  
} ;

//constructor with the default size 10
template <class T>
Stack<T>::Stack(int s)
{
	size = s > 0 && s < 1000 ? s : 10 ;  
	top = -1 ;  // initialize stack
	stackPtr = new T[size] ; 
}
 // push an element onto the Stack 
template <class T>
int Stack<T>::push(const T& item)
{
	if (!isFull())
	{
		stackPtr[++top] = item ;
		return 1 ;  // push successful
	}
	return 0 ;  // push unsuccessful
}

// pop an element off the Stack
template <class T> 
int Stack<T>::pop(T& popValue) 
{
	if (!isEmpty())
	{
		popValue = stackPtr[top--] ;
		return 1 ;  // pop successful
	}
	return 0 ;  // pop unsuccessful
}

int main()
{
	typedef Stack<float> FloatStack ;
	typedef Stack<int> IntStack ;

	FloatStack fs(5) ;
	float f = 1.1 ;
	cout << "Pushing elements onto fs" << endl ;
	while (fs.push(f))
	{
		cout << f << ' ' ;
		f += 1.1 ;
	}
	cout << endl << "Stack Full." << endl
	<< endl << "Popping elements from fs" << endl ;
	while (fs.pop(f))
		cout << f << ' ' ;
	cout << endl << "Stack Empty" << endl ;
	cout << endl ;

	IntStack is ;
	int i = 1.1 ;
	cout << "Pushing elements onto is" << endl ;
	while (is.push(i))
	{
		cout << i << ' ' ;
		i += 1 ;
	}
	cout << endl << "Stack Full" << endl
	<< endl << "Popping elements from is" << endl ;
	while (is.pop(i))
			cout << i << ' ' ;
	cout << endl << "Stack Empty" << endl ;
	return 0;
}
