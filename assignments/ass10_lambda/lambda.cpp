#include <iostream>

// apparently std namespace has a max function/var
//using namespace std;

template<typename T>
T max(T a, T b) {
    return a > b? a:b;
}

template<typename T>
struct MaxFuncObj {
    T operator() (T a, T b) {
        return a > b? a:b;
    }
};

template<typename T>
auto max_lambda = [](T a, T b) {
    return a > b? a:b;
};

int main() {
    // using function template
    std::cout << "a = 5, b = 10, max using function template is: " << max(5,10) << std::endl;

    // using function object
    MaxFuncObj<int> max_obj;
    std::cout << "a = 5, b = 10, max using function object is: " << max_obj(5,10) << std::endl;

    // using lamda expression
    std::cout << "a = 5, b = 10, max using lambda expression is: " << max_lambda<int>(5,10) << std::endl;
}