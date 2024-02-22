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
			if(balance<amount)
			{
				cout<<"Not sufficient amount!"<<endl;
			}
			
			else
			{
				this->balance-=amount;
				cout<<"Your current balance is: "<<balance<<endl;
			
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
	BankAccount accounts[3]={BankAccount(845467, "Adina", 0),BankAccount(667889, "Sara", 76777),BankAccount(736677, "Sohail", 98888)};
	for(int i =0; i< 3; i++)
	{
		accounts[i].display();
		accounts[i].deposit(00.0);
		accounts[i].withdraw(300.0);
		cout<<endl;
	}
	

	//accounts[2].display();
	
	//accounts[0].display();
}
