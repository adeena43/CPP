#include<iostream>
#include<string.h>
using namespace std;

class ValidateString{
	private:
		char* ptr;
		char* str;
	
	public:
		ValidateString(char* sentence)
		{
			str = new char[strlen(sentence)+1];
			strcpy(str, sentence);
		}
		
		~ValidateString(){
			delete[] str;
		}
		
		const void checkString()
		{
			ptr = str;
			while(*ptr!='\0')
			{
				if(!(((*ptr)<91  && (*ptr)>64 )||((*ptr)<123  && (*ptr)>96 )))
				{
					cout<<"Invalid string"<<endl;
					return;
				}
				
				ptr++;
			}
		}
};

int main()
{
	ValidateString string1("Hem1@looo");
	string1.checkString();
	
	ValidateString string2("Helooo");
	string2.checkString();
	
	ValidateString string3("Hemlooo mic test 1234...");
	string3.checkString();
}
