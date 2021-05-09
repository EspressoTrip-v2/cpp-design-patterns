#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <memory>
#include <cmath>
#include "boost/lexical_cast.hpp"
using namespace std;

class Point
{

    Point(float x, float y) : x(x), y(y)
    {}

    float x, y;

public:
    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }

    struct PointFactory
    {
        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        }

        static Point NewPolar(float r, float theta)
        {
            return {r * cos(theta), r * sin(theta)};
        }
    };
};


int main()
{

    auto p = Point::PointFactory::NewPolar(5, M_PI_4);
    cout << p << endl;
    int num{100};
    cout << "Number: " << boost::lexical_cast<string>(num) << endl;
    return 0;
}
