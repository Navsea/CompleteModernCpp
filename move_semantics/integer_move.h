#pragma once

class IntegerMove
{
    int *p_int{};
    public:
        IntegerMove();
        IntegerMove(int value);
        // IntegerMove(Integer value); This does not work, because passing by value would cause the copy constructor to be invoked again! circular ref
        // You should also use const keyword! as you are not trying to modify the original object
        IntegerMove(const IntegerMove &obj);
        IntegerMove(IntegerMove &&obj);
        ~IntegerMove();
        int get_value() const;
        void set_value(int value);
};