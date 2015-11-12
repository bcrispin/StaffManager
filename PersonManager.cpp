//
// Created by Brennan Crispin on 11/8/15.
//
#include<vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "PersonManager.h"
#include "model/Staff.h"

std::vector<int> PersonManager::sortPersonVector(char property, bool ascending) {

    std::vector<int> sortedVector = filter(property);
    return sortedVector;
}

std::vector<Person*> PersonManager::load(std::string filename) {
    std::vector<Person*> newVector;
    std::ifstream ifs(filename);
    Person * person;
    while(!ifs.eof())
    {
        std::string type;
        if (ifs >> type)
        {
            if(type == Staff::getType())
                person = new Staff();
                if ((ifs >> *person))
                    person->createNew();
                    newVector.push_back(person);
        }
    }

    personVector = newVector;
    return newVector;
}

void PersonManager::save(std::string filename)
{
    std::ofstream ofs(filename);
    for (std::vector<Person*>::iterator it = personVector.begin(); it != personVector.end(); ++it)
    {
        ofs << *(*it);
    }

    ofs.close();
}

void PersonManager::add(Person *person)
{
    bool hasAddedPerson = false;
    //Iterate over PersonVector and insert the new Person in order by name.
    for (std::vector<Person*>::iterator it = personVector.begin(); it != personVector.end(); ++it)
    {
        if (*person >= *(*it))
        {
            personVector.insert(it, person);
            hasAddedPerson = true;
            break;
        }
    }

    if(!hasAddedPerson)
        personVector.push_back(person);
}

void PersonManager::remove(Person *p)
{
    personVector.erase(search(p->getName()));
}

std::vector<Person*>::iterator PersonManager::search(std::string query) {
    for (std::vector<Person*>::iterator it = personVector.begin(); it != personVector.end(); ++it)
    {
        if ((*it)->getName() == query)
        {
            return it;
        }
    }
    throw 1;
}

std::vector<int> PersonManager::filter(char property) {
    std::vector<int> sortedIndexVector;
    for (std::vector<Person*>::iterator it = personVector.begin(); it != personVector.end(); ++it)
    {
        if ((*it)->hasProperty(property))
            sortedIndexVector.push_back(it - personVector.begin());
    }
    return sortedIndexVector;
}

Person* PersonManager::getPersonByIndex(int index)
{
    return (Person*)personVector[index];
}
