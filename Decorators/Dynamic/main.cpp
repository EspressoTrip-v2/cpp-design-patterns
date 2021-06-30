#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Shape
{
    virtual ~Shape() = default;
    virtual string str() = 0;
};

struct Circle : Shape
{
    float radius;
    Circle() = default;
    constexpr explicit Circle(float radius) : radius(radius)
    {}
    void resize(float factor)
    {
        radius * factor;
    }
    string str() override
    {
        ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
};

struct Square : Shape
{
    float side;
    Square() = default;
    constexpr explicit Square(float side) : side(side)
    {}

    [[nodiscard]]
    constexpr float area() const
    {
        return side * side;
    }

    string str() override
    {
        ostringstream oss;
        oss << "A square with side of " << side;
        return oss.str();
    }

};

struct ColoredShape : Shape
{
    string color;
    Shape &shape;
    ColoredShape(const string &color, Shape &shape) : color(color), shape(shape)
    {}
    string str() override
    {
        ostringstream oss;
        oss << shape.str() << " and is colored " << color;
        return oss.str();
    }

};

struct TransparentShape : Shape
{
    uint8_t transparency;
    Shape &shape;
    TransparentShape(float transparency, Shape &shape) : transparency(transparency), shape(shape)
    {}

    [[nodiscard]]
    float getTransparency() const
    {
        return static_cast<float>(transparency) / 255.00F * 100.00F;
    }

    string str() override
    {
        ostringstream oss;
        oss << shape.str() << " and its transparency is " << getTransparency() << "%.";
        return oss.str();
    }
};

void printShape(Shape &s)
{
    cout << s.str() << endl;
}

int main()
{
    Circle c{50.0};
    Square sq{100};
    cout << c.str() << "\n";
    cout << sq.str() << "\n";
    ColoredShape c2{"Red", c};
    cout << c2.str() << "\n";

    TransparentShape tp(20, sq);
    cout << tp.str() << "\n";

    TransparentShape nt{51, c2};
    cout << nt.str() << "\n";

    printShape(c);
    printShape(sq);
    printShape(tp);

    return 0;
}
