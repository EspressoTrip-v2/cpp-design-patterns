#include <iostream>
#include <functional>
#include <string>

using namespace std;

struct Logger1
{
    function<void()> func;
    string name;
    Logger1(const function<void()> &func, const string &name) : func(func), name(name)
    {}

    void operator()()
    {
        cout << "Start Log::\n";
        func();
        cout << "::End Log\n";
    }
};

template<typename Func>
struct Logger2
{
    Func func;
    string name;
    Logger2(const Func &func, const string &name) : func(func), name(name)
    {}

    void operator()()
    {
        cout << "Start Log::\n";
        func();
        cout << "::End Log\n";
    }
};

template<typename R, typename... Args>
struct Logger3
{
    function<R(Args...)> func;
    string name;
    Logger3(const function<R(Args...)> &func, const string &name) : func(func), name(name)
    {}
    auto operator()(Args...args)
    {
        cout << "Start::\n";
        auto result = func(args...);
        cout << "::End\n";
        return result;
    }
};

double add(double a, double b)
{
    cout << a << " + " << b << " = " << (a + b) << endl;
    return a + b;
}

int main()
{
    Logger1([]() { cout << "Hello World Test\n"; }, "Test Log")();
    Logger2([]() { cout << "Hello World Test2\n"; }, "Test Log2")();
    auto result = Logger3(function < double(double, double) > (add), "Add Func")(2, 3);
    cout << result << endl;
    return 0;
}
