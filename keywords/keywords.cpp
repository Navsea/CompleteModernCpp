#include <iostream>
#include <typeinfo>
using namespace std;
/*
auto:
indicates teh storage class of a variable in C and pre- C++11
meaning since C++11 has changed to automatically infer the type from the initializer
so initializer is required
*/
auto f1 = 1.33f;
auto i1 = 5;
// auto e1; // will give error

auto sum = f1 + i1;

int sum_f(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "f1: " << f1 << " i1: " << i1 << " sum: " << sum << endl;
    cout << "type of sum is: " << typeid(sum).name() << endl;

    auto i2 = sum_f(5,3);
    cout << "i2 contains: " << i2 << " type of sum is: " << typeid(i2).name() << endl;

    // auto is very useful for lamba expression and templates, handled in later topic
    // you can find out what the type is by hovering your mouse over the variable!

    // !!!!! type qualifiers are not copied when using auto !!!!! except for references (as its just an alias to same memory loc) and pointers (as it still references the same memory loc as variable)
    const int i3 = 5;
    auto i4 = i3;
    // works just fine!
    i4 = 6;
    // now i5 is also a const
    const auto i5 = i3;
    // wont work
    ///i5 = 6;
    auto &r1 = i3;
    // wont work
    //r1 = 6;

    // avoid auto with references and pointers
    auto p1 = &i3;
    // wont work
    // *p1 = 5;

    // only works when initiliazer list appears on right side of assigment operator
    auto list = {1,2,3,4,5}; 
    // wont work
    //auto list2 {1,2,3,4,5};
    int list3[5]{1,2,3,4,5};

    return 0;
}