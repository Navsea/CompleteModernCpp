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
