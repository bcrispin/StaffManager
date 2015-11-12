//
// Created by Brennan Crispin on 11/8/15.
//

#include "PersonInterface.h"
#include <iostream>
#include "Person.h"

Person::Person(std::string name)
{
    Person::name = name;
}

bool operator>(const Person& p1, const Person& p2) {
    return (p1.name > p2.name);
}

bool operator<(const Person& p1, const Person& p2) {
    return (p1.name < p2.name);
}

bool operator>=(const Person& p1, const Person& p2) {
    return (p1.name >= p2.name);
}

bool operator<=(const Person& p1, const Person& p2) {
    return (p1.name <= p2.name);
}

std::string Person::getName() const {
    return this->name;
}

void Person::setName(std::string n) {
    this->name = n;
}

std::ostream &operator<<(std::ostream &os, const Person &p) {
    p.output(os);
    return os;
}

std::istream &operator>>(std::istream &is, Person &p) {
    p.input(is);
    return is;
}

std::string Person::getType(){
    return "PERSON";
}
bool Person::hasProperty(char i) {
    switch (i)
    {
        case NAME:
            return true;
        default:
            return false;
    }
}

void Person::print()
{
    std::cout << "Type: " << getType() << "   Name: " << name;
}

void Person::editProperty() {
    char propertyToEdit;
    std::cout << "-----Properties-----" << std::endl;
    std::cout << "'n' -- name " << std::endl;
    std::cout << "Please select a property: ";
    std::cin >> propertyToEdit;
    switch (propertyToEdit)
    {
        case(Person::NAME):
        {
            std::string name;
            std::cout << "Please enter a new name: ";
            std::cin >> name;
            Person::setName(name);
            break;
        }
        default:
        {
            std::cout << "Invalid selection. Returning to options menu" << std::endl;
        }
    }
}

void Person::createNew() {
    std::string name;
    std::cout << "Please enter a name: " << std::endl;
    getline(std::cin, name);
    this->name = name;
}
