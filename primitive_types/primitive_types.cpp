#include <iostream>
#include <climits>
#include <cfloat>
#include <typeinfo>
using namespace std;

// special, used to indicate that nothing is passed or returned in functions
//void
// SCALAR TYPES
// integral types
bool var_bool = true;
char var_char;
wchar_t var_wchar;  // used only in special cases; for pointers and functions
char16_t var_char16;
char32_t var_char32;
short var_short;
int var_int;
long var_long = 3147483647;

// floating types
float var_float = 0.18;
double var_double = 18;

// modifiers
// signed, unsigned, short, long
signed int var_signed_int;
unsigned int var_unsigned_int;
short int var_short_int;
long int var_long_int;

// VECTOR TYPES
int array[5] = {1, 2, 3, 4, 5};

int main() {

    cout << "On this system with this compiler the datatypes have the following sizes:" << endl << endl;

    cout << "Integral types:" << endl;
    cout << "Size of bool : " << sizeof(var_bool) << " bytes" << endl;
    cout << "Size of char : " << sizeof(var_char) << " bytes" << endl;
    cout << "Size of wchar_t : " << sizeof(var_wchar) << " bytes" << endl;
    cout << "Size of char16_t : " << sizeof(var_char16) << " bytes" << endl;
    cout << "Size of char32_t : " << sizeof(var_char32) << " bytes" << endl;
    cout << "Size of short : " << sizeof(var_short) << " bytes" << endl;
    cout << "Size of int : " << sizeof(var_int) << " bytes" << endl;
    cout << "Size of long : " << sizeof(var_long) << " bytes" << endl << endl;

    cout << "Floating point types:" << endl;
    cout << "Size of float : " << sizeof(var_float) << " bytes" << endl;
    cout << "Size of double : " << sizeof(var_double) << " bytes" << endl << endl;
   
    cout << "Modifiers (using sizeof on datatype directly instead of variables of specific datatype):" << endl;
    cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
    cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
    cout << "Size of signed int : " << sizeof(signed int) << " bytes" << endl;
    cout << "Size of unsigned int : " << sizeof(unsigned int) << " bytes" << endl;
    cout << "Size of long double : " << sizeof(long double) << " bytes" << endl << endl;

    cout << "The limits of the ranges for integral datatypes can be checked via the climits/limits.h header file" << endl;
    cout << "The range of char ranges from: " << CHAR_MIN << " to " << CHAR_MAX << endl;
    cout << "The range of short ranges from: " << SHRT_MIN << " to " << SHRT_MAX << endl;
    cout << "The range of int ranges from: " << INT_MIN << " to " << INT_MAX << endl;
    cout << "The range of unsigned int ranges from: " << 0 << " to " << UINT_MAX << endl << endl;

    cout << "For floats you can find it in cfloat/float.h header file" << endl;
    cout << "The range of float ranges from: " << FLT_MIN << " to " << FLT_MAX << endl;
    cout << "The range of double ranges from: " << DBL_MIN << " to " << DBL_MAX << endl << endl;

    cout << "Checking the initialized variables: " << endl;
    cout << "The variable var_bool contains: " << var_bool << " is of datatype: " << typeid(var_bool).name() << endl;
    cout << "The variable var_long contains: " << var_long << " is of datatype: " << typeid(var_long).name() << endl;
    cout << "The variable var_float contains: " << var_float << " is of datatype: " << typeid(var_float).name() << endl;


    cout << "Variable initialization" << endl;
    // Uniform initialization is now possible since C++14, using the {}
    // primitive types are not initialized, objects are
    int i1; // uninitialized, can contain anything
    int i2 = 0; // copy initialization, should be avoided (from the moment you use assignment operator, because you first create the right side and then copy it to the left side)
    int i3(5); // called direct initialization

    string s; // this is an object, so its initialized to empty string

    char a1[8]; // uninitialized, can contain anything
    char a2[8] = {'\0'}; // initialized with null terminating character, copy initialization
    char a3[8] = {'a', 'b', 'c', 'd'}; // aggregate initialization

    cout << "i1: " << i1 << " i2: " << i2 << " i3: " <<  i3 << " s: " << s << endl;
    cout << "a1: " << a1 << " a2: " << a2 << " a3: " <<  a3 << endl;

    // uniform initialization
    int b1{}; // value initialization
    int b2(); // this is declaring a function b, called most vexing parse IT DOES NOT INITIALIZE only when you supply something between parenthesis
    int b3{5}; // Direction intialization
    char b4{};
    char b5[15]{"DirectInit"};  // Object is created on the heap, so its initialized

    cout << "b1: " << b1 << " b2 " << b2 << " b3 " << b3 << " b4 " << b4 << " b5 " << b5 << endl;

    int *p1 = new int; // uninitialized variable created on the heap
    int *p2 = new int{}; // initiliazed
    char *p3 = new char[8]{};
    //char *p3 = new char[8]{"Hi"}; // does not seem to work
    int *p4 = new int[8]{5,4,3,2,1}; // you should be able to now create a variable on the heap and immediately give it a value

    cout << "p1: " << *p1 << " p2: " << *p2 << " p3: " << *p3 << " p4: " << *p4 << " p4++: " << *(p4+1) <<endl;

    // for primitive types you can choose between assigment operator or uniform initialization, but for user defined types, you need to use uniform initialization
    /*
    1. Value initialization => T obj{};
    2. Direction initialization => T obj{b}
    3. Copy initiliazation => T obj = v; 

    Advantages of uniform intialization
    1. Forces initialization
    2. Direction initiliazation for array types
    3. It prevents narrowing conversion
    4. Uniform syntax
    */

    // example 
    // It prevents narrowing conversion (run build task to see warning)
    float f{};
    int i{f};

    return 0;
}

