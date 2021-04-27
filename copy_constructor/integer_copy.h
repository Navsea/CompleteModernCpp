#pragma once

class IntegerCopy
{
    int *p_int{};
    public:
        IntegerCopy();
        IntegerCopy(int value);
        // IntegerCopy(Integer value); This does not work, because passing by value would cause the copy constructor to be invoked again! circular ref
        // You should also use const keyword! as you are not trying to modify the original object
        IntegerCopy(const IntegerCopy &obj);
        ~IntegerCopy();
        int get_value();
        void set_value(int value);
};