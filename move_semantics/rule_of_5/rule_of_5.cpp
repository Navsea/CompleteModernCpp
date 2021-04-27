/* Rule of 5, resource management (doenst really hold true with fno-elide option)
- Some class owns a resource, may be pointer, file handle, socket, ect.
- You have to decide on the action that needs to take place on copy, move and destruction

- If a class has ownership semantics you require a user implemented:
    - destructor
    - copy constructor
    - copy assigment operator
    - move constructor
    - move assigment operator

This to properly handle the resource.
*/
/* Rule of 0
- No ownership semantics
- No user defined functions need to be implemented
- Compiler will automatically provide the required functions
- But if you define one of those, the compiler will not automatically synthesize the other functions!
*/

/*
When you implement one of the 5, auto synthesis for the others are not generated!
You dont have to implement the others, but you have to tell the compiler to generate them with default keyword
*/
/* 
Here we make a wrapper class, where the constructors and operators are automatically synthesized
These synthesized functions will make use of the constructors from Integer class

When is assigment operator constructor used and when copy constructor?
If a new object has to be created before the copying can occur, the copy constructor is used (note: this includes passing or returning objects by value).
If a new object does not have to be created before the copying can occur, the assignment operator is

*/

#include "integer.h"

class Number {
    Integer value{5};
public:
    Number(int value):value{value}{}
    // uncommenting this will cause no generation of the move constructors (and copies will be called of Integer class)
    //Number(const Number &n):value{n.value}{}
    //Number(Number &&n):value{n.value}{}
};

Number create_number(int num)
{
    Number n{num};
    return n;
}

int main(){
    Number n1{1};
    // here the copy constructor is used
    auto n2{n1};
    auto n3 = n2;
    
    // now the operator assigment copy is used!
    // because the memory is already allocated
    Number n4{3};
    n4 = n3;

    // create number returns an r value (return by value)
    auto n5{create_number(5)};
    n3 = create_number(3);

    /* output of code:
    Integer(): address: 0x7fffffffc8e8 (creating n1)
    Integer(const Integer &)address: 0x7fffffffc8f0 value: 1 (n1 is copied into new n2 address) 
    obj(right side of =) address: 0x7fffffffc8e8 value: 1 (n1)
    Integer(const Integer &)address: 0x7fffffffc8f8 value: 1 (n2 is copied into new n3 address)
    obj(right side of =) address: 0x7fffffffc8f0 value: 1 (n2)
    Integer(): address: 0x7fffffffc900 (create n4)
    obj(right side of =) address: 0x7fffffffc8f8 value: 1 (n3)
    operator=(const Integer &obj): address: 0x7fffffffc900 value: 1 (is copied (assigment) to address of n4)
    ------- create number 5
    Integer(): address: 0x7fffffffc8b0 (create number: create local n)
    obj(right side of =) address: 0x7fffffffc8b0 value: 5 (return local n)
    Integer(Integer &&)address: 0x7fffffffc910 value: 5  (function returns by value (r-value), so move of number is called)
    ~Integer(): address: 0x7fffffffc8b0 (destroy local n, exit create number)
    ------ create number done, 
    obj(right side of =) address: 0x7fffffffc910 value: 5
    Integer(Integer &&)address: 0x7fffffffc908 value: 5 (n5 steals the resource of local n, no new memory allocated for resource)
    ~Integer(): address: 0x7fffffffc910
    -------- create number 3
    Integer(): address: 0x7fffffffc8b0 (create local n, which call value constructor of Integer)
    obj(right side of =) address: 0x7fffffffc8b0 value: 3 
    Integer(Integer &&)address: 0x7fffffffc910 value: 3 (move constructor used to move local n into r value?)
    ~Integer(): address: 0x7fffffffc8b0 (local n destroyed)
    -------- create number done, now use move operator assigment to move resource to n3
    Integer::operator=(Integer &&obj): address: 0x7fffffffc8f8 value: 3 (r value moved into n3)
    ~Integer(): address: 0x7fffffffc910 (destroy r value?)
    ~Integer(): address: 0x7fffffffc908
    ~Integer(): address: 0x7fffffffc900
    ~Integer(): address: 0x7fffffffc8f8
    ~Integer(): address: 0x7fffffffc8f0
    ~Integer(): address: 0x7fffffffc8e8

    */
}