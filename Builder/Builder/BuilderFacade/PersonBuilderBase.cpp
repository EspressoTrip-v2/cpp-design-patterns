#include "PersonBuilderBase.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonAddressBuilder PersonBuilderBase::lives() const
{
	return PersonAddressBuilder{ ref_person };
};
PersonJobBuilder PersonBuilderBase::works() const
{
	return PersonJobBuilder{ ref_person };
};