//
// Created by Brennan Crispin on 11/9/15.
//

#ifndef STAFFMANAGER_PERSONMANAGERINTERFACE_H
#define STAFFMANAGER_PERSONMANAGERINTERFACE_H


#include "PersonManager.h"

class PersonManagerInterface
{
private:
    PersonManager personManager;

public:
    bool mainPrompt();
    void addNew();
    void save();
    void list();
    void select(std::vector<int> listedVector);
    void editSelected();
    void remove();
    Person * search();

    PersonManagerInterface(PersonManager &);
};


#endif //STAFFMANAGER_PERSONMANAGERINTERFACE_H
