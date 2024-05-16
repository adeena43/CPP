#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Medicine {
protected:
    string name;
    string formula;
    double retail_price;
    string manufacture_date;
    string expiration_date;

public:
    Medicine(const std::string& name, const std::string& formula, double retail_price, const std::string& manufacture_date, const std::string& expiration_date)
        : name(name), formula(formula), retail_price(retail_price), manufacture_date(manufacture_date), expiration_date(expiration_date) {}
    
   
    string getName() const { return name; }
    string getFormula() const { return formula; }
    double getRetailPrice() const { return retail_price; }
    string getManufactureDate() const { return manufacture_date; }
    string getExpirationDate() const { return expiration_date; }

    
    void setName(const string& name) { this->name = name; }
    void setFormula(const string& formula) { this->formula = formula; }
    void setRetailPrice(double retail_price) { this->retail_price = retail_price; }
    void setManufactureDate(const string& manufacture_date) { this->manufacture_date = manufacture_date; }
    void setExpirationDate(const string& expiration_date) { this->expiration_date = expiration_date; }

    
    virtual void printDetails() const {
        std::cout << "Name: " << name <<endl;
        std::cout << "Formula: " << formula <<endl;
        std::cout << "Retail Price: " << retail_price <<endl;
        std::cout << "Manufacture Date: " << manufacture_date <<endl;
        std::cout << "Expiration Date: " << expiration_date <<endl;
    }
    
    virtual bool operator==(const Medicine& other) const {
        return (name == other.name && formula == other.formula && retail_price == other.retail_price &&
                manufacture_date == other.manufacture_date && expiration_date == other.expiration_date);
    }
};

class Tablet : public Medicine {
private:
    double sucrose_level;

public:
    Tablet(const string& name, const string& formula, double retail_price, const string& manufacture_date, const string& expiration_date, double sucrose_level)
        : Medicine(name, formula, retail_price, manufacture_date, expiration_date), sucrose_level(sucrose_level) {}
    
    
    void printDetails() const override {
        Medicine::printDetails();
        cout << "Sucrose Level: " << sucrose_level << endl;
    }
};

class Capsule : public Medicine {
private:
    int absorption_percentage;

public:
    Capsule(const string& name, const string& formula, double retail_price, const string& manufacture_date, const string& expiration_date, int absorption_percentage)
        : Medicine(name, formula, retail_price, manufacture_date, expiration_date), absorption_percentage(absorption_percentage) {}
    

    void printDetails() const override {
        Medicine::printDetails();
        cout << "Absorption Percentage: " << absorption_percentage << "%" << endl;
    }
};

class Syrup : public Medicine {
public:
    Syrup(const string& name, const string& formula, double retail_price, const string& manufacture_date, const string& expiration_date)
        : Medicine(name, formula, retail_price, manufacture_date, expiration_date) {}
    
   
    void printDetails() const override {
        Medicine::printDetails();
    }
};

class Pharmacist {
public:
    
    void searchMedicine(const vector<Medicine*>& medicines, const string& formula) const {
        for (const auto& med : medicines) {
            if (med->getFormula() == formula) {
                cout << "Medicine found based on formula: " << formula <<endl;
                med->printDetails();
                return;
            }
        }
        cout << "Medicine not found based on formula: " << formula << endl;
    }
};

class Counter {
private:
    double overall_revenue;

public:
    Counter() : overall_revenue(0) {}

    
    void searchMedicine(const vector<Medicine*>& medicines, const string& name) const {
        for (const auto& med : medicines) {
            if (med->getName() == name) {
                cout << "Medicine found based on name: " << name << endl;
                med->printDetails();
                return;
            }
        }
        cout << "Medicine not found based on name: " << name <<endl;
    }

   
    void updateRevenue(double amount) {
        overall_revenue += amount;
    }
};

int main() {
    cout<<"Adina Faraz"<<endl<<"23k-0008"<<endl;
    vector<Medicine*> medicines;
    medicines.push_back(new Tablet("Paracetamol", "C8H9NO2", 10.99, "2024-01-01", "2024-12-31", 0.5));
    medicines.push_back(new Capsule("Ibuprofen", "C13H18O2", 15.99, "2024-01-01", "2024-12-31", 80));
    medicines.push_back(new Syrup("Cough Syrup", "Cough", 5.99, "2024-01-01", "2024-12-31"));

    Pharmacist pharmacist;
    pharmacist.searchMedicine(medicines, "C8H9NO2");

    Counter counter;
    counter.searchMedicine(medicines, "Paracetamol");

    
    for (size_t i = 0; i < medicines.size(); ++i) {
        delete medicines[i];
    }
    medicines.clear();

    return 0;
}
