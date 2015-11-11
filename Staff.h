//
// Created by Brennan Crispin on 11/11/15.
//

#ifndef STAFFMANAGER_STAFF_H
#define STAFFMANAGER_STAFF_H


#include "Person.h"

class Staff : public Person
{
    enum property
    {
        NAME = 'n',
        SALARY = 's'
    };
private:
    float salary;

public:
    virtual bool hasProperty(char i) override;

    virtual void createNew() override;

    virtual void print() override;

    virtual void editProperty() override;

    void setSalary(float);
    float getSalary();

    Staff(std::string name = "");
};


#endif //STAFFMANAGER_STAFF_H
