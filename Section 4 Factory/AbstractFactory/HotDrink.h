//
// Created by Juan on 5/8/2021.
//
#ifndef ABSTRACTFACTORY_HOTDRINK_H
#define ABSTRACTFACTORY_HOTDRINK_H

#include <iostream>

using namespace std;

struct HotDrink // Abstract
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Take tea bag, boil water, pour " << volume << "ml, add lemon" << endl;
    }
};

struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Grind some beans, boil water. pour " << volume << "ml, add some cream" << endl;
    }
};

#endif //ABSTRACTFACTORY_HOTDRINK_H
