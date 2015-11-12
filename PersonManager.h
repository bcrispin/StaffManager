//
// Created by Brennan Crispin on 11/8/15.
//

#ifndef STAFFMANAGER_PERSONMANAGER_H
#define STAFFMANAGER_PERSONMANAGER_H

#include <vector>
#include "model/Person.h"

class PersonManager
{
    enum Property
    {
        NAME = 'n',
        SALARY = 's',
        DEPARTMENT = 'd'

    };
private:
    std::vector<Person*> personVector;
    //Vector storing all persons

public:
    std::vector<int> sortPersonVector(std::vector<char>, bool ascending);
    //Sorts person vector by property, first to last. Default to NAME
    //PostCondition: Returns a sorted vector personVector, sorted by Property

    bool compareTwoElements(Person *p1, Person *p2, std::vector<char> properties, bool ascending);

    std::vector<Person*> load(std::string filename = "default.dat");
    //loads the personVector from file, takes filename as argument. Defaults to "default.dat"
    //PostCondition: personVector is updated from file. Returns personVector

    void save(std::string filename = "default.dat");
    //Saves personVector to file. Defaults saving to "default.dat"
    //PostCondtion. personVector data is saved to file.

    std::vector<Person*>::iterator search(std::string query);
    //Searches though personVector and gets an iterator.
    //PostCondition: Returns an iterator corresponding to the Person searched for.

    std::vector<int> filter(std::vector<char>);

    void add(Person *person);
    //Insert a new person. Opens up the PersonInterface new person prompt
    //PostCondition: Adds a new person to personVector

    void remove(Person* p);
    //Remove the person located at the reference passed in
    //PostCondition: per

    Person* getPersonByIndex(int index);
    //Calls ->edit for the person at the given index
    //PostCondition:

};


#endif //STAFFMANAGER_PERSONMANAGER_H
