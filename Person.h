//
// Created by Brennan Crispin on 11/8/15.
//

#ifndef STAFFMANAGER_PERSON_H
#define STAFFMANAGER_PERSON_H

#include<string>

class Person
{
    friend bool operator>(const Person& p1, const Person& p2);
    friend bool operator<(const Person& p1, const Person& p2);
    friend bool operator>=(const Person& p1, const Person& p2);
    friend bool operator<=(const Person& p1, const Person& p2);

    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend std::istream& operator>>(std::istream&, Person&);



public:
    enum property
    {
        NAME = 'n'
    };

    static std::string getType();
    std::string getName() const;
    void setName(std::string name);

    virtual bool hasProperty(char);

    virtual void print();

    virtual void editProperty();

    virtual void createNew();
    //Create new person. Prompt user to input new user data.
    //PostCondition: Return a new Person with input data.

    Person(std::string name = "");

private:
    std::string name;

};


#endif //STAFFMANAGER_PERSON_H
