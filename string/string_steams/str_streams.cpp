#include <iostream>
#include <sstream>

int main() {

    int a{5}, b{6};
    int sum = a + b;

    std::string my_sum;

    // cannot sum integers and strings 
    // my_sum = "Sum of " + a + " & " + b + " is: " + sum + std::endl;

    std::stringstream ss;   // both insertion and extraction operatorss (read and write)
    std::istringstream is;  // only insertion
    std::ostringstream os;  // only read

    // everything is converted to strings (all the primitive types)
    ss << "Sum of " << a << " & " << b << " is: " << sum << std::endl;
    my_sum = ss.str();

    std::cout << my_sum;

    ss.str("Yoyoyo");
    ss << " Add to the string stream";
    ss << " mooorrrreeee";
    my_sum = ss.str();
    // Interestingly enough, the string that the stream was initialized with is not printed6

    std::cout << my_sum << std::endl;

    std::string data = "12 89 21";
    int c;
    // reset string buffer
    ss.str(data);

    // try to read something from the string stream
    // ss returns fail bit after >> extraction operator, so this will print the last number twice!
    // while (!ss.fail())
    // {
    //     ss >> c;    // return a string stream object
    //     std::cout << c << std::endl;
    // }
    while (ss >> c) {
        std::cout << c << std::endl;
    }

    // there are conversion methods available in cpp
    int x = std::stoi("54");

    return 0;
}