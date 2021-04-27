#include <iostream>
using namespace std;
#include "integer.h"


/*
Memory is assigned in the constructors
So make sure to release it in the destructor!
*/

Integer::Integer() //:Integer(0)
{
    p_int = new int{0};
    cout << "Integer(): address: " <<  this << endl;
}

Integer::Integer(int value)
{
    p_int = new int{value};
    cout << "Integer(): address: " <<  this << endl;
} 

Integer::Integer(const Integer &obj)
{
    // create deep copy
    p_int = new int{*obj.p_int};

    cout << "Integer(const Integer &)" << "address: " << this << " value: " << this->get_value() << endl;
    cout << " obj(right side of =) address: " << &obj << " value: " << obj.get_value() << endl;
}

Integer::Integer(Integer &&obj)
{
    // binding ref to r value is not allowed
    cout << " obj(right side of =) address: " << &obj << " value: " << obj.get_value() << endl;
    p_int = obj.p_int;
    obj.p_int = nullptr;
    cout << "Integer(Integer &&)" << "address: " << this << " value: " << this->get_value() << endl;
}

Integer& Integer::operator=(const Integer &obj)
{
    cout << " obj(right side of =) address: " << &obj << " value: " << obj.get_value() << endl;
    if (this == &obj) {
        return *this;
    }
    delete p_int;
    p_int = new int{*obj.p_int};
    cout << "operator=(const Integer &obj): " << "address: " << this << " value: " << this->get_value() << endl;
    return *this;
} 

Integer & Integer::operator=(Integer &&obj)
{
    // getting address from temporary is not allowed
    //cout << " obj(right side of =) address: " << &obj << "value: " << obj.get_value() << endl;
    if (this == &obj){
        return *this;
    }
    delete p_int;
    p_int = obj.p_int;
    obj.p_int = nullptr;
    cout << "Integer::operator=(Integer &&obj): " << "address: " << this << " value: " << this->get_value() << endl;
    return *this;
}

Integer::~Integer()
{
    delete p_int;
    cout << "~Integer(): address: " << this << endl;
}

int Integer::get_value() const
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