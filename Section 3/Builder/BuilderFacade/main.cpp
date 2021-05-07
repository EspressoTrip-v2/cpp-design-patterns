#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>
#include <memory>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

// BUILDER FACADE
using namespace std;

int main()
{
	Person p = Person::create().works()
		.company("A Company").position("Software Engineer").income(20000)
		.lives().address("Some Address").city("Some City").postCode("Random Postal Code");

	cout << p;

	Person a;
	a = p;
	cout << a;

	return 0;
}