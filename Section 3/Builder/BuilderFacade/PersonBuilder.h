#pragma once
#include "PersonBuilderBase.h"

class PersonBuilder : public PersonBuilderBase
{
	Person person;
public:
	PersonBuilder() :PersonBuilderBase{ person } {};
};
