//
// Created by Brennan Crispin on 11/8/15.
//

#ifndef STAFFMANAGER_PERSONINTERFACE_H
#define STAFFMANAGER_PERSONINTERFACE_H

#include<string>
#include "Person.h"

class PersonInterface {

private:
    enum option
    {
        NEW = 'n',
        EDIT = 'e',
        DELETE = 'd',
        PRINT = 'p',
        EXIT = 'x'
    };

public:
    static bool selectOption(Person p);
    //Prompt user to select what they would like to do
    //PostCondition: Launch selected option
    static void editProperty(Person *p);
    //Prompt user to edit a property.
    //PostCondition: Person is saved with new property.
    static bool remove(Person p);
    //Prompt user to delete selectec person.
    //PostCondition: remove selected person.
    static void print(Person p);
    //print data related to selected person.
    //Postcondition: Person's value is output

};


#endif //STAFFMANAGER_PERSONINTERFACE_H
