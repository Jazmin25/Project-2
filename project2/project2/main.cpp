// Author: Jazmin Onofre
//Assignment: Midterm Project 2
//////////////////////////////////////////////////////////////////////////
//System Libraries
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
//My libraries
#include "ShopClasses.h"
using namespace std;


//Golbal Variables

//Function Prototypes

void ordering();
void SpOrder();
void WPack();
void Mailing();
//FOR THE DO WHILE LOOP
void Menu();
void def(int);
int getN();

int main(int argc, char** argv) 
{
	//variables
	int  inN;
	//Displaying the menu and the store location 
    cout << "\n\nThe Bloom Room\n";
	cout << "1545 Levi Way\nClaremont, CA 91711\n";
	cout <<"______________________________________________\n";

	//displays the menu after choosing an option the menu come back
	do
	{
		Menu();
		inN =getN();
		cout << endl;
	
	switch(inN)
	{
	case 1:
		//DISPLAYS THE ORDER FUNCTION
		ordering();
		break;
	case 2:
		//DISPLAYS THE SPECIAL ORDER FUNCTION
		SpOrder();
		break;
	case 3:
		//DISPLAYS THE WEDDING PACKAGE FUNTION
		WPack();
		break;
	case 4 :
		//DISPLAYS THE FUNCTION TO BECOME A MEMBER OF THE SHOPS NEWSLETTER
		Mailing();
		break;
	 default:   def(inN);
	}
	}while(inN >=1&& inN <5);
  
	
    cin.ignore();
    cin.get();
    return 0;
}
// for Orders the  carries displays the info and then saves the order if the user wishes
//writes to the file if the user wants to save the data
void ordering( )
{
	fstream file;
	// a struct of all the flowers and the prices that are stocked in the store
	DataB db[20]={{"1. Alstroemeria", 40.00},{"2. Agapanthus",  68.00},{"3. Amaryllis", 160.00},
    {"4. Aster",  44.00},{"5. Bird of Paradise" ,80.00},{"6. Calla Lily", 80.00},{"7. Carnation",  15.00},
    {"8. Chrysanthemum",  30.00},{"9. Daffodil", 20.00},{"10. Daisy",  20.00},{"11. Delphinium",  50.00},
    {"12. Ginger ",  80.00},{"13. Gardenia",  180.00},{"14. Gladiolus",  70.00},{"15. Iris",  40.00},
    {"16. Lily",  80.00},{"17. Orchid", 430.00}, {"18. Rose",  40.00},{"19. Sunflower", 75.00},{"20. Tulip",  50.00}};
	//CLASS OBJECT
	Order order;
	
	//VARIABLES
	int NSize;
	int choice, num, total =0;
	string noMsg = "No message";
	string noDel = "Not being delieved";
	string message, to, from, address;
	char delivery, msg, save;
	
	//SHOP ITEMS AND PRICES
	cout << "_______________________________________________" << endl;
    cout << "Name\t\tAmount in Stock\t Price per Stem\n\n";
	cout << "_______________________________________________\n\n";
    for (int i=0; i < 20; i++)
    {
        cout << db[i].Name;
		NSize = db[i].Name.length();
		if ( NSize < 8)
			cout <<"\t\t"<< fixed << showpoint << setprecision(2) << "$ "  << db[i].price<< endl;
		else if (NSize >= 16)
			cout <<"\t"<< fixed << showpoint << setprecision(2) << "$ "  << db[i].price<< endl;
		else
			cout <<"\t\t"<< fixed << showpoint << setprecision(2) << "$ "  << db[i].price<< endl;
		
    }
	cout << "\n\nHow many bouquets would you like to order? ";
	cin >> num;
	//memory allocation
	Order *oR = new Order[num];
	string *N = new string[num];
	int *T = new int[num];
	
	//USER INPUT FOR ORDER
	cout << "\nFrom the list above enter the number of the boquet you wish to buy. ";
	for (int i =0;i < num; i++)
	{
		cout << "\nChoice " << i+1 << ":   " ;
		cin >> choice;
		switch(choice)
		{
		case 1: *(N+i) = "Alstroemeria"; *(T+i) = 40; break;
			case 2: *(N+i) = "Agapanthus"; *(T+i) = 68; break;
			case 3: *(N+i) = "Amaryllis"; *(T+i) = 160; break;
			case 4: *(N+i) = "Aster"; *(T+i) = 44; break;
			case 5: *(N+i) = "Bird of Paradise"; *(T+i) = 80; break;
			case 6: *(N+i) = "Calla"; *(T+i) = 80; break;
			case 7: *(N+i) = "Carnation"; *(T+i) = 15; break;
			case 8: *(N+i) = "Chrysanthemum"; *(T+i) = 30; break;
			case 9: *(N+i) = "Daffodil"; *(T+i) = 20; break;
			case 10: *(N+i) = "Dasiy"; *(T+i) = 20; break;
			case 11: *(N+i) = "Delphinium"; *(T+i) = 50; break;
			case 12: *(N+i) = "Ginger (Red)"; *(T+i) = 80;  break;
			case 13: *(N+i) = "Gardenia"; *(T+i) = 180; break;
			case 14: *(N+i) = "Gladiolus"; *(T+i) = 70; break;
			case 15: *(N+i) = "Iris"; *(T+i) = 40; break;
			case 16: *(N+i) = "Lily"; *(T+i) = 80; break;
			case 17: *(N+i) = "Orchid"; *(T+i) = 430; break;
			case 18: *(N+i) = "Rose"; *(T+i) = 40;  break;
			case 19: *(N+i) = "Sunflower"; *(T+i) = 75; break;
			case 20: *(N+i) = "Tulip"; *(T+i) = 50; break;
		}
	}
	for ( int i =0;i < num; i++)
		total+= *(T+i);
	cin.ignore();

	cout <<"Please enter the name for who the flowers are for. ";
	getline(cin, to);
	cout << "Please enter the name of the sender. ";
	getline(cin, from);
	cout << "Would you like to send a message with the flowers? (Y/N) ";
	cin >> msg;
	order.setMsg(msg);

	if(order.getMsg() == 'Y' )
	{
		cin.ignore();
		cout << "Please enter a message no more than 100 characters.\n";
		getline(cin, message);
		
	}
	else if(order.getMsg() == 'N')
	{
		cout << "We'll skip the message then.";
		order.setMess(noMsg);
	}
	else
		cout << "That answer was not understood.";

	cout << "\nWould you like to have these delivered?(Y/N) ";
	cout << "\nThe fee will be $ 3.00 \n";
	cin >> delivery;
	order.setDel(delivery);

	if(order.getDel() == 'Y')
	{
		cin.ignore();
		cout << "What is the address for the flowers to be delievered to. \n";
		getline(cin, address);
		order.setAdd(address);
		total += 3; 
		cout <<"Total: "<< total;
	}
	else if(order.getDel() == 'N')
	{
		cout << "\nTotal: $ " << total;
		order.setAdd(noDel);
	}
	else
		cout << "That answer was not understood.";
	cout << "\nWould you like to place this order? (Y/N)";
	cin >> save;
	order.setSave(save);
	
	//USING CONSTRUCTOR TO INPUT MOST INFO
	Order ORDER(save, delivery, msg, to, from, address, message);

	if(order.getSave() == 'Y')
	{
		file.open("Order.txt", ios::out | ios::app);
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
		else
		{
			file << "To: " << ORDER.getTo() <<"\nFrom: " << ORDER.getFrom();
			file << "\nAddress: " << order.getAdd();
			file << "\nMessage: " << order.getMess();
			file << "\nFlowers: " ;
			for (int i =0;i<num;i++)
				file << *(N+i) <<", ";
			file << "\nTotal: $" << total;
			file << endl << endl;
			cout <<"Your order was saved.\n";

			file.close();
		}
	}

	else if(order.getSave() == 'N')
	{
		cout << "Order not saved. \n";
		
	}
	else
		cout << "That wasnt understood.";
	//deleting memory
	delete []N;
	delete []T;
	delete []oR;	
	
}
// a function to sspecial order what the store does not carry.

