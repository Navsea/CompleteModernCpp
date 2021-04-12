#include <iostream>
using namespace std;

// POINTERS

// A pointer stores the address of a variable or object
// here p2 is not a pointer, you need to declare every point variable with *
// some compilers will give error if you use uninitialized pointers
int *p1, p2;
// use nullptr to initialize it with some value (0) nullptr is typesafe as apposed to NULL
// p7 is value initialized to nullptr
// you cannot read of write from nullptrs but it will compile, you will get exception thrown
int *p3 = nullptr, *p4 = p3, *p5, *p7{};

int i1{5};

// Pointers can only contain something of the same type: this generates an error
//float * p5 = &i1;
// You could make pointer that is able to point to different types
void *p6 = &i1;

// REFERENCES
// Defines an alternative name for variables
// Initializer is always required
// Preferred over pointer!
// Refferent should almost always be a variable, not a literal
// Bound to referent for ever, cannot be to refer to other variable
// NO MEMORY IS USED FOR REFERENCE
int i2{6};
int &r1 = i2;

// does not compile
//int &r2;

/*
Differences between pointers and references
1. References always need an initializer, pointers do not (nullptr or nothing)
2. References need an lvalue as initializer, pointers do not
3. References are bound to referent, pointer can start to other variables during lifetime
4. References do not require its own storage, its just an alias, while pointers have stored the address that its pointing to (so also it has a different address when using &)
5. To access the value for references no dereference operator is needed
*/

void swap_pass_by_value(int x, int y);
void swap_pass_by_address(int *x, int *y);
void swap_pass_by_reference(int &x, int &y);

int main()
{
    // POINTERS
    p1 = &i1;

    cout << "The address of i1 is: " << p1 << " the value is: " << *p1 << endl;
    cout << "The address of p5(uninit) is: " << p5 << " The address of p3 is: " << p3 << " The address of p4 is: " << p4 << " The address of p7 is: " << p7 << endl;
    cout << "The address of i1 using void pointer is: " << p6 << " the value is: " << *(int*)p6 << endl;
    *p1 = 10;
    cout << "Changed value of i1 via pointer: " << *p1 << endl;

    // REFERENCES
    cout << "The value of i2: " << i2 << " The value of r1: " << r1 << " The address of i2: " << &i2 << " The address of r1: " << &r1 << endl;
    i2 = 9;
    cout << "Changed the value of i2: " << i2 << " The value of r1: " << r1 << " is also changed" << endl;
    r1 = 11;
    cout << "Changed the value of r1: " << r1 << " The value of i2: " << i2 << " is also changed" << endl;

    r1 = i1;
    cout << "Assigned i1 w value: " << i1 << " to r1, but r1 address did not change: " << &r1 << " only the value for that address " << r1 << " is changed, i2 is also updated: " << i2 << endl << endl;

    // How to decide on reference or pointer
    cout << "How to decide on reference or pointer" << endl;
    int i3{3}, i4{4};

    swap_pass_by_value(i3, i4);
    // Note that the variables did not change after calling the swap function
    // This is because when passing the arguments by value a copy is taken of the variables
    cout << "i3 = " << i3 << " and i4 = " << i4 << endl;

    swap_pass_by_address(&i3, &i4);
    // Note that the variables DID change after calling the swap function
    // This is because when passing the arguments by address the value of where the pointer is pointing to is changed
    cout << "i3 = " << i3 << " and i4 = " << i4 << endl;
    swap_pass_by_address(&i3, p3);

    swap_pass_by_reference(i3, i4);
    // Note that the variables DID change after calling the swap function
    // This is because when passing the arguments by reference the value of the address location is changed
    cout << "i3 = " << i3 << " and i4 = " << i4 << endl;

    return 0;
}

void swap_pass_by_value(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;

    cout << "x = " << x << " and y = " << y << endl;
}

void swap_pass_by_address(int *x, int *y)
{
    // make sure to check for nullptr when dereferencing to avoid crashing
    if (x != nullptr and y != nullptr)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
        cout << "x = " << *x << " and y = " << *y << endl;
    }
    else
    {
        cout << "Yo, are your trying to make me crash?" << endl;
    }
}

void swap_pass_by_reference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;

    cout << "x = " << x << " and y = " << y << endl;
}