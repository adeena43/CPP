#include<iostream>
using namespace std;

class DarazPersonData{
	protected:
		string lastName;
		string firstName;
		string address;
		string city;
		string state;
		string zip;
		string phone;
		
	public:
		DarazPersonData(string last, string first, string address, string city, string state, string zip, string phone)
		{
			this->lastName= last;
			this->firstName= first;
			this->address=address;
			this->city=city;
			this->state = state;
			this->zip=zip;
			this->phone =phone;
		}
		
		string getLastName()
		{
			return lastName;
		}
		
		string getFirstName()
		{
			return firstName;
		}
		string getAddress()
		{
			return address;
		}
		
		string getcity()
		{
			return city;
		}
		
		string getstate()
		{
			return state;
		}
		
		string getZip()
		{
			return zip;
		}
		
		string getPhone()
		{
			return phone;
		}
};

class DarazCustomerData:public DarazPersonData{
	protected:
		int customerNumber;
		int loyaltyPoints;
		
	public:
		DarazCustomerData(string last, string first, string address, string city, string state, string zip, string phone, int customerNumber, int loyaltyPoints):DarazPersonData(last, first, address, city, state, zip, phone),customerNumber(customerNumber), loyaltyPoints(loyaltyPoints)
		{
		}
		
		int getCustomerNumber()
		{
			return customerNumber;
		}
		
		int getLoyaltyPoints()
		{
			return loyaltyPoints;
		}
		
		void setLoyaltyPoints(int newPoints)
		{
			this->loyaltyPoints = newPoints;
		}
};

class DarazLoyaltyProgram{
	private:
		DarazCustomerData cust;
	public:
		DarazLoyaltyProgram(DarazCustomerData& customer) : cust(customer) {}
		 
		void addLoyaltyPoints(int pointsToAdd)
		{
			if(pointsToAdd>=0)
			{
				int currPoints = cust.getLoyaltyPoints();
				cust.setLoyaltyPoints(pointsToAdd+currPoints);
			}
			
			else
			{
				cout<<"Error: Negative points"<<endl;
			}
		}
		
		void redeemPoints(int points)
		{
			int currPoints= cust.getLoyaltyPoints();
			if(currPoints>=points)
			{
				cust.setLoyaltyPoints(currPoints-points);
			}
			else
			{
				cout<<"Points can not be redeemed"<<endl;
			}
		}
		
		void displayTotalLoyaltyPoints()
		{
			cout<<endl<<"-------DISPLAYING TOTAL LOYALTY POINTS---------"<<endl;
			cout<<cust.getFirstName()<<" "<<cust.getLastName()<<endl;
			cout<<"customer number: "<<cust.getCustomerNumber()<<endl;
			cout<<"LOYALTY POINTS: "<<cust.getLoyaltyPoints();
		}
};

int main()
{
	cout<<"Adina Faraz"<<endl<<"23k-0008"<<endl;
	DarazCustomerData customer("Hussain","Anwar", "Main road, street 5", "Karachi","State","B1234", "034501568788", 45,1000);
	DarazLoyaltyProgram prog(customer);
	prog.displayTotalLoyaltyPoints();
	prog.addLoyaltyPoints(100);
	prog.displayTotalLoyaltyPoints();
	prog.redeemPoints(1100);
	prog.displayTotalLoyaltyPoints();
}
