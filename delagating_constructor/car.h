// This is a header guard, similar to #ifndef from C
// This is widely accepted, but not standard
#pragma once


class Car
{
private:
    float fuel{0};  
    float speed{0};
    int passengers{0}; 
    int array[5]{1,2,3,4,5};
    int *p_int{}; //nullptr
    char *p_char = new char[8]{'H', 'e', 'l', 'l', 'o'};
    // auto i{4}; cannot declare non-static data member with auto!
    static int total_count;
public:
    Car();
    Car(float amount);
    Car(float amout, int pass);
    ~Car();
    void fill_fuel(float amount);
    void accelerate();
    void brake();
    void add_passengers(int count);
    void foo(const Car &car);
    void dashboard() const;
    static void show_count();
};