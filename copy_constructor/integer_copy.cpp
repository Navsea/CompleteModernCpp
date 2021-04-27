#include "integer_copy.h"

/*
Memory is assigned in the constructors
So make sure to release it in the destructor!
*/

IntegerCopy::IntegerCopy()
{
    p_int = new int{0};
}

IntegerCopy::IntegerCopy(int value)
{
    p_int = new int{value};
} 

IntegerCopy::IntegerCopy(const IntegerCopy &obj)
{
    // create deep copy
    p_int = new int{*obj.p_int};
}

IntegerCopy::~IntegerCopy()
{
    delete p_int;
}

int IntegerCopy::get_value()
{
    return *p_int;
}

void IntegerCopy::set_value(int value)
{
    if (p_int != nullptr)
    {
        *p_int = value;
    }
}