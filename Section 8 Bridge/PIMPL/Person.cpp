//
// Created by Juan on 5/13/2021.
//

#include "Person.h"

class Person::PersonImpl
{
public:
    void greet(Person *p)
    {
        cout << "Hello my name is " << p->name << endl;
    }
};

Person::Person() : impl{new PersonImpl}
{}
Person::~Person()
{
    delete impl;
}
void Person::greet()
{
    impl->greet(this);
}
