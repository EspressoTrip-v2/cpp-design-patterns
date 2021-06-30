#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>
using namespace std;

class Creature
{
    enum Abilities
    {
        str, agl, intl, count
    };

    array<int, count> abilities;
public:
    Creature() : abilities{}
    {}
    void setStrength(int value)
    { abilities[str] = value; }
    void setAgility(int value)
    { abilities[agl] = value; }
    void setIntelect(int value)
    { abilities[intl] = value; }
    int getStrength()
    { return abilities[str]; }
    int getAgility()
    { return abilities[agl]; }
    int getIntelect()
    { return abilities[intl]; }

    int sum()
    { return ::accumulate(abilities.begin(), abilities.end(), 0); }
    double average()
    { return sum() / static_cast<double>(count); }
    int maxAbility()
    { return *::max_element(abilities.begin(), abilities.end()); };

};

int main()
{
    Creature animal;
    animal.setAgility(20);
    animal.setIntelect(50);
    animal.setStrength(100);

    cout << "Sum of abilities " << animal.sum() << ", average " << animal.average() << ", max " << animal.maxAbility();

    return 0;
}
