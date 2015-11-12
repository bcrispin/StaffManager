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

    virtual void output(std::ostream& os) const = 0;
    virtual void input(std::istream& is) = 0;

    virtual bool hasProperty(char)=0;

    virtual void print()=0;

    virtual void editProperty()=0;

    virtual void createNew()=0;
    //Create new person. Prompt user to input new user data.
    //PostCondition: Return a new Person with input data.

    Person(std::string name = "");

private:
    std::string name;

};


#endif //STAFFMANAGER_PERSON_H
