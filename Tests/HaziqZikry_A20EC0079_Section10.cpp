/* Skill-Based Test 

Mohamad Haziq Zikry Bin Mohammad Razak		-A20EC0079
Section 10
Lecturer's Name: Dr. Nies Hui Wen

*/

//Header files
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>


using namespace std;

//Name class - task1 - composition
class Name { 
    private:
        string firstName, lastName;
       
    public:
        //constructor with arguments
        Name (string first, string last){
            firstName = first;
            lastName = last;
        }
        //Define getFullName function. The function returns the full name. (
        string getFullName(){
            return firstName + " " + lastName ;
        }

};

//Product class - task2 - aggregation
class Product {
    private:
        string name, category;
        double price;
        int quantity;
		
	public:
        //default constructor
        Product (){
            name = "";
            category = "";
            price = 0.0;
            quantity = 0;
        }
        //Define constructor with arguments. Initialize all the member variables for the class except quantity with the passed arguments
        Product (string n, string cat, double p){
            name = n;
            category = cat;
            price = p;
        }

        //Accessor functions
        string getName() const {return name;}
        string getCategory() const {return category;}
        double getPrice() const {return price;}
        int getQuantity() const {return quantity;}

        //Mutator functions
        void setQuantity(int quan) {quantity = quan;}	

};

//Customer class - task3 - compostion & aggregation
class Customer{
    private:
        string address;
        int numProduct;
        Name CustomerName;

        //1..10 (multiplicity)
        Product *product[10];
    public:
        //Define constructor with arguments
        Customer (string, string, string);
           
        
        //Inline member functions
        void buy(Product pr, int quan){
            if (quan < 69){
                product[numProduct] = &pr;
                product[numProduct]-> setQuantity(quan);
                numProduct++;
            }
            else
            {
                cout << "Sorry!! You already reached the maximum number of products purchased" << endl;
            }
        }
        void print(){

            double totalPrice = 0.0;
            cout << "Name   : " << CustomerName.getFullName() << endl;
            cout << "Address: " << address << endl;
            cout << "Number of products purchased: " << numProduct << endl;
            cout << endl;
            cout << "No\tProduct Name\tCategory\tQuantity   Unit Price(RM)   Amount(RM)" << endl;

            //set the decimal to 2 decimal paces
            cout << left << fixed << setprecision(2);
            for (int i=0; i< numProduct;i++)
            {   
                //total price formula
                totalPrice = totalPrice + product[i]->getPrice()*product[i]->getQuantity();
                //output
                cout << setw(8) << i+1;
                cout << setw (16) << product[i]->getName() << setw(20) << product[i]-> getCategory();
                cout << setw (12) << product[i]->getQuantity() << setw(14) << product[i]-> getPrice();
                cout << setw(9) << product[i]->getPrice()*product[i]->getQuantity() << endl;
                }
                cout << endl;
                cout << "Total price = RM " << totalPrice << endl;

        }
       
};

//Define Customer constructor with arguments
Customer::Customer (string first, string last, string NewAddress): CustomerName (first, last) { 
            address = NewAddress;
            numProduct = 0;
        }


//Main Function
int main () {

    Customer cust("Amir", "Jalil", "Masai, Johor");
    Product p1("Jacob", "Biscuit", 14.8);
    Product p2("Twister", "Drink", 7.5);
    Product p3("Ayamas", "Nugget", 18.4);
    Product p4("Oreo", "Biscuit", 3.8);
    cust.buy(p4, 5);
    cust.buy(p2, 4);
    cust.buy(p3, 2);
    cust.buy(p1, 3);
    cust.print();
    return 0;
}

