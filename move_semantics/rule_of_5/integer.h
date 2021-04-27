#pragma once

class Integer {
public:
    int *p_int{0};

    // default constructor
    Integer();

    // parameterized constructor
    Integer(int value);

    // copy constructor
    Integer(const Integer &obj);

    // move constructor
    Integer(Integer &&obj);

    // copy assigment
    Integer & operator=(const Integer &);

    // move assigment
    Integer & operator=(Integer &&);     

    int get_value() const;

    void set_value(int value);

    ~Integer(); 
};