void SpOrder()
{
	fstream file;
	Order sp;
	//variables
	int *SPtr;
	string phone, add, to, from;
	int SpOrder;
	int total=0;
	char ans1;
	string *F, *C;
	 
	cout << "\nHow many flowers would you like to be special ordered?";
	cin >> SpOrder;
	cin.ignore();
	//allocating memory
	Order *ptr = new Order[SpOrder];
	SPtr = new int[SpOrder];
	F = new string [SpOrder];
	C = new string[SpOrder];
	
	
	//inputing flowers names
	for (int i=0;i < SpOrder; i++)
	{
		cout << "Flower Name " << i+1 << ": ";
		getline(cin, *(F+i));
		cout << "Color: ";
		getline(cin, *(C+i));
		cout << "Number of this type of flower: ";
		cin >>*(SPtr+i);
		cin.get();
	}
	for (int i=0;i< SpOrder;i++)
		total += *(SPtr+i);
	cin.ignore();
	
	//USER INPUT FOR NAME, LOCATION ETC
	cout << "Please enter the name of the recipient. ";
	getline (cin, to);

	cout << "Please enter the name of the sender. ";
	getline (cin, from);
	
	cout << "Please enter your address. ";
	getline (cin, add);
	
	cout <<"Please enter you phone number (ex: 9511234567) ";
	getline(cin,  phone);
	sp.setTo(to); 
	sp.setFrom(from); 
	sp.setAdd(add);
	cout << "\nSpecial Order:\n\n";
	cout << "To: " << sp.getTo() <<"\nFrom: "<<sp.getFrom()<< "\nAddress: "<< sp.getAdd() << endl;
	cout << "Phone Number: "<< phone <<endl <<"Flowers: ";
	for ( int i =0;i < SpOrder; i++)
		{
			cout << *(F+i) << "  ";
			cout << *(SPtr+i) << endl;
		}
	//A MESSAGE TO THE BUYER TO WAIT FOR STORE CALL
	cout <<"Price of Flowers: Varies\n";
	cout << "A representative will call you within the day to give you the quote.\n";
	cout << "Shipping will take between 4-6 days ( in state shipping only)\n";
	if ( total <=10)
		cout << "Shipping Cost: $3.99\n";
	else if (total > 10 && total <=25)
		cout << "Shipping Cost: $6.99\n";
	else if (total > 25 && total <= 75)
		cout << "Shipping Cost: $9.99\n";
	else if(total >75 && total <= 100)
		cout << "Shipping Cost: $11.99\n";
	else if (total > 100 && total <=200)
		cout << "Shipping Cost: $13.99\n";
	else 
		cout << "Shipping Cost: 19.99\n";
	cout <<"Would you like to place this order?(Y/N)\n";
	cin >> ans1;
	sp.setSave(ans1);
	
	//SAVING THE FILE
	if(sp.getSave() =='Y')
	{
		file.open("SpecialOrder.txt", ios::out | ios::app);
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
		else
		{
			file  <<"\nName: " <<sp.getTo() <<"\nFrom: "<<sp.getFrom() << "\nAddress: "<<sp.getAdd()
				<< endl << "Phone: " << phone <<endl; 
			for ( int i =0;i < SpOrder; i++)
			{
				file << "Flower: " << *(F+i) << endl;
				file << "Amount: "<< *(SPtr+i) << endl;
				file << "Color: " << *(C+i) << endl;;
			}
			cout <<"Your order was saved.\n";

			file.close();
		}
	}
	else if (sp.getSave() == 'N' )
	{
		cout << "Order not saved\n";
	}
	else
	cout << "That answer was not recognized.";
	//deleting memory
		delete [] SPtr;
		delete [] ptr;
		delete [] F;
		delete [] C;
}



