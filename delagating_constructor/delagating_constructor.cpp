/* Delagating constructor
- Allow a constructor to invoke another constructor
    This is useful when you have multiple constructor that have common code

Note that the default constructor is calling a constructor with arugments
class Class
{
    Class():Class(val1, val2)
    {
        Class(arg1, arg2);
    }
}
*/
#include <iostream>
using namespace std;

#include "car.h"

int main()
{
    Car car1;
}