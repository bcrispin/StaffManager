//
// Created by Brennan Crispin on 11/9/15.
//
#include<iostream>
#include "PersonManagerInterface.h"
#include "model/Staff.h"

void PersonManagerInterface::addNew() {
    char choice;
    std::cout << "Select type of person to create: " << std::endl;
    std::cout << "1. (P)erson" << std::endl;
    std::cout << "2. (S)taff" << std::endl;
    std::cin >> choice;
    std::cin.ignore(INT_MAX, '\n');
    Person * person;
    switch (choice)
    {
        case 'p':;
            break;
        case 's':
            person = new Staff();
            person->createNew();
            personManager.add(person);
            break;
        default:
            std::cout << "Invalid choice!\n\n\n";
    }

}

void PersonManagerInterface::select(std::vector<int> listedVector)
{
    int index;
    char shouldEdit;
    std::cout << "Edit one of listed people (y/n):: " ;
    std::cin >> shouldEdit;
    std::cin.ignore();
    if (tolower(shouldEdit) == 'y')
    {
        std::cout << "\n\nSelect the index of the person you wish to edit:: ";
        std::cin >> index;
        personManager.getPersonByIndex(listedVector[index])->editProperty();
        std::cout << "\n\n\n";
    }

}

void PersonManagerInterface::editSelected()
{

}

void PersonManagerInterface::remove() {
    Person *p = search();
    char response;
    std::cout << "Remove entry for " << p->getName()
            << " in group: " << p->getType() << "? (y/n)::";

    std::cin >> response;
    std::cin.ignore();
    switch(tolower(response))
    {
        case 'y':
            personManager.remove(p);
            std::cout << p->getName() << " removed!\n\n\n";
            break;
        case 'n':
            std::cout << p->getName() << " was not removed!\n\n\n";
            break;
        default:
            std::cout << "Invalid response. Returning to main menu.\n\n\n";
    }
}

Person * PersonManagerInterface::search() {

    try {
        std::string n;
        std::cout << "Enter a name to search for: ";
        getline(std::cin, n);
        return (*personManager.search(n));
    }
    catch (int i)
    {
        throw i;
    }
}

PersonManagerInterface::PersonManagerInterface(PersonManager &manager) {
    personManager = manager;
}

void PersonManagerInterface::save() {
    personManager.save("//Users/brennancrispin/Documents/csc2100/StaffManager/test.dat");

}

bool PersonManagerInterface::mainPrompt() {

    char choice;
    std::cin.ignore(INT_MAX, '\n');

    std::cout << "==================================" << std::endl;
    std::cout << "1. (A)dd Record" << std::endl;
    std::cout << "2. (L)ist Records" << std::endl;
    std::cout << "3. (M)odify Record" << std::endl;
    std::cout << "4. (D)elete Record" << std::endl;
    std::cout << "5. e(X)it" << std:: endl;
    std::cout << "==================================" << std::endl;
    std::cout << "\nSelect Your Choice :: ";
    std::cin >> choice;

    switch(tolower(choice))
    {
        case 'a':
            addNew();
            break;
        case 'l':
            list();
            break;
        case 'm':
            editSelected();
            break;
        case 'd':
            remove();
            break;
        case 'x':
            return false;
        default:
            std::cout <<"Invalid entry. Please enter a valid option.\n\n";
            return true;
    }
    return true;
}

void PersonManagerInterface::list() {
    char choice;
    char order;
    std::cout << "==================================" << std::endl;
    std::cout << "Select a property to sort by: " << std::endl;
    std::cout << "1. (N)ame" << std::endl;
    std::cout << "2. (S)alary" << std::endl;
    std::cout << "3. (G)PA" << std::endl;
    std::cout << "4. e(X)it" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "\nSelect Your Choice :: ";
    std::cin >> choice;
    std::cin.ignore();
    std::cout << "==================================" << std::endl;
    std::cout << "(A)scending or (D)escending order:: ";
    std::cin >> order;
    std::cin.ignore();

    std::vector<int> sortedIndexVector = personManager.sortPersonVector(tolower(choice), (tolower(order)=='a'));
    for (std::vector<int>::iterator it = sortedIndexVector.begin(); it != sortedIndexVector.end(); ++it)
    {
        std::cout << std::distance(sortedIndexVector.begin(), it) << ".  ";
        Person *p = personManager.getPersonByIndex(*it);
        p->print();
        std::cout << std::endl;
    }
    select(sortedIndexVector);
}
