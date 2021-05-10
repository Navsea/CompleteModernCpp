#include <iostream>
using namespace std;

int main() {
    // this string is f-up
    string my_string = "C:\temp\newfile";
    cout << my_string << endl;

    // You have to escape the special characters 
    my_string = "C:\\temp\\newfile";
    cout << my_string << endl;

    // You can also use string literals!
    my_string = R"(C:\temp\newfile)";
    cout << my_string << endl;

    // in this case the compiler thinks the first )" is the end of the string
    // you have to create your own delimiter
    //string another_string = R"(blablabla "(in C++ 11)")";
    string another_string = R"MSG(blablabla "(in C++ 11)")MSG";
    cout << another_string << endl;
    return 0;
}