//
// Created by Brennan Crispin on 11/8/15.
//

#include<iostream>
#include "PersonInterface.h"

using std::cout;
using std::cin;
using std::endl;

bool PersonInterface::selectOption(Person p) {
    char selectedOption;
    bool tryAgain;
    cout << "-----Available Options----- " << endl;
    do
    {
        tryAgain = false;
        cout << "'n' - Create new Person. " << endl;
        cout << "'e' - Edit selected Person. " << endl;
        cout << "'d' - remove selected Person. " << endl;
        cout << "'p' - print values for selected Person." << endl;
        cout << "'x' - Exit to main options. " << endl;
        cout << "Please select your option: ";
        cin >> selectedOption;

        switch (selectedOption)
        {
            case(NEW):
            {
                createNew();
                break;
            }
            case(EDIT):
            {
                editProperty(&p);
                break;
            }
            case(DELETE):
            {
                remove(p);
                break;
            }
            case(PRINT):
            {
                print(p);
                break;
            }
            case(EXIT):
            {
               return true;
            }
            default:
            {
                tryAgain = true;
            }
        }
    } while(tryAgain);

    return false;

}


void PersonInterface::editProperty(Person *p) {
    char propertyToEdit;
    cout << "-----Properties-----" << endl;
    cout << "'n' -- name " << endl;
    cout << "Please select a property: ";
    cin >> propertyToEdit;
    switch (propertyToEdit)
    {
        case(Person::NAME):
        {
            std::string name;
            cout << "Please enter a new name: ";
            cin >> name;
            p->setName(name);
            break;
        }
        default:
        {
            cout << "Invalid selection. Returning to options menu" << endl;
        }
    }
}

bool PersonInterface::remove(Person p) {
    char shouldDelete;
    cout << "Are you sure you want to delete " << p.getName() << "? (y/n)";
    while (true)
    {
        cin >> shouldDelete;
        switch(tolower(shouldDelete))
        {
            case('y'):
                return true;
            case('n'):
                return false;
            default:
                cout << "Invalid choice. Please select y(es) or n(o): ";
        }
    }
}

void PersonInterface::print(Person p) {
    cout << "Name: " << p.getName() << std::endl;
}

