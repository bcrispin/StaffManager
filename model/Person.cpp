//
// Created by Brennan Crispin on 11/8/15.
//

#include <iostream>
#include <sstream>
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
    os << '\n';
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
        case ID:
            return true;
        case ADDRESS:
            return true;
        case PHONE:
            return true;
        case GENDER:
            return true;
        case EMAIL:
            return true;
        default:
            return false;
    }
}

void Person::print()
{
    std::cout << "ID: " << id << "  Type: " << getType() << "   Name: " << name
            << "   Email: " << email << "  Address: " << address << "   Phone: "
    << phone << "  Gender: " << getGenderString();
}

void Person::editProperty() {
    char propertyToEdit;
    std::cout << "-----Properties-----" << std::endl;
    std::cout << "1. (N)ame" << std::endl;
    std::cout << "2. (I)d" << std::endl;
    std::cout << "3. (A)ddress" << std::endl;
    std::cout << "4. (P)hone" << std::endl;
    std::cout << "5. (G)ender" << std::endl;
    std::cout << "6. (E)mail" << std::endl;
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
        case 'x':
            break;
        default:
        {
            std::cout << "Invalid selection. Returning to options menu" << std::endl;
        }
    }
}

void Person::createNew() {
    std::string input;
    std::cout << "Please enter NAME: ";
    getline(std::cin, input);
    this->name = input;
    while (true) {
        std::cout << "Please enter a valid number: ";
        getline(std::cin, input);

        // This code converts from string to number safely.
        std::stringstream myStream(input);
        if (myStream >> Person::id)
            break;
        std::cout << "Invalid number, please try again" << std::endl;
    }
    std::cout << "Please enter PHONE NUMBER: ";
    getline(std::cin, input);
    this->phone = input;
    std::cout << "Please enter EMAIL: ";
    getline(std::cin, input);
    this->email = input;
    std::cout << "Please enter ADDRESS: ";
    getline(std::cin, input);
    this->address = input;
    std::cout << "Please enter GENDER: ";
    getline(std::cin, input);
    this->setGender(input[0]);
}



Person::~Person(){
}

long Person::getId() const {
    return Person::id;
}
void Person::setId(long id) {
    Person::id = id;
}

std::string Person::getPhone() const {
    return Person::phone;
}

void Person::setPhone(std::string phone) {
    Person::phone = phone;
}

std::string Person::getAddress() const {
    return Person::address;
}

void Person::setAddress(std::string address) {
    Person::address = address;
}

Person::Gender Person::getGender() const {
    return Person::gender;
}

void Person::setGender(Person::Gender gender) {
    Person::gender = gender;
}

void Person::setGender(char gender) {
    switch (tolower(gender))
    {
        case MALE:
        Person::gender = MALE;
            break;
        case FEMALE:
        Person::gender = FEMALE;
            break;
    }
}

std::string Person::getEmail() const {
    return Person::email;
}

void Person::setEmail(std::string email) {
    Person::email = email;
}

std::string Person::getGenderString() const {
    switch (gender)
    {
        case MALE:
            return "MALE";
        case FEMALE:
            return "FEMALE";
        default:
            return "";
    }
}


void Person::output(std::ostream &os) const {
    os << getType() << ' ' << getId() << ' ' << getName() << ' ' << getGender() << ' '
    << getEmail() << ' ' << getAddress() << ' ' << getPhone();
}

void Person::input(std::istream &is) {
    std::string g;
    is >> id >> name >> g >> email >> address >> phone;
    setGender(tolower(g[0]));
}