// This function presents a list of wedding packages and their contents
//and lets the user enter their choice and leave a phone number
void WPack()
{
	//variables
	Package p;
	fstream file;
	int num, num2, num3, num4, num5, num6;
	string pckN, flower, fill;
	char ans;
	string color1, color2, color3, name, phone, addr;
	string noDel = "Pickup";
	//wedding packages
	//BRONZE PACKAGE
	cout << "\t\tWedding Packages:\n____________________________________________\n";
	cout << "1. Bronze Package \nIncludes: Brides Bouquet and Grooms Boutonniere\n";
	cout << "Flower Choices:\t 1) Alstroemeria   2) Agapanthus  3) Aster  4) Chrysanthemum";
	cout << "\n5) Delphinium  6) Iris  7) Rose  8)Tulip";
	cout << "\nCost: $125.00 ";

	//SILVER PACKAGE
	cout <<"\n\n2. Silver Package \nIncludes: Brides Bouquet and Grooms Boutonniere\n";
	cout << "Maid of Honor Bouquet and Best Man Boutonniere\n";
	cout << "Flower Choices:\t 9) Calla Lily  10) Ginger  \n11) Gladiolus  12) Lily  13) Sunflowers";
	cout << "\nOr any of the flowers in the Bronze package + 20 extra flowers";
	cout << "\nCost: $250.00";

	//GOLD PACKAGE
	cout << "\n\n3. Gold Package \nIncludes Brides Bouquet and Grooms Boutonniere\n";
	cout << "Maid of Honor Bouquet and Best Man Boutonniere\n";
	cout << "5 Bridesmaids and Groomsmen Bouquets and Boutonnieres\n";
	cout << "Flower Choices:\t14) Amaryllis  15) Gardenia  16) Freesia  17) Ranunculus";
	cout << "\n Or any of the flowers from the Bronze package + 40 extra flowers.";
	cout << "\nOr any of the flowers from the Silver package + 20 extra flowers.";
	cout << "\nOr any of the flowers from the Gold package + 15 extra flowers.";
	cout << "\nCost: $300.00";

	//PLAT PACKAGE
	cout <<"\n\n4. Platinum Package \nIncludesBrides Bouquet and Grooms Boutonniere\n";
	cout << "Maid of Honor Bouquet and Best Man Boutonniere\n";
	cout << "5 Bridesmaids and Groomsmen Bouquets and Boutonnieres\n";
	cout << "Flower Choice:\t18) Orchid";
	cout << "\nOr any of the flowers in the Bronze package + 60 extra flowers";
	cout << "\nOr any of the flowers in the Silver package + 35 extra flowers";
	cout << "\nOr any of the flowers in the Gold package + 15 extra flowers";
	cout << "\nCost: $550.00\n\n";
	cout << "\n*Bouquets include 20 flowers plus a filler of your choice.";
	cout << "\n\nFiller Choices:\t 19) Baby's Breath  20) Carnation  21) Daisy  22) Daffodils  23)None";
	cout << "\nWhat package would you ike to order? ";
	cin >> num;

	//switch case for input ON FLOSWER, FILLLER, COLORS AND RIBBON
	switch(num)
	{
	case 1:
		pckN = "Bronze Package";
		p.setTotal(125);
		cout << "Please enter the number of the flower. ";
		cin >> num2;
	switch(num2)
	{
		case 1:
			flower = "Alstroemeria"; p.setFlower(flower);
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
		switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 2:
			flower = "Agapanthus"; p.setFlower(flower);
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 3:
			flower = "Aster"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 4:
			flower = "Chrysanthemum"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 5:
			flower = "Delphinium"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 6:
			flower = "Iris"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 7:
			flower = "Rose"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 8:
			flower = "Tulip"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
	}break;
	case 2:
		pckN = "Silver Package";
		p.setTotal(250); 
	cout << "Please enter the number of the flower. ";
		cin >> num2;
	switch(num2)
	{
		case 9:
			flower = "Calla Lily"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 10:
			flower = "Ginger"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 11:
			flower = "Gladiolus"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 12:
			flower = "Lily"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 13:
			flower = "Sunflowers"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
	}break;
	case 3:
		pckN = "Gold Package";
		p.setTotal(375);
	cout << "Please enter the number of the flower. ";
		cin >> num2;
	switch(num2)
	{
		case 14:
			flower = "Amaryllis"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 15:
			flower = "Gardenia"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 16:
			flower = "Freesia"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
		case 17:
			flower = "Ranunculus"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
	}break;
	case 4: 
		pckN = "Platinum Package";
		p.setTotal(550);
		cout << "Please enter the number of the flower. ";
		cin >> num2;
	switch(num2)
	{
		case 18:
			flower = "Orchid"; p.setFlower(flower); 
			cout <<"Please enter the number of the filler you want. ";
			cin >> num3;
			switch(num3)
		{	case 19: fill ="Baby's Breath"; p.setFill(fill); break;  
			case 20: fill ="Carnation"; p.setFill(fill); break;
			case 21: fill ="Daisy"; p.setFill(fill); break;
			case 22: fill ="Daffodils"; p.setFill(fill); break;
			case 23: fill ="None"; p.setFill(fill); break;
		}break;
	}break;
}
	cin.ignore();
	cout << "We offer our flowers in the following colors : \n1) White  2) Pink  3) Purple  4) Red  5) Blue";
	cout << "\nPlease enter the number of the primary color for your flowers. ";
	cin >> num4;
	switch(num4)
	{	case 1: color1 = "White"; p.setPCol(color1); break;
		case 2: color1 = "Pink"; p.setPCol(color1); break;
		case 3: color1 = "Purple"; p.setPCol(color1); break;
		case 4: color1 = "Red"; p.setPCol(color1); break;
		case 5: color1 = "Blue"; p.setPCol(color1); break;
	}
	cout << "\nPlease enter the number of the secondary color for your flowers. ";
	cin >> num5;
	switch(num5)
	{	case 1: color2 = "White"; p.setSCol(color2); break;
		case 2: color2 = "Pink"; p.setSCol(color2); break;
		case 3: color2 = "Purple"; p.setSCol(color2); break;
		case 4: color2 = "Red"; p.setSCol(color2); break;
		case 5: color2 = "Blue"; p.setSCol(color2); break;
	}
	cout << "\nPlease enter the number of the color for the ribbon on your flowers. ";
	cin >> num6;
	switch(num6)
	{	case 1: color3 = "White"; p.setRCol(color3); break;
		case 2: color3 = "Pink"; p.setRCol(color3); break;
		case 3: color3 = "Purple"; p.setRCol(color3); break;
		case 4: color3 = "Red"; p.setRCol(color3); break;
		case 5: color3 = "Blue"; p.setRCol(color3); break;
	}
	//MORE USER INFO INPUT
	cout << "Please leave your name and phone number for us to call you back.";
	cin.ignore();
	cout << "\nName: ";
	getline(cin, name);
	p.setTo(name);
	cout << "\nNumber: ";
	getline(cin, phone);
	p.setPhone(phone);
	cout << "Please enter your address.";
		getline(cin, addr);
		p.setAdd(addr);	
	
	cout << "\nWould you like to place your order? (Y/N) ";
	cin >> ans;
	p.setSave(ans);
	if(p.getSave() =='Y')
	{
		file.open("WeddingOrder.txt", ios::out | ios::app);
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
		else
		{
			cout << "Your order is being saved.\n";
			file << "Name: " << p.getTo();
			file << "\nPhone Number: " << p.getPhone();
			file << "\nPackage Name: " << pckN << "\nFlower Name: " << p.getFlower() << " in the color " << p.getPCol()
				<<"\nFiller Flower: " << p.getFill() << " in the color " << p.getSCol()
				<< ".\nWith " << p.getRCol() << " ribbons."  << "\nAddress: " << p.getAdd()
				<< "\nTotal: $ " << p.getTotal() << endl << endl;
			file.close();
		}
	}
	else if(p.getSave() =='N')
		cout << "Your order was cancelled.\n";
	else
		cout <<"That was not recognized";	
	
	
}

