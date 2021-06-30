#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <memory>
#include <cmath>
using namespace std;

#include "boost/serialization/serialization.hpp"
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
using namespace boost;

struct Address
{
    string street, city;
    int suite;

    Address() = default;
    Address(const string &street, const string &city, int suite) : street(street), city(city), suite(suite)
    {}
    friend ostream &operator<<(ostream &os, const Address &address)
    {
        os << "street: " << address.street << "\ncity: " << address.city << "\nsuite: " << address.suite << endl;
        return os;
    }

private:
    friend class serialization::access;

    template<typename archive>
    void serialize(archive &ar, const unsigned version)
    {
        // Serialize members
        ar & street;
        ar & city;
        ar & suite;
    }
};

struct Contact
{
    string name;
    Address *address;

    Contact() = default;
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
private:
    friend class serialization::access;

    template<typename archive>
    void serialize(archive &ar, const unsigned version)
    {
        // Serialize members
        ar & name;
        ar & address;
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
    auto clone = [](const Contact &c) {
        // Serializes Object
        ostringstream oss;
        archive::text_oarchive oa(oss);
        oa << c;

        string s = oss.str();
        cout << s << endl;

        // Deserialize object
        istringstream iss(s);
        archive::text_iarchive ia(iss);
        Contact result;
        ia >> result;
        return result;
    };

    auto john = EmployeeFactory::newMAinOfficeEmployee("John Doe", 123);
    auto jane = clone(*john);
    jane.name = "Jane Doe";
    cout << jane << endl;
    cout << *john << endl;

    return 0;
}
