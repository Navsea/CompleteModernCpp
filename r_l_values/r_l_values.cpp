/*
- L-value has a name, R does not
- All variables are l-values, R-values are temporary
- L value can be assigned a value, R not
- Some expressions return L and some R
- L-values persist beyond the expression, R does not
- Functions that return by reference return l-value (func can appear on left side!)
- Functions that return by value return r-value
- References to l value exist and also to r value
*/

/* R-value references
- Have been implemented for move semantics
- a reference created to a temporary, always
- created with the && operator
- cannot point to l-values
- allows you to detect temporaries in expressions
*/

#include <iostream>
using namespace std;

// returns by value, so an r-value
int add(int x, int y) {
    return x + y;
}
// returns a reference, so an l-value
// !!! So this function can appear on the left side of an assigment !!!
// The return value will be updated with whatever is on the right side of the assigment
int& transform(int &x)
{
    x = x%3;
    return x;
}

// overloaded functions
void print(int &x)
{
    cout << "Print(int &) called" << endl;
}

void print(const int &x)
{
    cout << "Print(const int &) called" << endl;
}

void print(int &&x)
{
    cout << "Print(int &&) called" << endl;
}


int main()
{
    // x is an l value, 5 is an r value
    int x = 4;
    int y = 6;

    // expression returns an l value
    int result = (x + y);

    // expression return an r value
    x++;

    cout << "value of x: " << x << endl; 
    int &result2 = transform(x);
    cout << "value of result: " << result2 << endl;
    cout << "value of x: " << x << endl;


    transform(x) = 10;
    cout << "value of x: " << x << endl; 

    // r value reference
    int &&r_ref = 10;
    int &&r_ref2 = add(6, 7); // add returns an r value
    int &&r_ref3 = 9+3; // expression return r value

    //error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    //int &&r_ref4 = transform(x);

    // you can assign an r value to an l value though if l value is const
    const int &r_ref4 = 10;

    print(x);
    // here the function call could call the const l value overloaded func or the r-value
    // by default it will choose r-value
    print(10);

}

