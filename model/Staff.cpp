//
// Created by Brennan Crispin on 11/11/15.
//

#include <iostream>
#include <vector>
#include "Staff.h"


bool Staff::hasProperty(char i) {
    switch (i)
    {
        case NAME:
            return true;
        case SALARY:
            return true;
        default:
            return false;
    }
}

void Staff::print() {
    std::cout << "Type: " << getType() << "   Name: " << getName() << "   Salary: " << getSalary();
}

void Staff::editProperty() {
    char propertyToEdit;
    std::cout << "-----Properties-----" << std::endl;
    std::cout << "'n' -- name " << std::endl;
    std::cout << "'s' -- salary " << std::endl;
    std::cout << "Please select a property to edit: ";
    std::cin >> propertyToEdit;
    switch (propertyToEdit)
    {
        case(Staff::NAME):
        {
            std::string n;
            std::cout << "Please enter a new name: ";
            std::cin >> n;
            Person::setName(n);
            break;
        }
        case(Staff::SALARY):
        {
            float s;
            std::cout << "Please enter a new salary: ";
            std::cin >> s;
            Staff::setSalary(s);
        }
        default:
        {
            std::cout << "Invalid selection. Returning to options menu" << std::endl;
        }
    }
}

float Staff::getSalary() const { return this->salary;}
void Staff::setSalary(float s) {this->salary = s;}

Staff::Staff(std::string name) : Person(name) {

}

void Staff::createNew() {
    Person::createNew();
    float salary;
    std::cout << "Please enter a salary:: ";
    std::cin >> salary;
    this->salary = salary;
}

void Staff::output(std::ostream &os) const {
    os << getType() << ' ' << getName() << ' ' << getSalary() << '\n';
}

void Staff::input(std::istream &is) {
    std::string n;
    is >> n >> salary;
    setName(n);
}

std::string Staff::getType(){
    return "STAFF";
}

bool Staff::propertyIsGreater(Person *p2, char property) {
    Staff * s2 = static_cast<Staff*>(p2);
    switch (property)
    {
        case NAME:
            return (this->getName() > s2->getName());
        case SALARY:
            return (this->getSalary() > s2->getSalary());
        default:
            return false;
    }
}

bool Staff::propertyIsEqual(Person *p2, char property) {
    Staff * s2 = static_cast<Staff*>(p2);
    switch (property)
    {
        case NAME:
            return (this->getName() == s2->getName());
        case SALARY:
            return (this->getSalary() == s2->getSalary());
        default:
            return false;
    }
}

Staff::~Staff() {
    setName("");
    setSalary(0);
}
