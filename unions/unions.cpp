/*
- gives the ability to respresent all members of the union in the same memory
- saves space (because you dont have to allocate mem for each type of var) and will allocate mem for the largest member
- no way to know which types it holds
- nested types with non-def constructors deletes the default constr of the union
- cannot assign objects of user def types directly to a union member
- user def types are not destroyed implicitly
- cannot have a base class
- cannot derive from a union
- by default members are public
*/
#include <iostream>
using namespace std;
#include "user_def_types.h"

union Test {
    int x;
    char ch;
    double d;
    Test(): ch{'a'} {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~Test() {
        cout << __PRETTY_FUNCTION__ << endl; 
    }
};

// Here the union contains user defined classes with UD constructors
// So default constructor for UDT is deleted, you cannot even use default keyword
union UDT {
    A classA;
    B classB;
    string s;

    UDT() {

    }
    ~UDT() {

    }
};

int main() {
    Test t;
    cout << t.ch << endl;
    t.x = 100;

    cout << t.x << endl;
    // you can still look at it as character, even though its defined as an integer now
    cout << t.ch << endl;

    cout << "The size of the union is: " << sizeof(t) << endl;

    UDT udt;
    // You have to manually create these UDT
    // You cannot assign to them as they have not been created yet! so cannot use assigment operator
    //udt.classA = A{};
    //udt.s = "Hello world!";
    // you need to use placement new operator! only initializes memory, but does not allocate
    new(&udt.s) std::string{"Hello world!"};
    cout << "size of udt after initializing w string: " << sizeof(udt) << endl;
    new(&udt.classA) A{};
    cout << "size of A after initializing w string: " << sizeof(udt) << endl;

    return 0;
}