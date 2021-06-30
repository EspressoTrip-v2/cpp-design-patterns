#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <memory>
#include <cmath>
using namespace std;

struct Address
{
    string street, city;
    int suite;
    Address(const string &street, const string &city, int suite) : street(street), city(city), suite(suite)
    {}

    Address(const Address &other) : street{other.street}, city{other.city}, suite{other.suite}
    {}

    friend ostream &operator<<(ostream &os, const Address &address)
    {
        os << "street: " << address.street << "\ncity: " << address.city << "\nsuite: " << address.suite << endl;
        return os;
    }
};

struct Contact
{
    string name;
    Address *address;

    Contact(const string &name, Address *address) : name(name), address(address)
    {}
    Contact(const Contact &other) : name{other.name},
                                    address{new Address{other.address->street, other.address->city,
                                                        other.address->suite}}
    {}
    ~Contact()
    {
        delete address;
    }
    friend ostream &operator<<(ostream &os, const Contact &contact)
    {
        os << "name: " << contact.name << "\naddress: " << *contact.address;
        return os;
    }
};

struct EmployeeFactory
{
    static unique_ptr<Contact> newMAinOfficeEmployee(const string &name, const int suite)
    {
        static Contact p{"", new Address{"123 East Dr", "London", 0}};
        return newEmployee(name, suite, p);
    }

    static unique_ptr<Contact> newContractEmployee(const string &name, const int suite)
    {
        static Contact p{"", new Address{"200 West Ave", "London", 0}};
        return newEmployee(name, suite, p);
    }

private:
    static unique_ptr<Contact> newEmployee(const string &name, const int suite, const Contact &prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

int main()
{
    auto mEmployee = EmployeeFactory::newMAinOfficeEmployee("Jason Weirs", 111);
    auto cEmployee = EmployeeFactory::newContractEmployee("Emily Sass", 125);

    cout << "New main office employee:\n" << *mEmployee << endl;
    cout << "New contract employee:\n" << *cEmployee << endl;
    return 0;
}
