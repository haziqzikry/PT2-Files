/* 
Name: Mohamad Haziq Zikry Bin Mohammad Razak		
Matric ID: A20EC0079
Section 10
*/

#include <iostream>
#include <iomanip>
using namespace std;

class TennisShop {
    private:
        string brand;
        double price;
        int quantity;
    public:
        TennisShop() {}

        TennisShop(int quantity) {
        this->quantity = quantity;
        }

            void setBrandPrice(string brand, double price) {
            this->price = price;
            this->brand = brand;
        }

        string getBrand() { return brand; }
        double getPrice() { return price; }
        int getQuantity() { return quantity; }

        virtual void display() = 0;
        virtual double calcPrice() = 0;
};

class Racket : public TennisShop{
    private:
        //task a (i)
        int racketType;
    
    public:
        //task a (ii)
        Racket() {}

        //task a (iii)
        Racket (int racketType, int quantity) : TennisShop(quantity){
            this-> racketType = racketType;
        }

        //task a (iv)
        void display(){
            string NameOfRacketType;
            if (racketType == 1){  
                setBrandPrice("Wilson", 569.70);
                NameOfRacketType = "Junior Tennis Racket";
            }
            else if (racketType == 2){
                setBrandPrice("Yonex", 719.70);
                NameOfRacketType = "Beginners Tennis Racket";
            }
            else if (racketType == 3){
                setBrandPrice("Yonex", 1289.70);
                NameOfRacketType = "Advanced Tennis Racket";
            }
            else if (racketType == 4){
                setBrandPrice("Dunlop", 989.70);
                NameOfRacketType = "All Tennis Racket";
            }

            cout << "Tennis Racket" << endl;
            cout << "Brand    : " << getBrand() << endl;
            cout << "Type     : " << NameOfRacketType << endl;
            cout << fixed << setprecision(2);
            cout << "Price    : RM " << getPrice() << endl;
            cout << "No Discount!" << endl;
            cout << "Quantity : " << getQuantity() << endl;
            cout << "Subtotal : RM " << calcPrice() << endl;
            
        }    
        //task a (v)
        double calcPrice(){
            return getPrice() * getQuantity();
        }

};

class Ball : public TennisShop{
    private:
        //task b(i)
        int numBalls;
        int ballId;
    public:
        
        //task b(ii)
        Ball(){}

        //task b(iii)
        Ball (int ballId, int quantity) : TennisShop(quantity){
            this-> ballId = ballId; 
         
            // how many tubes
            switch (ballId){
                case 1:
                        numBalls = 4;
                        break;
                case 2:
                        numBalls = 3;
                        break;
                case 3:
                        numBalls = 4;
                        break;                
                case 4:
                        numBalls = 3;
                        break;
            }
        }

        //task b(iv)
        double calcDisc(){
            return getPrice() * 85/100;
        }

        //task b(v)
        void display(){
            string BallDescription;
            if (ballId == 1){  
                setBrandPrice("Wilson", 38.40);
                BallDescription = "Roland Garros All Court";
            }
            else if (ballId == 2){
                setBrandPrice("Wilson", 28.80);
                BallDescription = "US Open";
            }
            else if (ballId == 3){
                setBrandPrice("Dunlop", 81.00);
                BallDescription = "Fort Max TP KNLTB";
            }
            else if (ballId == 4){
                setBrandPrice("Dunlop", 33.00);
                BallDescription = "Fort All Court";
            }

            cout << "Tennis Ball" << endl;
            cout << "Brand      : " << BallDescription << endl;
            cout << "Description: " << getBrand() << endl;
            cout << fixed << setprecision(2);
            cout << "Price      : RM " << getPrice() << " for 4 balls per tube" << endl;
            cout << "Discount   : 15.00%" << endl;
            cout << "Quantity   : " << getQuantity() << endl;
            cout << "Subtotal   : RM " << calcPrice() << endl;
        } 

