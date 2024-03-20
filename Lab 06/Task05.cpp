/*Name->Adina Faraz
  Student ID-> 23k-008
  */
  
#include<iostream>
using namespace std;

class Courses{
	string code;
	string name;
	int creditHours;
	
	public:
	Courses(string code, string name, int creditHours) : code(code), name(name), creditHours(creditHours){}
	int getCreditHours() const {
        return creditHours;
    }
    string getCode() const {
        return code;
    }	
};

class Student{
	private:
		string ID;
		string name;
		int curr = 0;
		Courses* courses[10];
		
	public:
		Student(string ID, string newName)
		{
			this->ID=ID;
			this->name = newName;
		}
		
		void enroll(Courses& course)
		{
			courses[curr] = new courses();
			courses[curr] = &course;
			curr++;
		}
		
		void drop(Courses& course)
		{
			bool found = false;
			for (int i = 0; i<curr; ++i){
				if (courses[i]->getCode() == course.code){
					delete *courses[i];
					for(int j = i; j < curr - 1; j++) // Shift elements to fill the gap
                    courses[j] = courses[j + 1];
                curr--;
                break;
            }
				}
				 if(!found){
            cout << "This course was not enrolled." << endl;
			}
			
		int getTotalCreditHours (){
			int total;
			
			for (int i = 0; i<curr; i++)
				total += courses[i]->creditHours;
			return total;
		}
		
		void printEnrolledCourses(){
			for (int i = 0; i<curr; i++)
				 cout << courses[i]->creditHours << endl;

		}
		~Student(){
			for (int i = 0; i<curr; i++)
				delete *courses[i];	
		}
};

int main()
{
	Courses c1("EW", "el1002", 2);
	Courses c2("CAAG", "mt1003", 3);
	Courses c3("oop-lab", "cs11919", 1);
	
	Student s1("23k-0022", "Arwa");
	s1.enroll(c1);
	s1.enroll(c2);
	s1.enroll(c3);
	s1.printEnrolledCourses();
	s1.drop(c1);
	s1.printEnrolledCourses();
}
