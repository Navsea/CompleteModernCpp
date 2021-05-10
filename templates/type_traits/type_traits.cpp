#include <iostream>
using namespace std;
#include <type_traits>

/* Type traits
- is mostly used by templates
*/

template<typename T>
T divide(T a, T b) {
    // the is_floating_point<T> is evaluated at compile time, but the if at runtime
    // its better to use static assert for this to fail the compilation
    if (std::is_floating_point<T>::value)
    {
        return a / b;
    }
    else{
        throw std::invalid_argument("Wrong type");
    }
}

template<typename T>
void check(T &&value) {
    // check if its an l or r-value reference
    cout << "is reference?: " << std::boolalpha << std::is_reference<T>::value << endl;    

    // is reference returns a boolean
    // but remove_reference returns a type
    // you have to use typename for return of remove_reference to indicate that its a dependent type on T
    cout << "After removing reference: " << std::boolalpha << std::is_reference<typename std::remove_reference<T>::type>::value << endl;
}

int main() {
    // boolapha converts 1/0 to text true or flase
    cout << std::boolalpha << "Is Integer? " << std::is_integral<uint>::value << endl;

    //int result = divide(5,4);
    float result = divide(5.0, 4.1);
    cout << "Result is: " << result << endl;

    // r-value
    check(5);
    int i{};
    // l value
    check(i);
    check(new int{3});
}   
