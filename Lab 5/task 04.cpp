/*
Name -> Adina Faraz
Student ID -> 23k-0008

*/

#include<iostream>
using namespace std;

class BankAccount{
	private:
		int accountNumber;
		string accountHolderName;
		double balance;
		
	public:
		BankAccount(int accountNumber, string accountHolderName, double balance)
		{
			this->accountNumber = accountNumber;
			this->accountHolderName = accountHolderName;
			this->balance = balance;
		}
		
		void deposit(double amount)
		{
			this->balance+=amount;
			cout<<"Your current balance is: "<<balance<<endl;
		}
		
		void withdraw(double amount)
		{
			if(amount<balance)
			{
				this->balance-=amount;
				cout<<"Your current balance is: "<<balance<<endl;
			}
			
			else
			{
				cout<<"You are ghareeb sorry!"<<endl;
			}
		}
		
		void display()
		{
			cout<<endl;
			cout<<"Account Number: "<<accountNumber<<endl;
			cout<<"Account Holder Name: "<<accountHolderName<<endl;
			cout<<"Balance: "<<balance<<endl;
			cout<<endl;
		}
};

int main()
{
	BankAccount accounts[3]={BankAccount(845467, "Adina", 5677.9),BankAccount(667889, "Sara", 76777),BankAccount(736677, "Sohail", 98888)};
	for(int i =0; i< 3; i++)
	{
		accounts[i].display();
		cout<<endl;
	}
	
	accounts[2].deposit(500.0);
	accounts[2].display();
	accounts[1].withdraw(200.0);
	accounts[1].display();
}
