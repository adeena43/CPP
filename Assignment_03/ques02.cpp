#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Pet {
protected:
    string name;
    int age;

public:
    Pet(const string& name, int age) : name(name), age(age) {}

    virtual void makeSound() const = 0;

    string getName() const { return name; }
    int getAge() const { return age; }
};

class Cat : public Pet<Cat> {
public:
    Cat(const string& name, int age) : Pet<Cat>(name, age) {}

    void makeSound() const override {
        cout << "Meow!" <<endl;
    }
};

class Dog : public Pet<Dog> {
public:
    Dog(const string& name, int age) : Pet<Dog>(name, age) {}

    void makeSound() const override {
        cout << "Woof!" <<endl;
    }
};

class Bird : public Pet<Bird> {
public:
    Bird(const string& name, int age) : Pet<Bird>(name, age) {}

    void makeSound() const override {
        cout << "Chirp!" <<endl;
    }
};

int main() {
	cout<<"Adina Faraz"<<endl<<"23k-0008"<<endl;
    Cat cat("Whiskers", 3);
    Dog dog("Buddy", 5);
    Bird bird("Tweetie", 2);

    Pet<Cat>* ptrCat = &cat;
    Pet<Dog>* ptrDog = &dog;
    Pet<Bird>* ptrBird = &bird;

    cout << "Cat: " << ptrCat->getName() << ", Age: " << ptrCat->getAge() <<endl;
    ptrCat->makeSound();

    cout << "Dog: " << ptrDog->getName() << ", Age: " << ptrDog->getAge() <<endl;
    ptrDog->makeSound();

    cout << "Bird: " << ptrBird->getName() << ", Age: " << ptrBird->getAge() <<endl;
    ptrBird->makeSound();

    return 0;
}
