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
        radius *= factor;
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

template<typename T>
struct ColoredShape : T // Mixin Inheritance
{
    string color;
    ColoredShape() = default;

    template<typename...Args>
    ColoredShape(string color, Args...args): // Variadic recursion on the constructor
            color(move(color)), T(forward<Args>(args)...)
    {}

    string str() override
    {
        ostringstream oss;
        oss << T::str() << " is colored " << color;
        return oss.str();
    }
};

template<typename T>
struct TransparentShape : T
{
    uint8_t transparency;
    TransparentShape() = default;

    template<typename... Args>
    TransparentShape(uint8_t transparency, Args...args) : transparency(transparency), T(forward<Args>(args)...)
    {}

    string str() override
    {
        ostringstream oss;
        oss << T::str() << " has a transparency of " << getTransparency() << "%";
        return oss.str();
    }

    double getTransparency()
    {
        return static_cast<double>(transparency) / 255.f * 100.f;
    }

};

int main()
{
    TransparentShape<ColoredShape<Circle>> cc(50, "Red", 10);
    cc.resize(2);
    cout << cc.str();
    return 0;
}
