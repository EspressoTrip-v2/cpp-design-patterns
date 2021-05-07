#pragma once
#include <string>
#include "PersonBuilderBase.h"

using namespace std;

class PersonAddressBuilder : public PersonBuilderBase
{
	typedef PersonAddressBuilder Self;
public:
	explicit PersonAddressBuilder(Person& person) :PersonBuilderBase{ person } {};

	Self& address(const string& address)
	{
		ref_person.streetAddress = address;
		return *this;
	}

	Self& postCode(const string& postCode)
	{
		ref_person.postCode = postCode;
		return *this;
	}

	Self& city(const string& city)
	{
		ref_person.city = city;
		return *this;
	}
};
