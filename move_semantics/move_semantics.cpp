/* Move Semantics
- Copy is implemented through copy constructor, shallow or deep which creates a COPY
- This is wasteful in case the copy is created from a temporary (temporary requires mem and new mem has to be allocated for the copy and then the value has to be copied over)
- Instead the state can be MOVED from the source object
- Implemented through move semantics
- Should be used when an expression returns a temporary and has to be copied in some object, use MOVE, this can be done by r-value references, so you dont use the default copy constructor!
   This kind of constructor is called a move constructor

- https://stackoverflow.com/questions/20837691/why-isnt-the-copy-constructor-called-when-returning-local-variable
--> disabled optimization by the compiler
Copy elision, see onenote 
*/
#include "integer_move.h"

// Note: when the parameters are const, you can only access const functions!
IntegerMove add(const IntegerMove &i1, const IntegerMove &i2) {
   // create a temporary object8
   IntegerMove temp;
   temp.set_value(i1.get_value() + i2.get_value());

   // here we return the object by value
   return temp;
}

int main() {
   IntegerMove i1{4}, i2{6};
   // the state of the temp temporary is moved inside of the set_value rvalue, not copied
   i1.set_value(add(i1,i2).get_value());
   //IntegerMove i3(i1);
   //IntegerMove a, b;
   return 0;
}