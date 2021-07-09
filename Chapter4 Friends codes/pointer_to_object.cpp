/* Pointer to Object: This Pointer: InfoBrother:*/
#include<iostream>
using namespace std;
 
class Date
{
    private:
        int dd, mm, yy;
    public:
        Date() //default constrctor:
        {
            dd = mm = yy = 0;
        }
        void getDate(int d, int m, int y) 
        {
            dd = d;
            mm = m;
            yy = y;
        }
        void printDate(void)
        {
            cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
        }
};
 
int main()
{   
    Date tarikh;  
    Date *dateptr; 
 
    cout<<"Initialize data members using object, with 12/4/2021"<<endl;
    tarikh.getDate(12,04,2021);   //12/4/2021
 
    cout<<"        \tPrint member using object: ";
	tarikh.printDate();   //12/4/2021
	
    dateptr = &tarikh; //Date *dateptr;  //i=10 &i=address *iptr=10 ptr=address
    
    cout<<"\tPrint member using object pointer: ";
	dateptr->printDate(); //date 12/4/2021
 
    cout<<"\nInitialize data members using object pointer, with 14/4/2021"<<endl;
    dateptr->getDate(14,04,2021); //14/4/2021
    
    cout<<"                 \tPrint member using object: ";
	tarikh.printDate(); //12 or 14
 
    cout<<"               Print members using object pointer: ";
	dateptr->printDate(); //14
	
	cout<<"\n(*dateptr).printDate(); = ";
	(*dateptr).printDate(); // access public members/functions
	cout<<"\n(&tarikh)->printDate(); = ";
	(&tarikh)->printDate();
 
 	cout<<"\nDate *dat=&tarikh; = ";
    Date *dat=&tarikh; 
    (*dat).getDate(11,04,2021);
    (*dat).printDate();
    return 0;
}
