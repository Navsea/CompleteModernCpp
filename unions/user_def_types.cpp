#include <iostream>
using namespace std;
#include "user_def_types.h"


A::A() { cout << __PRETTY_FUNCTION__ << endl; }
A::~A() { cout << __PRETTY_FUNCTION__ << endl; }
A::A(const A &other) { cout << __PRETTY_FUNCTION__ << endl; }
A::A(const A &&other) noexcept { cout << __PRETTY_FUNCTION__ << endl; }
A& A::operator=(const A &other) { 
    cout << __PRETTY_FUNCTION__ << endl;
    if (&other==this) {
        return *this;
    } 
    return *this;    
}
A& A::operator=(const A &&other) noexcept { 
    cout << __PRETTY_FUNCTION__ << endl;
    if (&other==this) {
        return *this;
    } 
    return *this;    
}



B::B() { cout << __PRETTY_FUNCTION__ << endl; }
B::~B() { cout << __PRETTY_FUNCTION__ << endl; }
B::B(const B &other) { cout << __PRETTY_FUNCTION__ << endl; }
B::B(const B &&other) noexcept { cout << __PRETTY_FUNCTION__ << endl; }
B& B::operator=(const B &other) { 
    cout << __PRETTY_FUNCTION__ << endl;
    if (&other==this) {
        return *this;
    } 
    return *this;    
}
B& B::operator=(const B &&other) noexcept { 
    cout << __PRETTY_FUNCTION__ << endl;
    if (&other==this) {
        return *this;
    } 
    return *this;    
}