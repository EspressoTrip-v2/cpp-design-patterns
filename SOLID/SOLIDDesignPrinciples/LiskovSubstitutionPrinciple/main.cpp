#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// LISKOV SUBSTITION PRINCIPLE
using namespace std;
using namespace boost;

class Rectangle
{
protected:
	int m_width, m_height;

public:
	Rectangle(int width, int height) :m_width{ width }, m_height{ height }{};

	virtual void setWidth(int width) {
		m_width = width;
	}

	int getWidth() {
		return m_width;
	}

	virtual void setHeight(int height) {
		m_height = height;
	}

	int getHeight() {
		return m_height;
	}

	int area() { return m_width * m_height; }
};

class Square : public Rectangle
{
public:
	virtual ~Square() = default;
	Square(int width, int height) :Rectangle{ width, height } {};
	virtual void setWidth(int width) override
	{
		m_width = m_height = width;
	}

	virtual void setHeight(int height) override
	{
		m_width = m_height = height;
	}
};

void process(Rectangle& r) {
	int w = r.getWidth();
	r.setHeight(10);

	cout << "Expected area: " << w * 10
		<< ", got: " << r.area() << endl;
}

int main()
{
	// Example of breaking Liskov Substitution Principle. Process breaks when using Square;
	Rectangle r{ 3,4 };
	process(r);

	Square s{ 4,4 };
	process(s);
	return 0;
}