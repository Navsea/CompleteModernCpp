/* constant expression
- used to represent an expression that is constant
- these expressions are possibly evaluated at compile time, so may increase performance of code
- can be applied to variable declarations or functions
- IN CPP 11: should only contain one line of code, the return statement! this is allowed from Cpp14 onwards
- All constant expressions are implicitly inline, so just like inline, you need to define them in the header file!

const vs constexpr
all constexpr are cst but not all cst are constexpr (const can be defined at runtime)
const is used to indicate that the value will not change!
constexpr is used for expressions that need to be executed at compile time
*/
#include <iostream>
using namespace std;

int get_number() { return 42; }

// should only return literal types! (void, scalar, types(int, float, char), references, ect...)
constexpr int get_number_cst() { return 42; }

// this also works!!!
// but arguments have to be a literal and a compile time cst if you want it to return as cst expression
constexpr int add(int x, int y) { return x + y; }

constexpr int max(int x, int y) { return x > y? x:y; }
// 
constexpr int max_multiline(int x, int y) {
    if (x > y)
        return x;
    return y;
}

int main() {
    constexpr int i = 10;
    int arr[i];

    // Difference is that not all constants are evaluated at compile time
    // Some constants can be defined at runtime!
    const int j = 5;
    int arry1[j];

    // this constant is not defined at compile time!
    // but it still seems to work, this is not what the instructor implied...
    const int k = get_number();
    int arr2[k];

    arr2[2] = 5;
    cout << arr2[2] << endl;

    // get_number is not a constant expression!
    //constexpr int l = get_number();
    constexpr int l = get_number_cst();

    // behaves as a normal function, so only executed at run time!
    // reason being that the target variable is not a constexpr
    int m = get_number_cst();

    // executed at compile time
    constexpr int n = add(5,4);
    // not executed at compile time
    int o = add(5,5);

    int p = add(arr2[2], 6);
    cout << p << endl;
    // does not work, arrr2[2] is not a constant expression
    //constexpr int q = add(arr2[2], 6);

    constexpr int q = max(6,2);
    constexpr int r = max_multiline(6,2);
    cout << "max of 6,2 is: " << q << endl;
    cout << "max of 6,2 is: " << r << endl;

    return 0;
}