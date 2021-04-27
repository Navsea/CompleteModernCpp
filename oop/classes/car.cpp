/* Class
- Blueprint/template/recipe
- Represents an abstraction
- Every object is instantiated from a class, so an object is an instance
- You can have multiple instances of a class 
- Instances can operate independently for each other 

class <name>
{
    // members are private by default
    <modifiers>: 
        <member variables>

};
*/

#include "car.h"
#include <iostream>
using namespace std;

Car::Car()
{
    cout << "Car()" << endl;
}

Car::Car(float amount)
{
    fuel = amount;
    cout << "Car(float amout)" << endl;
}

Car::~Car()
{
    cout << "~Car()" << endl;
}

void Car::fill_fuel(float amount)
{
    fuel = amount;
}
void Car::accelerate()
{
    speed++;
    fuel -= 1;
}
void Car::brake()
{
    speed = 0;
}
void Car::add_passengers(int count)
{
    passengers=count;
}
void Car::dashboard()
{
    cout << "Fuel: " << fuel << endl;
    cout << "Speed: " << speed << endl;
    cout << "Passengers: " << passengers << endl;
    cout << "p_char: " << p_char << endl;
}

