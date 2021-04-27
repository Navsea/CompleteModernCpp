/* std::move()
This function can make an r value from a l value
so you can use move constructors with l values

Useful to change ownership: you no longer need the object, and pass it on to a function
this function once the parameter goes out of scope, will be destroyed.

Useful if the object contains non-copyable resources, such as a file stream for example
then you could remove the copy constructors but only keep the moves.

using std::move() on a primitive will still copy the value, not move it
*/

#include <iostream>
using namespace std;
#include "integer.h"

void print(Integer i)
{
    cout << "Printing: " << i.get_value() << endl;
}

int main()
{
    Integer i1{1};
    //auto i2{i1};        // copy constructor is used, but is now deleted

    // explicitly cast i1 to r value
    auto i3{static_cast<Integer&&>(i1)};

    // this would not work, as i1 doesnt have that memory anymore! its moved to i3
    //auto i4{std::move(i1)}; // move constructor  is used
    auto i4{std::move(i3)};

    // A common use case if when you no longer need an object, but a function still needs it
    // as the ownership has moved to the function parameter, the object will be released when the function exits.
    print(std::move(i4));

    // print(i4); would try to dereference released memory
    // but i4 object still exists, you could reinitilize it
    // but you cannot just call set_value now, because it just writes to already allocated memory!
    i4.set_value(3);

    return 0;
}