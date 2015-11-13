//
// Created by Brennan Crispin on 11/12/15.
//

#ifndef STAFFMANAGER_FACULTY_H
#define STAFFMANAGER_FACULTY_H


#include "Staff.h"

class Faculty : public Staff{

    enum property
    {
        NAME = 'n',
        SALARY = 's',
        DEPARTMENT = 'd'
    };

private:
    std::string department;

public:
    std::string getDepartment() const;

    void setDepartment(std::string department);

    virtual void output(std::ostream &os) const override;

    virtual void input(std::istream &is) override;

    virtual bool propertyIsGreater(Person *p2, char property) override;

    virtual bool propertyIsEqual(Person *p2, char property) override;

    virtual bool hasProperty(char i) override;

    virtual void createNew() override;

    virtual void print() override;

    virtual void editProperty() override;

    static std::string getType();
};


#endif //STAFFMANAGER_FACULTY_H
