#include <iostream>
using namespace std;

int square(int x)
{
    return x * x;
}

#define SQUARE2(x) x*x

inline int square3(int x)
{
    return x * x;
}

int main()
{
    int val{5};
    int result =  square(val);
    cout << "result using regular function: " << result << endl;

    /*
    Calling this function, which is defined at another memory address, causes overhead
    1. The pointer to where we were in the program (program pointer), needs to be stored on the stack, so we know where to return to once the function is executed
    2. Stack memory for needed for the arguments of the function
    Instead, you could defined a macro
    */
    result = SQUARE2(val);
    cout << "result using macro: " << result << endl;

    /*
    The problem with this, is that the macro is literally pasted inside of the code (done by preprocessor)
    Here, this expression is expanded as val+1^2 * val+1^2 = 11 (* has priority so, it does 1^2 * 1^2, then adds 5 two times)
    */
   result = SQUARE2(val+1);
   cout << "result using macro w calculation as argument (expected 36): " << result << endl;

   /*
   Instead you should use the inline keyword
   This will cause the compiler to expand the function call with the body of the function 
   Argument is first evaluated before passing as argument to function
   YOU HAVE TO BE CAREFUL IN VISUAL STUDIO CODE THOUGH: WHEN COMPILING USING DEBUG CONFIGURATION, OPTIMIZATIONS ARE NOT DONE BY DEFAULT
   SO EVEN WHEN USING INLINE, IT WOULD STILL JUMP TO OTHER MEM LOCATION. THIS IS AN OPTION THAT YOU CAN CHANGE THOUGH
   */
    result = square3(val+1);
    cout << "result using inline function: " << result << endl;

    /*
    1. an inline function is marked with keyword inline where it is defined (no declaration needed as definition is in the same file that is included in other files)
    2. these should be defined inside a header file, this ensures that the whole project has the same definition:
        - See one definition rule, so the easiest to ensure only one definition of the function exists, is to put it together in the header file
        - If you want to put the definition of a function in a single source file, you should not declare it inline, the compiler could still choose to inline it.
        - defining it in source file, and then including it in other source file, will give you linker error (linker cannot find definition)
    3. the overhead of a function call is avoided (stack for argument memory and program pointer for return address)
    4. inline is only a request to the compiler, compiler may ignore it! (large functions, recursive, functions invoked through pointers, ...ect) depends on the compiler
    5. compiler may automatically inline a function
    6. excessive inlining will increase the program binary size.
    */

}


