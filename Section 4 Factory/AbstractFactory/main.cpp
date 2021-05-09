#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <memory>
#include <cmath>

using namespace std;

#include "HotDrinkFactory.h"
#include "DrinkFactory.h"

int main()
{
    // Class Factory methods
    DrinkFactory factory;
    auto tea = factory.makeDrink("tea");
    auto coffee = factory.makeDrink("coffee");

    // Functional factory method
    DrinkWithVolumeFactory dv;
    auto tea2 = dv.makeDrink("tea");
    auto coffee2 = dv.makeDrink("coffee");

    return 0;
}