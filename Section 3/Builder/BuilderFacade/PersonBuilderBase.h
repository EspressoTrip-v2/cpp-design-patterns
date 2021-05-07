#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

class PersonAddressBuilder;
class PersonJobBuilder;
class PersonBuilderBase
{
protected:
	Person& ref_person;

public:
	explicit PersonBuilderBase(Person& person) :ref_person{ person } { cout << "Base constructor::called" << endl; };

	PersonAddressBuilder lives() const;
	PersonJobBuilder works() const;

	// Type conversion return operator
	operator Person() const
	{
		return move(ref_person);
	}
};
