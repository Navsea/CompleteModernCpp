#include <iostream>
using namespace std;

int main()
{
    int a = 8, b = 3;
    float f = a; // compiler does cast implicitly
    float f2 = a / b; // result is 2
    cout << "f2 with integer division: " << f2 << endl;
    f2 = (float)a/b; //
    // this is not advised because there are no checks in the casting
    cout << "f2 with c style cast: " << f2 << endl;

    // use static_cast!
    float f3 = static_cast<float>(a)/b;
    cout << "f3 with cpp style cast: " << f3 << endl;

    // example of why static cast is better
    //char *p = &a; does not work
    // this is allowed! even though its a different type
    char *p = (char *)&a;
    // static cast does not allow this
    //p = static_cast<char *>(&a);

    // you could make it work in cpp style with reinterpret_cast
    p = reinterpret_cast<char *>(&a);

    // The difference is that c-style casting will discard the type qualifiers, cpp style does not
    const int i = 5;
    // does not work, pointer to int is not pointer to cst int
    //int *p2 = &i;
    // but you can do this --> qualifier is discarted
    int *p2 = (int *)&i;

    // qualifiers are kept
    //p2 = reinterpret_cast<int *>(&i);

    // you can work around this
    p2 = const_cast<int *>(&i);

}