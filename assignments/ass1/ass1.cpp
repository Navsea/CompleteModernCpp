#include "math.h"
#include <iostream>
using namespace std;

// See section2 video 20

int main()
{
    int i1{4}, i2{5}, r1{1};
    int * a = nullptr, *b = a, *result = a;
    a = &i1;
    b = &i2;
    result = &r1;

    int add = Add(a,b);
    cout << "The result of using Add() w a=" << *a << " and b=" << *b << " results in " << add << endl;
    AddVal(a, b, result);
    cout << "The result of using AddVal() w a=" << *a << " and b=" << *b << " results in " << *result << endl;
    cout << "The result of using Swap() w a=" << *a << " and b=" << *b;
    Swap(a, b);
    cout << " results in a=" << *a << " and b=" << *b << endl;
    Factorial(a, result);
    cout << "The result of using Factorial() w a=" << *a << " results in " << *result << endl;
}