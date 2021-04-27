#include <iostream>
#include "Integer.h"
using namespace std;

void print(const Integer a)
{

}

int main()
{
    Integer a{5};
    // compiler does not know how to convert Integer to int
    //int x = a;  

    // type conversion operator
    // operator<type>() no arguments, not return type
    // after defining the cast function it works
    //int x = a;
    // you can add the explicit to the function, so that you need to explicitly use static_cast<int>
    int x = static_cast<int>(a);

    return 0;
}