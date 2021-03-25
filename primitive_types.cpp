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


    return 0;
}
