#pragma once

class Integer
{
    int *p_int{};
    public:
        Integer();
        Integer(int value);
        ~Integer();
        int get_value();
        void set_value(int value);
};