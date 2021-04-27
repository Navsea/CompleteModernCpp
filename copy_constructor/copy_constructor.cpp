/* Copy constructor
- Copies the state of object to another object
- Automatically created by the compiler is not defined by user
- Default will just copy values, this might be undesired in the case of pointers (pointing to the same object as where you copied from)
-  The copy constuctor is called: 
    - when you call the constructor with an object of the same type
    - when you call a function with the object as parameter passed by value
    - when a function returns an object by value 
    - when an object is assigned to another object
- Rule of 3:
    - when implementing one of these three function, implement all of them!:
    this is because your trying to allocate some resource
        - destructor (indicates that your trying to free allocated mem)
        - copy constructor (you want to make deep instead of shallow copy, otherwise you would use default constructor)
        - copy assignement operator
    if you dont, that might cause memory leak or shallow copy
*/
#include <iostream>
using namespace std;

#include "integer.h"
#include "integer_copy.h"

int main()
{
    Integer i(5);
    cout << "original integer: " << i.get_value() << endl;
    Integer i2(i); // this directly invokes the copy constructor (by compiler if not created)
    cout << "copied integer: " << i2.get_value() << endl;
    i2.set_value(3);
    // here you will see that changing i2 changes i as well as the copied object is pionting to the same integer
    // also when destroying the second object, we will try to free the same memory!
    cout << "original integer: " << i.get_value() << " copied integer: " << i2.get_value() << endl;

    // p_int2 is a shallow copy, only pointer itself is copied
    int *p_int = new int(5);
    int *p_int2 = p_int;

    // probably you want a deep copy
    // here we explicitly allocate new memory!
    int *p_int3 = new int(*p_int);

    // This does not work because the constructor of a class returns a reference to an object
    // So youre trying to assign a reference to a regular variable
    // IntegerCopy i3 = IntegerCopy(5);
    IntegerCopy i3(5);
    IntegerCopy i4(i3);
    i4.set_value(9);
    cout << "original integer: " << i3.get_value() << " copied integer: " << i4.get_value() << endl;

}