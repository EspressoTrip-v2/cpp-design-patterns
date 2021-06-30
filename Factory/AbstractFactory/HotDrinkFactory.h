//
// Created by Juan on 5/8/2021.
//

#ifndef ABSTRACTFACTORY_HOTDRINKFACTORY_H
#define ABSTRACTFACTORY_HOTDRINKFACTORY_H

#include "HotDrink.h"

struct HotDrinkFactory // Abstract Factory
{
    virtual unique_ptr<HotDrink> make() = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() override
    {
        return make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() override
    {
        return make_unique<Coffee>();
    }
};

#endif //ABSTRACTFACTORY_HOTDRINKFACTORY_H
