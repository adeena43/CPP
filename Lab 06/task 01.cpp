/*
Name-> Adina faraz
student ID-> 23k-0008
*/

#include<iostream>
using namespace std;

class BankAccount{
	private:
		int accountId;
		double balance;
		int* transactionHistory;
		int numTransaction;
	public:
		BankAccount(int accountId, double balance, int* transactions, int number){
			this->accountId=accountId;
			this->balance = balance;
			this->numTransaction=number;
			
			transactionHistory=new int[number];
			for(int i =0; i<number;i++)
			{
				this->transactionHistory[i]=transactions[i];
			}
		}
		
		//copy constructor
		BankAccount(BankAccount& obj2)
		{
			this->accountId=obj2.accountId;
			this->balance = obj2.balance;
			this->numTransaction=obj2.numTransaction;
			
			transactionHistory=new int[numTransaction];
			for(int i =0; i<numTransaction;i++)
			{
				this->transactionHistory[i]=obj2.transactionHistory[i];
			}
		}
		
		~BankAccount()
		{
			delete []transactionHistory;
		}
		
		void display()
		{
			cout<<"---------DISPLAYING ACCOUNT DETAILS--------"<<endl;
			cout<<"Account ID: "<<accountId<<endl;
			cout<<"Current Balance: "<<balance<<endl;
			cout<<"Transaction history: "<<endl;
			
			for(int i =0; i<numTransaction; i++)
			{
				cout<<transactionHistory[i]<<"\t";
			}
			cout<<endl;
		}
		
		void updateTransactionHistory(int* newTransactions, int newNumber)
		{
			delete []transactionHistory;
			
			transactionHistory=new int[newNumber];
			
			for(int i =0; i<newNumber; i++)
			{
				transactionHistory[i] = newTransactions[i];
			}
		}
};

int main()
{
	int transactions[]={1200, 130, 500}
	;int size = sizeof(transactions)/sizeof(transactions[0]);
	
	BankAccount account1(123456, 23000, transactions, size);
	BankAccount account2 = account1;
	
	cout<<"Account 1: "<<endl;
	account1.display();
	cout<<"Account 2: "<<endl;
	account2.display();
	
	int newTransactions[]= {-900, 800, 65};
	int newSize = sizeof(newTransactions)/sizeof(newTransactions[0]);
	account1.updateTransactionHistory(newTransactions, newSize);
	
	cout<<"After updating"<<endl;
	cout<<"Account 1: "<<endl;
	account1.display();
	cout<<"Account 2: "<<endl;
	account2.display();
	
	return 0;
}
