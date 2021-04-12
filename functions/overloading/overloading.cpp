#include <iostream>
using namespace std;

int Add(int a, int b)
{
    return a + b;
}

double AddDoubles(double a, double b)
{
    return a + b;
}

int Add2(int a, int b)
{
    return a + b;
}
double Add2(double a, double b)
{
    return a + b;
}

void Print(int *x)
{
    cout << "pointer to int " << *x << endl;
}
void Print(const int *x)
{
    cout << "pointer to const int " << *x << endl;
}

void Print(int x)
{
    cout << "int " << x << endl;
}

/* this does not have a different signature from above function
void Print(const int x)
{
    cout << "const int " << x << endl;
}
*/

extern "C" void print(const char *message);

void print(const char *message)
{
    cout << *message << endl;
}

int main()
{
    int result_int = Add(6,4);
    int result_int_double = Add(6.1, 3.6);
    cout << "result adding ints: " << result_int << " result adding doubles defined as int in function: " << result_int_double << endl;

    // You can see that truncation occurred (int only has 4 bytes of storage and double 8)
    double result_double = AddDoubles(6.1,3.6);
    cout << "result adding doubles: " << result_double <<  endl;

    // In cpp you can use function overloading, so the same name can be used for the same behaviour
    double result_double2 = Add2(3.1, 3.2);
    int result_int2 = Add2(5,4);
    cout << "result adding ints: " << result_int2 << " result adding doubles: " << result_double2 << endl;

    // The function signature needs to be different so the compiler knows based on the parameters passed, which function to choose (type of parameters or nr of parameters)
    // using a different type qualifier only counts as a different signature for pointers and references!!!
    int i = 1;
    int *p1 = &i;
    const int i2 = 5;

    Print(p1);
    Print(&i2);
    Print(i);
    Print(i2); // using same function as above print (const int is not different from int)

    /*
    Function overloading requires:
    1. Arguments should differ in type and/or number
    2. For pointers and references type qualifiers count as type difference
    3. Return type is ignored
    4. When defining methods(class functions), type qualifiers participate in overload

    This allows for different implementations of the same behaviour
    The correct function is chosen based on the passed arguments
    This is resolved at compile time (static polymorphism)
    Function overloading is handy for the programmers of function callers

    Name mangling generates unique names for each of the functions,
    This way the linker can link to the correct function code
    The name mangling varies from compiler to compiler and is an unkown algorithm, this means that Cpp overloaded functions are not always callable from C code or other languages

    To resolve this, you need to use the compiler directive extern "C" typically where the function is declared, and implemented (if seperate files, if you include the header with declarations which already have extern C, then its not needed). You can put it only where implemented when there is no declaration for the function
    1. Compiler directive applkiked on global functions and variables
    2. Supresses name mangling of the type on which it is appied
    3. Can be applied to only one function in a set of overloaded functions
    4. Allows C++ functions to be called from C or other languages
    */
   print("hello, is it you im looking for");

}