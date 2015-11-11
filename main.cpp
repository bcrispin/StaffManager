#include <iostream>
#include "Person.h"
#include "PersonInterface.h"
#include "PersonManager.h"
#include "PersonManagerInterface.h"

using namespace std;

int main() {

    PersonManager personManager;
    personManager.load("//Users/brennancrispin/Documents/csc2100/StaffManager/test.dat");
    PersonManagerInterface personManagerInterface(personManager);
    while(personManagerInterface.mainPrompt())

    personManagerInterface.save();
    return 0;
}