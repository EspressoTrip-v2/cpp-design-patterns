#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// DEPENCENCY INVERSION PRINCIPLE
// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details.
//    Details should depend on abstractions.

using namespace std;
using namespace boost;

enum class Relationship
{
	parent, child, sibling
};

struct Person
{
	string name;
};

// Compliant
struct RelationshipBrowser
{
	virtual ~RelationshipBrowser() = default;
	virtual vector<Person> findAllChildrenOf(const string& name) = 0;
};

struct Relationships : RelationshipBrowser // Low level
{
	virtual ~Relationships() = default;
	vector<tuple<Person, Relationship, Person>> relations;

	void addParentAndChild(const Person& parent, const Person& child)
	{
		relations.push_back({ parent, Relationship::parent, child });
		relations.push_back({ child, Relationship::child, parent });
	}

	// Inherited via RelationshipBrowser
	virtual vector<Person> findAllChildrenOf(const string& name) override
	{
		vector<Person> results;
		for (auto& tup : relations)
		{
			auto& item = get<0>(tup);
			auto& rel = get<1>(tup);
			auto& child = get<2>(tup);
			if (item.name == name && rel == Relationship::parent)
				results.push_back(child);
		}

		return results;
	}
};

// Compliant
struct Research // High level
{
	explicit Research(RelationshipBrowser& browser)
	{
		for (auto& child : browser.findAllChildrenOf("John"))
		{
			cout << "John has a child called " << child.name << endl;
		}
	};
};

// Non Compliant
/*
struct Research // High level
{
	explicit Research(Relationships& relationships)
	{
		auto& relations = relationships.relations;
		for (auto& tup : relations)
			cout << "First: " << get<0>(tup).name << ", Type: "
			<< lexical_cast<string>(static_cast<int>(get<1>(tup)))
			<< ", Second: " << get<2>(tup).name << endl;
	};
};
*/

int main()
{
	Person parent{ "John" };
	Person child1{ "Chris" }, child2{ "Matt" };

	Relationships relationships;
	relationships.addParentAndChild(parent, child1);
	relationships.addParentAndChild(parent, child2);

	Research _{ relationships };

	return 0;
}