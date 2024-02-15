/*Construct a class representing a Book, encompassing attributes like name, author, ISBN number,
and total page count, along with a variable tracking the number of pages read. Tasks include
defining constructors for the Book class - one default constructor and another parameterized
constructor initializing all attributes. Values can be hardcoded within the main function.
Additionally, implement a method to update the pages read, triggering a display of "You have
finished the book" when all pages are read. This method should be called from the main
function to monitor reading progress.*/

#include<iostream>
using namespace std;

class Book{
	string name;
	string author;
	string isbn;
	int totalpgs;
	int count;		// number of pages read yet
	
	public:
		Book(){
			name = "Unknown";
			author = "Unknown";
			isbn = "Unknown";
			totalpgs = 0;
			count = 0;
		}
		
		Book(string name, string author, string isbn, int count, int totalpgs)
		{
			this->name = name;
			this->author = author;
			this->isbn = isbn;
			this->count = count;
			this->totalpgs = totalpgs;
		}
		
		void update(int pgs)
		{
			count+=pgs;
			if(count==totalpgs)
			{
				cout<<"You have read all the pages";
			}
			
			else if(count>totalpgs)
			{
				cout<<"----------------------------------";
				cout<<"Invalid pages entered";
				cout<<"----------------------------------";
				return;
			}
		}
		
		void display()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"ISBN Number: "<<isbn<<endl;
			cout<<"Current pages read: "<<count<<endl;
			cout<<"Total pages read: "<<totalpgs<<endl;
		}
};

int main(){
	
	Book b1("The Valley of fear", "Sherlock Holmes", "098-987-0086-123", 56, 1000);
	b1.display();
	b1.update(1002);
	cout<<endl;
	b1.display();
}
