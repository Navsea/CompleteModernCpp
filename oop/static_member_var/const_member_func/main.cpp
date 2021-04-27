
/* static member variables
- qualified with the 'static' keyword
- not part of the object, but part of the class, so only ONE copy exists, so its shared across all the objects
- cannot be initialized in the class

What if you dont have an object, how to access static variable?
- You have to create a static function
- belons to the class, not the object, so it doesnt have a this pointer parameter
- only use static in the declaration, not the implementation
*/

#include "car.h"

int main()
{
    // a constant object can only call constant function
    const Car car(5);    // constructor called
    car.dashboard();

    Car *car2 = new Car;
    (*car2).dashboard();

    Car car3(10);
    car3.dashboard();

    // call static function
    Car::show_count();
}
