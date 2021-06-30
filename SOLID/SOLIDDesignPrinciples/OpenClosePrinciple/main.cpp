#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// OPEN FOR EXTENSION CLOSED FOR MODIFICATION
// Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.
using namespace std;
using namespace boost;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
	string name;
	Color color;
	Size size;
};

// Specification Design pattern
template<typename T> struct AndSpecification;
template<typename T> struct Specification
{
	virtual bool isSatisfied(T* item) const = 0;
	virtual ~Specification() = default;
};

template<typename T> struct Filter
{
	virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
	virtual ~Filter() = default;
};

// Overloaded Operator
template <typename T> AndSpecification<T> operator&&
(const Specification<T>& first, const Specification<T>& second)
{
	return { first, second };
}

// Better Filter Implementation
struct BetterFilter : public Filter<Product>
{
	virtual vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override
	{
		vector<Product*> result;
		for (auto& item : items)
			if (spec.isSatisfied(item))
				result.push_back(item);

		return result;
	}

	virtual ~BetterFilter() = default;
};

// Color Specification
struct ColorSpecification : public Specification<Product>
{
	Color m_color;
	explicit ColorSpecification(Color color) :m_color{ color } {};

	virtual bool isSatisfied(Product* item) const override
	{
		return item->color == m_color;
	}
};

// Size Specification
struct SizeSpecification : public Specification<Product>
{
	Size m_size;
	explicit SizeSpecification(Size size) :m_size{ size } {};

	virtual bool isSatisfied(Product* item) const override
	{
		return item->size == m_size;
	}
};

// Combinator
template<typename T> struct AndSpecification : public Specification<T>
{
	const Specification<T>& m_specA;
	const Specification<T>& m_specB;
	AndSpecification(const Specification<T>& specA, const Specification<T>& specB) :m_specA{ specA }, m_specB{ specB }{};

	virtual bool isSatisfied(T* item) const override
	{
		return m_specA.isSatisfied(item) && m_specB.isSatisfied(item);
	}
};

int main()
{
	Product apple{ "Apple", Color::green, Size::small };
	Product tree{ "Tree", Color::green, Size::large };
	Product house{ "House", Color::blue, Size::large };
	Product car{ "Car", Color::red, Size::medium };

	vector<Product*> products{ &apple, &tree,&house, &car };

	BetterFilter bf;
	ColorSpecification green{ Color::green };
	for (auto& item : bf.filter(products, green))
		cout << item->name << " is Green" << endl;

	SizeSpecification large{ Size::large };
	for (auto& item : bf.filter(products, large))
		cout << item->name << " is Large" << endl;

	AndSpecification<Product> largeAndGreen{ large, green };
	// Better way with operator overload
	auto spec = green && large;
	for (auto& item : bf.filter(products, largeAndGreen))
		cout << item->name << " is Green and Large" << endl;

	return 0;
}