#include <iostream>
#include "math.h"
using namespace std;

// See section2 video 22

int main()
{
    int a{4}, b{5}, r{1};

    Add(a,b,r);
    cout << "The result of using Add() w a=" << a << " and b=" << b << " results in " << r << endl;
    cout << "The result of using Swap() w a=" << a << " and b=" << b;
    Swap(a, b);
    cout << " results in a=" << a << " and b=" << b << endl;
    Factorial(a, r);
    cout << "The result of using Factorial() w a=" << a << " results in " << r << endl;

    return 0;
}
