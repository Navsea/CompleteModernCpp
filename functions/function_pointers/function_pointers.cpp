#include <iostream>
using namespace std;

/* Function pointers
1. contains the address to a function
2. the type is the same as the signature of the function (return and arguments)
3. can be used to invoke a function, even when name is not known
4. used by algorithms and classes for customization (fe, multiple algo's that do the same thing (multiple sorts fe))
*/
void print(int count, char ch)
{
    for (int i = 0; i < count; i++)
    {
        cout << ch;
    }
    cout << endl;
}

void end_message()
{
    cout << "end of program" << endl;
}

int main()
{
    print(5, '#');

    // this is how you declare a function pointer
    // return type, and parameters corresponding to the function it needs to point to, *pfn is the name () is important
    // note that for functions & is optional, using the regular function name also returns a pointer to the function
    void (*pfn) (int, char) {&print};
    // can be invoked like this:
    (*pfn)(8, '@');
    // or like a regular function
    pfn(8, '+');

    // atexit() can execute a function just before the program exits, so position of the function call does not matter
    atexit(end_message);
    return 0;
}