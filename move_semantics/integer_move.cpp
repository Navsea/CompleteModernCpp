#include <iostream>
using namespace std;
#include "integer_move.h"


/*
Memory is assigned in the constructors
So make sure to release it in the destructor!
*/

IntegerMove::IntegerMove() //:IntegerMove(0)
{
    cout << "IntegerMove()" << endl;
    p_int = new int{0};
}

IntegerMove::IntegerMove(int value)
{
    cout << "IntegerMove(value)" << endl;
    p_int = new int{value};
} 

IntegerMove::IntegerMove(const IntegerMove &obj)
{
    cout << "IntegerMove(const IntegerMove &)" << endl;
    // create deep copy
    p_int = new int{*obj.p_int};
}

IntegerMove::IntegerMove(IntegerMove &&obj)
{
    cout << "IntegerMove(IntegerMove &&)" << endl;
    p_int = obj.p_int;
    obj.p_int = nullptr;
}

IntegerMove::~IntegerMove()
{
    cout << "~IntegerMove()" << endl;
    delete p_int;
}

int IntegerMove::get_value() const
{
    return *p_int;
}

void IntegerMove::set_value(int value)
{
    if (p_int != nullptr)
    {
        *p_int = value;
    }
}