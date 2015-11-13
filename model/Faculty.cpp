//
// Created by Brennan Crispin on 11/12/15.
//

#include <iostream>
#include "Faculty.h"

void Faculty::output(std::ostream &os) const {
    Staff::output(os);
    os <<' ' << getDepartment();
}

void Faculty::input(std::istream &is) {
    Staff::input(is);
    is >> department;
}

bool Faculty::propertyIsGreater(Person *p2, char property) {
    if (Staff::propertyIsGreater(p2, property))
        return true;

    Faculty * f2 = static_cast<Faculty*>(p2);
    switch (property)
    {
        case NAME:
            return (this->getName() > f2->getName());
        case SALARY:
            return (this->getSalary() > f2->getSalary());
        case DEPARTMENT:
            return (this->getDepartment() > f2->getDepartment());
        default:
            return false;
    }
}

bool Faculty::propertyIsEqual(Person *p2, char property) {
    if (Staff::propertyIsEqual(p2, property))
        return true;

    Faculty * f2 = static_cast<Faculty*>(p2);
    switch (property)
    {
        case NAME:
            return (this->getName() == f2->getName());
        case SALARY:
            return (this->getSalary() == f2->getSalary());
        case DEPARTMENT:
            return (this->getDepartment() == f2->getDepartment());
        default:
            return false;
    }
}

bool Faculty::hasProperty(char i) {
    if (Staff::hasProperty(i))
        return true;

    switch (i)
    {
        case DEPARTMENT:
            return true;
        default:
            return false;
    }
}

void Faculty::createNew() {
    Staff::createNew();
    std::cin.ignore();
    std::string d;
    std::cout << "Please enter a department:: ";
    getline(std::cin, d);
    this->department = d;
}

void Faculty::print() {
    std::cout << "Type: " << getType() << "   Name: " <<
            getName() << "   Salary: " << getSalary()
            <<   "   Department: " << getDepartment();
}

void Faculty::editProperty() {
    char propertyToEdit;
    std::cout << "-----Properties-----" << std::endl;
    std::cout << "'n' -- name " << std::endl;
    std::cout << "'s' -- salary " << std::endl;
    std::cout << "'d' -- department " << std::endl;
    std::cout << "Please select a property to edit: ";
    std::cin >> propertyToEdit;
    switch (propertyToEdit)
    {
        case(Faculty::NAME): {
            std::string n;
            std::cout << "Please enter a new name: ";
            std::cin >> n;
            Person::setName(n);
            break;
        }
        case(Faculty::SALARY): {
            float s;
            std::cout << "Please enter a new salary: ";
            std::cin >> s;
            Staff::setSalary(s);
            break;
        }
        case(Faculty::DEPARTMENT): {
            std::string d;
            std::cout << "Please enter a new department: ";
            std::cin >> d;
            Faculty::setDepartment(d);
            break;
        }
        default:
        {
            std::cout << "Invalid selection. Returning to options menu" << std::endl;
        }
    }
}

std::string Faculty::getType()
{
    return "FACULTY";
}

std::string Faculty::getDepartment() const {
    return Faculty::department;
}

void Faculty::setDepartment(std::string department) {
    Faculty::department = department;
}
