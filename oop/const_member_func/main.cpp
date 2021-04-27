
/* this pointer
- a hidden pointer bassed to member functions
- points to the object that invoked the member function
- provided as a keyword that is only meaningful in member functions
- this pointer is optional! as you have seen in the oop classes examples of car
    YOU WOULD ONLY USE THIS WHEN THE PARAMETER OF THE MEMBER FUNCTION HAS THE SAME NAME AS THE FIELD (see add_passengers function)
    OR WHEN YOU NEED TO PASS THE OBJECT ITSELF TO A MEMBER FUNCTION
- all functions that do not change the state of the object should be qualified with const
- if you define a const object, the const qualifier is applied to this
*/

#include "car.h"

int main()
{
    // a constant object can only call constant function
    const Car car(5);    // constructor called
    car.dashboard();
}
