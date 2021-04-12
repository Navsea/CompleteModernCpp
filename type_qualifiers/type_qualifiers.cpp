
#include <iostream>
#include <cmath>
using namespace std;

// Replaces C macros
// commonly used with references or to avoid magic numbers
// for constant always use UPPER CASE
const int I1 = 5;

// volatile is another type qualifier

void calc_circle(float radius)
{
    // This constant is only known within the scope of this function, as apposed to macros
    const float PI = 3.141592;
    cout << "A circle with radius: " << radius << " has an area of: " << PI * pow(radius,2) << " and a circumference of: " << 2*PI*radius << endl;

    // You cannot change a constant
    //PI = 5.1;
}

// Typically for arugments you use const to they cant change the passed value.
// This way you avoid that the copy needs to happen when passing by value
void print(const int &ref)
{
    cout << ref << endl;
}

int main()
{
    calc_circle(1.2);

    // PI is not known here, code would give compiler error
    //cout << PI << endl;

    // This also gives an error as you need to always initiliaze a constant
    //const int I2;

    // Not allowed to create a that is not constant pointer to a constant
    //int * p1 = &I1;
    // This is a pointer to a constant int and not a constant pointer
    const int * p2 = &I1;

    int i2{5};
    const int * p3 = &i2;
    // Even though i2 is not a constant you cannot change it because the pointer is defined as pointing to a cst
    //*p3 = 6;

    // this is a constant pointer to a constant int
    const int * const p4 = &I1;

    // Note that we create a refence with an r value!
    // with const this is possible, because no one can change the value, it does not require an address
    const int &r1 = 4;
    int &r2 = i2;
    print(r1);
    print(r2);
    // This also works because literal is also constant
    print(10);
}