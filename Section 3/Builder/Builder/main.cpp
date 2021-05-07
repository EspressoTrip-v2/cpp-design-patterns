#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>
#include <memory>
#include <cstdio>

// BUILDER
using namespace std;

struct HtmlBuilder; // This only works if class a is not a composite of class b, else requires pointers

struct HtmlElement
{
	string name, text;
	vector<HtmlElement> elements;
	const size_t indentSize{ 2 };

	HtmlElement() = default;
	HtmlElement(const string& name, const string& text) :name{ name }, text{ text } {};

	string str(int indent = 0) const
	{
		ostringstream oss;
		string i(indentSize * indent, ' ');

		oss << i << "<" << name << ">" << endl;
		if (text.size() > 0)
			oss << string(indentSize * (indent + 1), ' ') << text << endl;

		for (const auto& e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}

	static unique_ptr<HtmlBuilder> build(string rootName)
	{
		return make_unique<HtmlBuilder>(rootName);
	}
};

struct HtmlBuilder
{
	HtmlElement root;

	HtmlBuilder() = default;
	HtmlBuilder(string rootName)
	{
		root.name = rootName;
	}

	HtmlBuilder& addChild(string childName, string childText) // *fluent*
	{
		HtmlElement e{ childName, childText };
		root.elements.emplace_back(e);
		return *this;
	}

	string str() const
	{
		return root.str();
	}

	operator HtmlElement() { // Type operator overload
		return root;
	}
};

int main()
{
	HtmlBuilder builder{ "ul" };

	builder.addChild("li", "Hello").addChild("li", "World"); // Fluent Interface *fluent* returns reference to builder for chaining

	cout << builder.str();
	auto builder2 = HtmlElement::build("div")->addChild("div", "First Child").addChild("p", "Second Child");
	cout << builder2.str();

	auto& elem = builder;
	cout << elem.str();

	return 0;
}