//
// Created by Juan on 5/8/2021.
//

#ifndef ABSTRACTFACTORY_DRINKFACTORY_H
#define ABSTRACTFACTORY_DRINKFACTORY_H

#include "HotDrinkFactory.h"
#include "HotDrink.h"
#include <map>
#include <functional>

class DrinkFactory
{
    map <string, unique_ptr<HotDrinkFactory>> m_hotDrinks;

public:
    DrinkFactory()
    {
        m_hotDrinks["tea"] = make_unique<TeaFactory>();
        m_hotDrinks["coffee"] = make_unique<CoffeeFactory>();
    }

    unique_ptr<HotDrink> makeDrink(const string &name)
    {
        auto drink = m_hotDrinks[name]->make();
        drink->prepare(200);
        return drink;
    }
};

class DrinkWithVolumeFactory
{
    map <string, function<unique_ptr<HotDrink>()>> factories;
public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = []() {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };

        factories["coffee"] = []() {
            auto coffee = make_unique<Coffee>();
            coffee->prepare(250);
            return coffee;
        };

    }

    unique_ptr<HotDrink> makeDrink(const string &name)
    {
        return factories[name]();
    }

};

#endif //ABSTRACTFACTORY_DRINKFACTORY_H
