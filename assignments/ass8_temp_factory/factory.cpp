#include <iostream>

// pitfalls
// do not return the object by value, but by ref
// you can just pass the parameter list to the initializer list
// use the r value reference of the params
template<typename T, typename ...Params> 
T create_object(Params &&... args) {
    T *new_object = new T{std::forward<Params>(args)...};
    return new_object;
}

int main()
{
    return 0;
}