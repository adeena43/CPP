#include <iostream>
using namespace std;

class Table {
private:
    const static int defaultCapacity = 4;
    int capacity;
    int occupiedSeats;
    int freeSeats;
    bool clean;

public:
    Table() {
        capacity = defaultCapacity;
        occupiedSeats = 0;
        freeSeats = defaultCapacity;
        clean = true;
    }

    Table(int capacity) {
        if (capacity < 6) {
            this->capacity = 4;
        } else {
            this->capacity = 8;
        }
        occupiedSeats = 0;
        freeSeats = this->capacity;
        clean = true;
    }

    int getCapacity(){
        return capacity;
    }

    int getOccupiedSeats(){
        return occupiedSeats;
    }

    int getFreeSeats(){
        return freeSeats;
    }

    bool isClean() {
        return clean;
    }

    bool useTable(int groupSize) {
        if (!clean || groupSize > capacity || groupSize > freeSeats) {
            cout << "Table cannot be used." <<endl;
            return false;
        }

        occupiedSeats = groupSize;
        freeSeats -= groupSize;
        clean = false;
        cout << "Table with capacity " << capacity << " has been occupied by a group of " << groupSize << "." <<endl;
        return true;
    }

    bool haveLunch() {
        if (!occupiedSeats || clean) {
            cout << "No one is seated or the table is already clean." << endl;
            return false;
        }

        cout << "Having lunch on the table..." <<endl;
        clean = false;
        return true;
    }

    bool leaveTable() {
        if (!occupiedSeats) {
            cout << "No one is seated at the table." <<endl;
            return false;
        }

        cout << "Leaving the table with " << occupiedSeats << " occupied seats." << endl;
        freeSeats += occupiedSeats;
        occupiedSeats = 0;
        return true;
    }

    bool cleanTable() {
        if (occupiedSeats) {
            cout << "Cannot clean the table while someone is seated." << endl;
            return false;
        }

        cout << "Cleaning the table..." << endl;
        clean = true;
        return true;
    }
};

void occupyTable(Table tableArray[], int groupSize) {
    for (int i = 0; i < 5; ++i) {
        if (tableArray[i].useTable(groupSize)) {
            return;
        }
    }
}

void emptyTable(Table& table) {
    table.leaveTable();
    table.cleanTable();
}

int main() {
	cout<<"Adina Faraz"<<"23k-0008"<<endl<<endl;
    Table tableArray[5];

    tableArray[0] = Table(8);
    tableArray[1] = Table(8);
    tableArray[2] = Table(4);
    tableArray[3] = Table(4);
    tableArray[4] = Table(4);

    occupyTable(tableArray, 4); 
    occupyTable(tableArray, 6); 

    
    tableArray[0].useTable(4);
    tableArray[0].haveLunch();
    tableArray[0].leaveTable();
    tableArray[0].cleanTable();

    emptyTable(tableArray[1]);

    return 0;
}
