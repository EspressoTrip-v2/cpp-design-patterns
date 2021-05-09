#pragma once
#include <string>
#include "PersonBuilderBase.h"
using namespace std;
class PersonJobBuilder : public PersonBuilderBase
{
	typedef PersonJobBuilder Self;
public:
	explicit PersonJobBuilder(Person& person) :PersonBuilderBase{ person } {};

	Self& company(const string& companyName)
	{
		ref_person.companyName = companyName;
		return *this;
	}

	Self& position(const string& position)
	{
		ref_person.position = position;
		return *this;
	}

	Self& income(int annualIncome)
	{
		ref_person.annualIncome = annualIncome;
		return *this;
	}
};
