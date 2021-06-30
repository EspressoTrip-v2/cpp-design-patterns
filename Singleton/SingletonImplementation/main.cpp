#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <map>
#include "boost/lexical_cast.hpp"

using namespace std;
using namespace boost;

class SingletonDatabase
{
private:
    map<string, int> m_capitals;
    SingletonDatabase()
    {
        cout << "Initializing the database\n";
        ifstream ifs{"capitals.txt"};
        if (!ifs)
            cout << "Cant read file" << endl;
        string s, s2;
        while (getline(ifs, s))
        {
            getline(ifs, s2);
            m_capitals[s] = lexical_cast<int>(s2);
        }
    }
public:
    SingletonDatabase(const SingletonDatabase &obj) = delete;
    SingletonDatabase operator=(const SingletonDatabase &obj) = delete;
    static SingletonDatabase &get()
    {
        static SingletonDatabase db;
        return db;
    }
    int getPopulation(const string &name)
    {
        return m_capitals[name];
    }
};

int main()
{
    string city{"Tokyo"};
    cout << city << " has a population of: " << SingletonDatabase::get().getPopulation(city) << endl;
    return 0;
}
