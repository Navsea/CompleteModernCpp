#include <iostream>
using namespace std;

std::string to_upper(const string &string);
std::string to_lower(const string &string);

int main() {
    string convert = "Hello!";
    auto upper = to_upper(convert);
    auto lower = to_lower(convert);
    cout << "to_upper: " << upper << " to_lower: " << lower << endl;
    return 0;
}

std::string to_upper(const string &string)
{
    std::string new_string;
    for (char c: string)
    {
        new_string += toupper(c);
    }

    return new_string;
}

std::string to_lower(const string &string)
{
    std::string new_string;
    for (char c: string)
    {
        new_string += tolower(c);
    }

    return new_string;
}