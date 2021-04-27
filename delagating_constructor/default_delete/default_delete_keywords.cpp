#include <iostream>
using namespace std;

/* if you only need to do default initialization in the constructor
then you should just use the assigment in the class itself!
but when youve already declared a parameterized consturctor this wont work!
you can say to the compiler to create a default constructor without implementing it full by assigning the default keyword to the constructor definition

To avoid that the compiler would create a default constructor/destructor, you could use the keyword delete
In this case you should also delete the default assignment operator!

You can also delete certain functions, see example of passing a float to a function that only accepts ints
*/

class Integer 
{
    int value{0};   // Dont need the default constructor!
public:
    Integer() = default; // ask compiler to create default constructor
    // Integer(){
    //     value = 0;
    // }
    Integer(int value)
    {
        this->value = value;
    }
    //Integer(const Integer &) = default; //creates a default copy constructor, but here it didnt matter if we explicitly asked the compiler or not, he wouldv created one
    Integer(const Integer &) = delete;

    void set_value(int value)
    {
        this->value = value;
    }
    // explicitly avoid the function being called w floats
    void set_value(float value ) = delete;
    int get_value() const
    {
        return value;
    }
};

class Testje {
    int value{0};
};

int main()
{
    Integer i;
    // Integer i2(2); doesnt work anymore because the default copy constructor is never created

    i.set_value(6);
    cout << "integer i: " << i.get_value() << endl;
    // will not build anymore, as weve explicitly deleted the function with float as param
    //i.set_value(5.6); // youll get a warning but it will do it and trucate!
    //cout << "integer i: " << i.get_value() << endl;

    Testje test;
    return 0;
}