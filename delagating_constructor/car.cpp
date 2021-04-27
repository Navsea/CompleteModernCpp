/* 

see main.cpp
*/

#include "car.h"
#include <iostream>
using namespace std;

int Car::total_count = 0; // static members are automatically initialized to zero

Car::Car():Car(0)
{
    cout << "Called Car()" << endl;
}

Car::Car(float amount):Car(amount, 0)
{
    cout << "Called Car(amount)" << endl;
}

Car::Car(float amount, int passengers)
{
    cout << "Called Car(amount, passengers)" << endl;
    total_count++;
    fuel = amount;
    speed = 0;
    this->passengers = passengers;
}

Car::~Car()
{
    total_count--;
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
    cout << "Total cars: " << this->total_count << endl;
    cout << "p_char: " << this->p_char << endl;
}
void Car::show_count()
{
    cout << "Total cars: " << total_count << endl;
}
