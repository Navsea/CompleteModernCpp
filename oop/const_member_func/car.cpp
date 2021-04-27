/* 

see main.cpp
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
    this->fuel = amount;
    cout << "Car(float amout)" << endl;
}

Car::~Car()
{
    cout << "~Car()" << endl;
}

void Car::fill_fuel(float amount)
{
    this->fuel = amount;
}
void Car::accelerate()
{
    this->speed++;
    this->fuel -= 1;
}
void Car::brake()
{
    this->speed = 0;
}
void Car::add_passengers(int passenger)
{
    this->passengers=passenger; // because of this he knows you meant the member variable (on the left side)
    foo(*this);
}
void Car::foo(const Car &car)
{
    
}
void Car::dashboard() const
{
    // this->fuel++ will not work
    cout << "Fuel: " << this->fuel << endl;
    cout << "Speed: " << this->speed << endl;
    cout << "Passengers: " << this->passengers << endl;
    cout << "p_char: " << this->p_char << endl;
}

