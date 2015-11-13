//
// Created by Brennan Crispin on 11/11/15.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "Staff.h"


bool Staff::hasProperty(char i) {
    if (Person::hasProperty(i))
        return true;
    switch (i)
    {
        case SALARY:
            return true;
        default:
            return false;
    }
}

void Staff::print() {
    Person::print();
    std::cout << "   Salary: " << getSalary();
}

void Staff::editProperty() {
    char propertyToEdit;
    std::cout << "-----Properties-----" << std::endl;
    std::cout << "1. (N)ame" << std::endl;
    std::cout << "2. (I)d" << std::endl;
    std::cout << "3. (A)ddress" << std::endl;
    std::cout << "4. (P)hone" << std::endl;
    std::cout << "5. (G)ender" << std::endl;
    std::cout << "6. (E)mail" << std::endl;
    std::cout << "7. (S)alary" <<std::endl;
    std::cout << "7. e(X)it" << std:: endl;
    std::cout << "Please select a property: ";
    std::cin >> propertyToEdit;
    switch (propertyToEdit) {
        case (Person::NAME): {
            std::string name;
            std::cout << "Please enter a new name: ";
            std::cin >> name;
            Person::setName(name);
            break;
        }
        case ID:{
            float id;
            std::cout << "Please enter a new ID: ";
            std::cin >> id;
            Person::setId(id);
            break;
        }
        case ADDRESS: {
            std::string address;
            std::cout << "Please enter a new address: ";
            std::cin >> address;
            Person::setAddress(address);
            break;
        }
        case PHONE: {
            std::string phone;
            std::cout << "Please enter a new phone: ";
            std::cin >> phone;
            Person::setPhone(phone);
            break;
        }
        case GENDER:
        {   char gender;
            std::cout << "Please enter a new gender (m/f): ";
            std::cin >> gender;
            Person::setGender(gender);
            break;}
        case EMAIL:
        {std::string email;
            std::cout << "Please enter a new email: ";
            std::cin >> email;
            Person::setEmail(email);
            break;}
        case SALARY: {
            std::string input;
            while (true) {
                std::cout << "Please enter a new salary: ";
                getline(std::cin, input);

                std::stringstream stream(input);
                if (stream >> salary)
                    break;
                std::cout << "Invalid number, please try again" << std::endl;
            }
        }
        case 'x':
            break;
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
    Person::output(os);
    os << ' ' << getSalary();
}

void Staff::input(std::istream &is) {
    Person::input(is);
    is >> salary;

}

std::string Staff::getType(){
    return "STAFF";
}

bool Staff::propertyIsGreater(Person *p2, char property) {
    if (Person::propertyIsGreater(p2, property))
        return true;
    else
    {
        Staff * s2 = static_cast<Staff*>(p2);
        switch (property)
        {
            case SALARY:
                return (this->getSalary() > s2->getSalary());
            default:
                return false;
        }
    }
}

bool Staff::propertyIsEqual(Person *p2, char property) {
    if (Person::propertyIsEqual(p2, property))
        return true;
    else {
        Staff *s2 = static_cast<Staff *>(p2);
        switch (property) {
            case SALARY:
                return (this->getSalary() == s2->getSalary());
            default:
                return false;
        }
    }
}

Staff::~Staff() {
    setName("");
    setSalary(0);
}
