//
// Created by Brennan Crispin on 11/11/15.
//

#ifndef STAFFMANAGER_STAFF_H
#define STAFFMANAGER_STAFF_H


#include <vector>
#include "Person.h"

class Staff : public Person
{
    enum property
    {
        NAME = 'n',
        SALARY = 's'
    };

public:
    virtual void output(std::ostream &os) const override;

    virtual void input(std::istream &is) override;

private:
    float salary;

public:
    virtual bool propertyIsGreater(Person *p2, char property) override;

    virtual bool propertyIsEqual(Person *p2, char property) override;

    virtual bool hasProperty(char i) override;

    virtual void createNew() override;

    virtual void print() override;

    virtual void editProperty() override;

    ~Staff();

    void setSalary(float);
    float getSalary() const;
    static std::string getType();
    Staff(std::string name = "");
};


#endif //STAFFMANAGER_STAFF_H
