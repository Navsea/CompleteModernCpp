#include "integer.h"

/*
Memory is assigned in the constructors
So make sure to release it in the destructor!
*/

Integer::Integer()
{
    p_int = new int{0};
}

Integer::Integer(int value)
{
    p_int = new int{value};
}

Integer::~Integer()
{
    delete p_int;
}

int Integer::get_value()
{
    return *p_int;
}

void Integer::set_value(int value)
{
    if (p_int != nullptr)
    {
        *p_int = value;
    }
}