//FUNCTION FO NEWSLETTER

void Mailing()
{
	string N, E;
	fstream file;
	cin.ignore();
	cout << "\nThank you for signing up for our Newsletter. ";
	bool check;
	// CHECKING FOR GIBBERISH IN THE NAME
	do {
		cout << "\nPlease enter your name. ";
		getline(cin,N);
		check = true;
		for(int i = 0; (i < N.length()) && (check == true); i++)
		{
			if(isdigit(N[i]))
			{
				check = false;
			}
			else
			{
				check = true; 
			}
	
		}
	
	}while(check == false);

	cout <<"\nPlease enter your email. ";
	getline(cin, E);

	MailingList<string> mail(E,N);
	
	//DISPLAYING INPUT
	cout << "\nName: " << mail.getName() << "\nEmail: " << mail.getEmail();
	cout <<"\nYou will now be added to our mailing list for our monthly newsletter.\n";

	//AUTOMATICALLY SAVING INPUT
		file.open("Newsletter.txt", ios::out | ios::app);
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
		else
		{
			file << "\nName: " << mail.getName() << "\nEmail: " << mail.getEmail() <<endl;
			file.close();
		}
}

void def(int inN)
{
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

int getN()
{
        int inN;
        cin>>inN;
        return inN;
}

void Menu()
{
	//MENU OPTIONS
    cout << "______________________________________________";
		cout << "\n\n\t\t    Menu: \n______________________________________________";
		cout << "\n\n\t 1: Order a Bouquet \n\t 2: Special Order\n";
		cout << "\t 3: Wedding Packages \n\t 4: Recieve our Newletter \n\t Anything else to exit. ";
		cout << "\n______________________________________________";
		cout << "\nPlease enter the choice number of your command.\n";
}