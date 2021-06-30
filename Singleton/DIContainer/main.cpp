#include <iostream>
#include <string>
#include <memory>
#include "di.h"
#include "boost/lexical_cast.hpp"
using namespace boost;
using namespace std;

struct IFoo
{
    virtual string name() = 0;
};

struct Foo : IFoo
{
    static int id;
    Foo()
    {
        id++;
    }
    string name() override
    {
        return "Foo id: " + lexical_cast<string>(id) + "\n";
    }
};

int  Foo::id = 0;
struct Bar
{
    std::shared_ptr<IFoo> foo;
};
int main()
{
    auto injector = di::make_injector(di::bind<IFoo>().to<Foo>().in(di::singleton));

    auto bar1 = injector.create<std::shared_ptr<Bar>>();
    auto bar2 = injector.create<std::shared_ptr<Bar>>();

    cout << bar1->foo->name();
    cout << bar2->foo->name();

    return 0;
}
