#pragma once
#include <string>
#include <iostream>

using namespace std;
class PersonBuilder;
class Person
{
	friend class PersonBuilder;
	friend class PersonJobBuilder;
	friend class PersonAddressBuilder;
	friend ostream& operator<<(ostream& os, const Person& obj)
	{
		os << "Street Address: \nAddress: " << obj.streetAddress << "\n"
			<< "Post Code: " << obj.postCode << "\n"
			<< "City: " << obj.city << "\n\n"
			<< "Work:\nCompany Name: " << obj.companyName << "\n"
			<< "Position: " << obj.position << "\n"
			<< "Annual Income $" << obj.annualIncome << endl;
		return os;
	}

	// Address Details
	string streetAddress, postCode, city;
	// Employment Details
	string companyName, position;
	int annualIncome{ 0 };

public:
	// Constructors
	Person() = default;
	~Person() = default;

	Person(const Person& other) :streetAddress{ other.streetAddress }, postCode{ other.postCode },
		city{ other.city }, companyName{ other.companyName }, position{ other.position }, annualIncome{ other.annualIncome }
	{
		cout << "\tCopy::constructor->" << this << endl;
	};

	Person(Person&& other) noexcept {
		cout << "\tMove::constructor->" << this << endl;
		streetAddress = move(other.streetAddress);
		postCode = move(other.postCode);
		city = move(other.city);
		companyName = move(other.companyName);
		position = move(other.position);
		annualIncome = other.annualIncome;
	};

	// Operators
	Person& operator=(const Person& other)
	{
		cout << "\tCopy::operator->" << this << endl;
		streetAddress = other.streetAddress;
		postCode = other.postCode;
		city = other.city;
		companyName = other.companyName;
		position = other.position;
		annualIncome = other.annualIncome;
		return *this;
	}

	Person& operator=(Person& other) noexcept
	{
		cout << "\tMove::operator->" << this << endl;
		streetAddress = move(other.streetAddress);
		postCode = move(other.postCode);
		city = move(other.city);
		companyName = move(other.companyName);
		position = move(other.position);
		annualIncome = other.annualIncome;
		return *this;
	};

	// Static builder
	static PersonBuilder create();
};
