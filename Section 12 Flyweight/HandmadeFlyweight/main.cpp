#include <iostream>
#include <string>
#include "boost/bimap.hpp"
using namespace std;
using namespace boost;

using key = uint32_t;

struct User
{

protected:
    static bimap<key, string> names;
    static key seed;
    static void keyAdd(string_view &s)
    {
        names
        auto it = names.right.find(s);
        if (it == names.right.end())
        {
            key id = ++seed;
            names.insert({seed, s});

        }
    }

};

key User::seed{0};
bimap<key, string> User::names{};

int main()
{

    return 0;
}