        //task b(vi)
        double calcPrice(){
            return calcDisc() * getQuantity();
        }
};

class Customer{
    private:
        //task c(i)
        string CustName;
        TennisShop *itemList[10];
        int numOfItem;
    public:
        
        //task c(ii)
        Customer(string CustName){
            this-> CustName = CustName;
            numOfItem = 0;
        }

        //task c(iii)
        string getName() { return CustName; }

        //task c(iv)
        //codes for buy function that update the pointers array named itemList to include the new pointer of TennisShop in the array
        void buy(TennisShop *tennis){
            itemList[numOfItem] = tennis;
            numOfItem++;
        }

         //task c(v)
        void print(){

            double total;
            cout << "LIST OF TENNIS ITEMS BOUGHT\n"; 
            for (int i = 0; i < numOfItem; i++){
                cout << endl << "----- Item #" << i+1 << " -----" << endl;
                itemList[i]-> display();
                total += itemList[i]-> calcPrice();
            }

            cout << fixed << setprecision(2) << endl << "TOTAL: RM " << total << "\n\n";
        }

};

//task d
int displayMainMenu() {
    int choice;
    cout << "==========[MENU]============\n"
         << " [1] Buy item\n"
         << " [2] Print all items\n"
         << " [3] Exit\n"
         << "============================\n"
         << "Choice: ";
    cin >> choice;
    return choice;
    }

int displayRacketMenu() {
    int choice;
    cout << " [1] Wilson: Junior Tennis Racket\n"
         << " [2] Yonex: Beginners Tennis Racket\n"
         << " [3] Yonex: Advanced Tennis Racket\n"
         << " [4] Dunlop: All Tennis Racket\n"
         << "Choice: ";
    cin >> choice;
    return choice;
    }

int displayBallMenu() {
    int choice;
    cout << " [1] Wilson: Roland Garros All Court\n"
         << " [2] Wilson: US Open\n"
         << " [3] Dunlop: Fort Max TP KNLTB\n"
         << " [4] Dunlop: Fort All Court\n"
         << "Choice: ";
    cin >> choice;
    return choice;
}

//task e
int main() {
    TennisShop *p;
    Customer c("ARIF AIMAN");

    //Complete your function start from here
    //Define any suitable variables for the program
    //Write the codes based on the tasks listed in (e)
    
    int menu1;
    int menu2, menu3;
    int quantity;

    //task e (i)
    cout << "WELCOME " << c.getName() << "\n\n" ;

    //task e (ii)
    do{

        menu1 = displayMainMenu();
        
        //task e (iii-1)
        if (menu1 == 1){

                cout << endl << "<< Item to buy >>" << endl;
                cout << "  [1] Racket" << endl;
                cout << "  [2] Ball" << endl;
                cout << "Choice: ";
                cin >> menu2;

                    if (menu2 == 1){
                        
                        cout << endl << "*** Racket ***" << endl;
                        menu3 = displayRacketMenu();
                         //task e (iii -2)
                        cout << "Quantity: ";
                        cin >> quantity;
                         //task e (iii -3)
                        p = new Racket (menu3, quantity);

                    }

                    else if (menu2 == 2){
                 
                        cout << endl << "*** Ball ***" << endl;
                        //task e (iii -2)
                        menu3 = displayBallMenu ();
                        cout << "Quantity: ";
                        cin >> quantity;
                        //task e (iii -3)
                        p = new Ball (menu3, quantity);

                    }
                     c.buy(p);
                     cout << "\n";
            }
        //task e (iii-1)
        else if (menu1 == 2){
                //task e (iv)
                cout << "\n";
                c.print();
                cout << "\n";
        }
        //task e (iii-1)
        else if (menu1 == 3){
                //task e (v)
                cout << endl << "Thank you for using this system ;)" << endl;
        }
        else{
                cout << endl << "Invalid input. Try again!" << endl << endl;
        } 

    } while (menu1 !=3);  
}

