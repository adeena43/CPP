#include<iostream>
using namespace std;

class RollerCoaster{
private:
	string name;
	float height;
	float length;
	float speed;
	int capacity;
	int CurrentNumRiders;
	bool RideInProgress;

public:
	RollerCoaster():name("ROller Coaster"), height(500), length(2000), capacity(20), RideInProgress(false)
	{
	
	}


	RollerCoaster(string name, float height, float length, float speed, int capacity, int CurrentNumRiders)
	{
		this->name = name;
		this->height =height;
		this->length = length;
		this->speed = speed;
		this->capacity = capacity;
		this->CurrentNumRiders = CurrentNumRiders;
		
		if(capacity<3)
		{
			cout<<"Initially the capcity is not suffiecient (it is less than 3)"<<endl;
			capacity = 4;
		}
		
		if((capacity%2!=0) && (capacity%3!=0))
		{
			cout<<"Rounding the capacity of people to the closest multiple of 2"<<endl;
			capacity = ((capacity+1)/2)*2;
		}
		}
		
	string getName()
	{
		return name;
	}
	
	float getHeight()
	{
		return height;
	}
	
	float getLength()
	{
		return length;
	}
	
	float getSpeed()
	{
		return speed;
	}
	
	int getCapacity()
	{
		return capacity;
	}
	
	int getCurrentNumRiders()
	{
		return CurrentNumRiders;
	}
	
	bool getProgress()
	{
		return RideInProgress;
	}
	
	void setName(string newName)
	{
		this->name = newName;
	}
	
	void setHeight(float newHeight)
	{
		this->height = newHeight;
	}

	void setLength(float newLength)
	{
		this->length = newLength;
	}

	void setspeed(float newSpeed)
	{
		this->speed = newSpeed;
	}
	
	void setCapacity(int newCapacity)
	{
		this->capacity = newCapacity;
		
		if(capacity<3)
		{
			cout<<"Initially the capcity is not suffiecient (it is less than 3)"<<endl;
			capacity = 4;
		}
		
		if((capacity%2!=0) && (capacity%3!=0))
		{
			cout<<"Rounding the capacity of people to the closest multiple of 2"<<endl;
			capacity = ((capacity+1)/2)*2;
		}
	}


	void setCurrentNumRiders(int moreRiders)
	{
		this->CurrentNumRiders = moreRiders;
	}
	
	void setProgress(bool newState)
	{
		this->RideInProgress = newState;
	}
	
	int setRiders(int passengers)
	{
		if(getProgress()==false)
		{
			if(passengers>capacity)
			{
				int remaining = passengers - capacity;
				setCurrentNumRiders(passengers-capacity);
				return remaining;
			}
			else
			{
				setCurrentNumRiders(passengers);
				cout<<"All passengers are seated successfully"<<endl;
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	
	int startRide()
	{
		if(getProgress()==false)
		{
			if(CurrentNumRiders==capacity)
			{
				setProgress(true);
				cout<<"Ride started successfully"<<endl;
			}
			else
			{
				int emptySeats = capacity - CurrentNumRiders;
				return emptySeats;	
			}
		}
		else
		{
			return -1;
		}
	}
	
	void stopRide()
	{
		if(getProgress() == true)
		{
			setProgress(false);
			cout<<"Ride stopped successfully"<<endl;
		}
		else
		{
			cout<<"Ride is not in progress yet"<<endl;
		}
	}
	
	void unloadRiders()
	{
		if(getProgress()==false)
		{
			this->CurrentNumRiders = 0;
			cout<<"Passengers unloaded successfully"<<endl;
		}
		else
		{
			cout<<"Passengers can not be unloaded because the ride is in progress"<<endl;
		}
	}
	void accelerate(int rollNumber) {
        int lastNonZero = rollNumber % 10;

        speed += lastNonZero;

        cout << "Accelerating! New speed: " << speed << endl;
    }
    void applyBrakes(int rollNumber) {
        
        int firstNonZero;

        while (rollNumber >= 10) {
            rollNumber /= 10;
        }

        firstNonZero = rollNumber;

        speed -= firstNonZero;
        if (speed < 0) {
            speed = 0;
        }

        cout << "Applying brakes! New speed: " << speed <<endl;
    }


void display()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Height: "<<height<<endl;
	cout<<"Length: "<<length<<endl;
	cout<<"Speed: "<<speed<<endl;
	cout<<"Capacity: "<<capacity<<endl;
	cout<<"Current riders: "<<CurrentNumRiders<<endl;
	cout<<"Is the ride in progress: "<<RideInProgress<<endl;
}
};

int main(){
	cout<<"Name--> Adina Faraz"<<endl<<"Student ID --> 23k-0008"<<endl;
	RollerCoaster R1;		//using the default constructor
	cout<<"Object made using the default constructor: "<<endl;
	R1.display();
	RollerCoaster R2("RideNRoll", 56.7, 78.9, 0, 20, 0);		//using the parameterized constructor

	//Demonstrate the functionality of roller coaster
	cout<<endl<<"Object made by using parameterized constructor: "<<endl;
	R2.display();
	cout<<"-----------------------------------"<<endl;
	R2.setRiders(20);
	R2.startRide();
	R2.accelerate(1234);
	R2.applyBrakes(1234);
	//My Student id is 0008 which gave some octal number error so i passed an assumed ID in the functions
	int riders = R2.getCurrentNumRiders();
	cout<<riders<<endl;
	R2.stopRide();
	R2.unloadRiders();
}
