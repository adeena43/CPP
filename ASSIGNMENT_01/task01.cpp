#include <iostream>
#include <sstream>
using namespace std;

class Pet {
private:
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    int size;
    string* specialSkills;

public:
   Pet(string health = "", int hunger = 0, int happiness = 0, int size = 0, const string skills[] = NULL)
        : healthStatus(health), happinessLevel(happiness), hungerLevel(hunger), size(size) {
        specialSkills = new string[size];
        if (skills != NULL) {
            for (int i = 0; i < size; i++) {
                specialSkills[i] = skills[i];
            }
        }
    }



    string displayPetDetails(int num) const {
        stringstream ss;
        ss << "Displaying info for pet " << num << endl;
        ss << "Health Status: " << healthStatus << endl;
        ss << "Hunger Level: " << hungerLevel << endl;
        ss << "Skills:" << endl;
        for (int i = 0; i < size; i++) {
            ss << specialSkills[i] << endl;
        }
        return ss.str();
    }

    void updateHappiness(int num) {
        if (happinessLevel < 10) {
            happinessLevel++;
        }
    }

    void updateHunger(int num) {
        hungerLevel += num;
        updateHappiness(happinessLevel - 1);
    }

    void updateHealth(string updatedHealth) {
        healthStatus = updatedHealth;
    }

    void feedPet() {
        if (happinessLevel < 10) {
            happinessLevel++;
        }

        if (hungerLevel > 0) {
            hungerLevel--;
        }
    }
    ~Pet() {
        delete[] specialSkills;
    }
};

class Adopter {
private:
    string adopterName;
    string adopterMobileNum;
    Pet adoptedPetRecords[3];
    bool slotsEmpty[3];

public:
    Adopter(string name, string mobileNum) : adopterName(name), adopterMobileNum(mobileNum) {
        for (int i = 0; i < 3; i++) {
            slotsEmpty[i] = true;
        }
    }

    void adoptPet(const Pet& pet) {
        for (int i = 0; i < 3; ++i) {
            if (slotsEmpty[i]) {
                adoptedPetRecords[i] = pet;
                slotsEmpty[i] = false;
                cout << adopterName << " has adopted a new pet!\n";
                return;
            }
        }
        cout << "Sorry, " << adopterName << " cannot adopt more pets.\n";
    }

    void returnPet(const Pet& pet) {
        for (int i = 0; i < 3; ++i) {
            if (!slotsEmpty[i] && &adoptedPetRecords[i] == &pet) {
                adoptedPetRecords[i] = Pet("", 0, 0, 0); // Reset the array element
                slotsEmpty[i] = true;
                cout << adopterName << " has returned the pet.\n";
                return;
            }
        }
        cout << "Pet not found in adopted records.\n";
    }

    void displayAdoptedPets() const {
        cout << adopterName << "'s Adopted Pets:\n";
        for (int i = 0; i < 3; i++) {
            if (!slotsEmpty[i]) {
                cout << adoptedPetRecords[i].displayPetDetails(i + 1) << endl;
                cout << "-----------------------------\n";
            }
        }
    }
};

int main() {
    string dogSkills[] = { "Fetch", "Sit" };
	Pet dog("Healthy", 5, 5, 2, dogSkills);
	
	string catSkills[] = { "Climbing", "Purring" };
	Pet cat("Healthy", 6, 4, 2, catSkills);

    Adopter john("John", "123-456-789");
    Adopter alice("Alice", "987-654-321");

    john.adoptPet(dog);
    alice.adoptPet(cat);

    john.displayAdoptedPets();
    alice.displayAdoptedPets();

    john.returnPet(dog);

    john.displayAdoptedPets();

//    return 0;
}
