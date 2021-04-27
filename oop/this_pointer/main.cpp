
/* this pointer
- a hidden pointer bassed to member functions
- points to the object that invoked the member function
- provided as a keyword that is only meaningful in member functions
- this pointer is optional! as you have seen in the oop classes examples of car
    YOU WOULD ONLY USE THIS WHEN THE PARAMETER OF THE MEMBER FUNCTION HAS THE SAME NAME AS THE FIELD (see add_passengers function)
    OR WHEN YOU NEED TO PASS THE OBJECT ITSELF TO A MEMBER FUNCTION
*/

#include "car.h"

int main()
{
    Car car(5);    // constructor called
    car.dashboard();
    car.fill_fuel(6);
    car.accelerate();
    car.accelerate();
    car.accelerate();
    car.accelerate();
    car.accelerate();
    car.dashboard();

    Car car2;
    car2.dashboard();
}
