//
// Created by Brennan Crispin on 11/8/15.
//

#ifndef STAFFMANAGER_PERSON_H
#define STAFFMANAGER_PERSON_H

#include<string>
#include <vector>

class Person
{
    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend std::istream& operator>>(std::istream&, Person&);

public:
    enum Property
    {
        NAME = 'n',
        ID = 'i',
        PHONE = 'p',
        ADDRESS = 'a',
        GENDER = 'g',
        EMAIL = 'e'
    };

    enum Gender
    {
        MALE = 'm',
        FEMALE = 'f'
    };

    static std::string getType();

    //Getters and setters for private data
    //------***----------

    std::string getName() const;
    void setName(std::string name);
    long getId() const;
    void setId(long id);
    std::string getPhone() const;
    void setPhone(std::string name);
    std::string getAddress() const;
    void setAddress(std::string name);
    Gender getGender() const;
    std::string getGenderString() const;
    void setGender(Gender);
    void setGender(char);
    std::string getEmail() const;
    void setEmail(std::string name);

    //------***----------
    //End Getters and setters

    //Input and output stream handlers. Used for writing and reading file
    virtual void output(std::ostream& os) const = 0;
    virtual void input(std::istream& is) = 0;

    virtual bool hasProperty(char)=0;
    //Checks if selected property is part of object
    //Returns true if char matches enum property
    virtual bool propertyIsGreater(Person *p2, char property) = 0;
    //Checks that the selected property is greater than the other person's property
    //PostCondition: Returns true is this->property is greater than p2->property
    virtual bool propertyIsEqual(Person *p2, char property) = 0;
    //Checks that the selected properties are equal for the Person pointed at.
    //PostCondition: Returns true if equal, false if not.
    virtual void print()=0;
    //Print the values contained in the selectd person.
    //PostCondition: Outputs variables belonging to person in form
    //Type:(Type) Name:Name etc...

    virtual void editProperty()=0;
    //Edit a property of the selected person. Prompts the user to select and edit a property.
    //PostCondition: Person is updated with a new property as selected by the user.

    virtual void createNew()=0;
    //Create new person. Prompt user to input new user data.
    //PostCondition: Return a new Person with input data.

    Person(std::string name = "");
    virtual ~Person()=0;


private:
    std::string name;
    long id;
    std::string phone;
    std::string address;
    Gender gender;
    std::string email;

};


#endif //STAFFMANAGER_PERSON_H
