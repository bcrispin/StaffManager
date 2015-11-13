//
// Created by Brennan Crispin on 11/8/15.
//
#include<vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "PersonManager.h"
#include "model/Staff.h"
#include "model/Faculty.h"

std::vector<int> PersonManager::sortPersonVector(std::vector<char> properties, bool ascending) {

    std::vector<int> sortedVector;
    //Ensure only persons containing the selected properties are sorted.
    sortedVector = filter(properties);

    for (std::vector<int>::iterator it = sortedVector.begin(); it != sortedVector.end(); ++it)
    {
        std::vector<int>::iterator jt = it; //i:j :: it:jt
        while (jt != sortedVector.begin() && compareTwoElements(getPersonByIndex(*(jt-1)),
                                                                getPersonByIndex(*jt),
                                                                properties,
                                                                ascending)){
            std::iter_swap(jt-1, jt);
            --jt;
        }
    }
    if (!ascending)
        std::reverse(sortedVector.begin(), sortedVector.end());

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
            if(type == Staff::getType()) {
                person = new Staff();
                if ((ifs >> *person))
                    newVector.push_back(person);
            }
            else if(type == Faculty::getType()){
                person = new Faculty();
                if ((ifs >> *person))
                    newVector.push_back(person);
            }
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
    delete p;
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

std::vector<int> PersonManager::filter(std::vector<char> properties) {
    std::vector<int> sortedIndexVector;
    for (std::vector<Person*>::iterator it = personVector.begin(); it != personVector.end(); ++it)
    {
        bool hasAllProperties = true;
        for (int i = 0; i < properties.size(); i++)
        {
            if (!(*it)->hasProperty(properties[i])){
                hasAllProperties = false;
                break;
            }
        }

        if (hasAllProperties)
        {
            //Get the index of the iterator that has the above properties
            sortedIndexVector.push_back(it - personVector.begin());
        }
    }
    return sortedIndexVector;
}

Person* PersonManager::getPersonByIndex(int index)
{
    return (Person*)personVector[index];
}

bool PersonManager::compareTwoElements(Person *p1, Person *p2, std::vector<char> properties, bool ascending) {

    //if no more properties to sort by, return false
    if (properties.empty())
        return false;

    //Compare two elements by the given property. If they are equal, call the next property in the properties vector
    char property = properties.front();
    properties.erase(properties.begin());
    return (p1->propertyIsGreater(p2, property))
           || (p1->propertyIsEqual(p2, property) && this->compareTwoElements(p1, p2, properties, ascending));
}
