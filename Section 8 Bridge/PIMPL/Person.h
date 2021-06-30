//
// Created by Juan on 5/13/2021.
//

#ifndef PIMPL_PERSON_H
#define PIMPL_PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    string name;

    class PersonImpl;

    PersonImpl *impl;

    Person();
    ~Person();
    void greet();
};


#endif //PIMPL_PERSON_H
