#include "stdafx.h"

class Address
{
public:
    Address(string streetName) : streetName(streetName){}
    string streetName;
};

class Person
{
public:
    Person(string firstName, string lastName) : firstName(firstName), lastName(lastName) {}

    string firstName;
    string lastName;

    optional<string> middleName;
    optional<Address> address;

    optional<string> GetName() { return middleName; }
};

int main(int argc, char* argv[])
{
    Person p { "John", "Watson" };

    if (p.middleName)
    {
        cout << *p.middleName << endl;
    }

    p.middleName = "Hamish";
    p.middleName = "The Gambler";

    if (p.middleName)
    {
        cout << *p.middleName << endl;
    }

    p.address = Address{ "Baker st." };

    if (p.address)
    {
        cout << p.address->streetName << endl;
    }

    return 0;
}
