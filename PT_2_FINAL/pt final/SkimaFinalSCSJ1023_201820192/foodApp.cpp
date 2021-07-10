#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define POUNDTOGRAM 453.59
#define USTOMYR 4.13
	
class Food 
{
	string desc;
	double price;

	public:
		Food(string desc, double price) {
			this->desc = desc; 
			this->price = price; 
		}
		
		string getDesc() const { return desc; } 
		double calcPriceInRinggit() const { return price * USTOMYR; }
	 	virtual void displayInfo() { 
			cout << fixed << setprecision(2)
				 << "Price: USD" << price << endl
				 << "Price converted to Malaysian = MYR" << calcPriceInRinggit()
				 << endl << endl;
		}
		double getPrice()
		{
			return price;
		}
};

class Vegetable : public Food 
{
	int weight;

	public:
		Vegetable(string desc, double price, int weight) :Food(desc,price){ 
			this->weight = weight;
		}
		
		double calcWeightInGram() const { return weight * POUNDTOGRAM; }

		 void displayInfo() 
		{
			cout << "Food description: " << getDesc() << endl
				 << "Weight in pound: " << weight << " pound" << endl
				 << "Weight in gram: " << calcWeightInGram() << " grams" <<endl
				 << "Price: USD" << getPrice() << endl
				 << "Price converted to Malaysian = MYR" << calcPriceInRinggit() << endl;
		}
};

class CannedFood : public Food 
{
	string type, expDate;

	public:
		CannedFood(string desc, double price, string type, string expDate):Food(desc,price) { 
			this->type = type;
			this->expDate = expDate;
		}

	 	 void displayInfo() 
		{
			cout << "Food description: " << getDesc() << endl
				 << "Canned Food Type: " << type << endl
				 << "Expired date: " << expDate << endl
		 		 << "Price: USD" << getPrice() << endl
				 << "Price converted to Malaysian = MYR" << calcPriceInRinggit() << endl;
		}
};

int main()
{	const int size=5;
	Food *f[size] = { new Vegetable("Broccoli", 1.6, 3), 
				  new Vegetable("Tomato", 1.4, 5),
				  new CannedFood("Mushroom Soup", 5.78, "Soups", "12/09/2020"),
				  new Vegetable("Cabbage", 0.7, 4.5),
				  new CannedFood("Sliced Yellow Cling Peaches", 9.58, "Fruit", "01/02/2021")};

	for (int i = 0; i < size; i++) 
	{
		cout << "Food #" << (i + 1) << endl;
		f[i]->displayInfo();
		cout<<endl; 
	}
		
	return 0;
}
