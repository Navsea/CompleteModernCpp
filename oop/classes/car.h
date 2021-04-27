// This is a header guard, similar to #ifndef from C
// This is widely accepted, but not standard
#pragma once

/* Constructor
- Automatically executed when instance is created
- Used for initialization
- Does not have a return type
- Can accept arguments and so can be overloaded

Default constructor: 
- Does not have arguments
- Automatically created by the compiler if there are not other constructors defined

Parameterized constructor:
- Constructor that accepts one or more argumetns
- Used to intialize an object with user-defined values
- Never synthesized by the compiler
- When defined, it will block the generation of the default constructor
*/
/* Destructor
- Automatically invoked when an object is destroyed
- Used for freeing resources that were allocated in the objects lifetime
- Class can only have one destructor, without arguments
- Same name as constructor with preceded with ~
*/

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
public:
    Car();
    Car(float amount);
    ~Car();
    void fill_fuel(float amount);
    void accelerate();
    void brake();
    void add_passengers(int count);
    void foo(const Car &car);
    void dashboard();
};