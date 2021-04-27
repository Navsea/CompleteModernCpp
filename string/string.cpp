#include <iostream>
using namespace std;
#include <cstring>
#include <string>

// We are returning a pointer to a local variable!
// The local variable is destroyed after exiting the function
const char * combine(const char *first, const char *last)
{
    char full_name[20];
    strcpy(full_name, first);
    strcat(full_name, last);
    return full_name;
}

const char * combine_dyn_alloc(const char *first, const char *last)
{
    // you have to allocate one byte extra! because of the null terminating character that is automatically appended for strings
    char *full_name = new char[strlen(first) + strlen(last) + 1];
    strcpy(full_name, first);
    strcat(full_name, last);
    return full_name;
}

// return by value, so copy is created
string combine_string(const string &first, const string &last)
{
    // you have to allocate one byte extra! because of the null terminating character that is automatically appended for strings
    string full_name = first + last;
    return full_name;
}

int main() {
    // char first[10];
    // char last[10];

    // // getline prevents that cin would stop reading when space is entered
    // cin.getline(first, 10);
    // cin.getline(last, 10);

    // // const char * full_name = combine(first, last);
    // // // Can contain garbage as the local has been destroyed
    // // cout << "full_name: " << full_name << endl;

    // const char *full_name2 = combine_dyn_alloc(first, last);
    // cout << "full_name: " << full_name2 << endl;
    // delete[] full_name2;    // delete for arrays!!!

    // // you can easily make mistakes with cstring (forget memory alloc for null terminating char, returning ptr to local var)
    // // cpp has a string class!

    // // intitialize and assign
    string s = "Hello!";
    // s = "Again hello!";

    // // access
    // s[6] = 'H';
    // char c = s[0];
    // cout << s << endl;
    // cin >> s;
    // std::getline(cin, s);

    // size
    int lenght_of_string = s.length();

    // insert & concatenate
    string s1 = "Hello";
    string s2 = "Again!";
    string s3 = s1 + ' ' + s2;
    cout << s3 << endl;
    s3 += s2;
    cout << s3 << endl;

    s1.insert(3, "world");
    cout << s1 << endl;

    // comparison
    if (s1 != s2)
    {

    }

    // removal
    //s1.erase();
    s1.erase(0, 5); // erase first 5 characters (end not included)
    cout << s1 << endl;
    s1.clear();

    // search
    s1 = "Hello world!";
    auto pos = s1.find("world", 0);  // second argument is the offset, where search starts from
    if (pos != std::string::npos)   // npos is a constant that is returned when nothing is found
    {
        cout << "position: " << pos << endl;
    }

    string full_name = combine_string("Kenneth ", "De Leener");
    cout << full_name << endl;

    // If you are using functions of c, you can still use cpp string class by using the c_str() function
    printf("%s", full_name.c_str());


    // literals will be explained later but
    using namespace std::string_literals; // requires c++14 or above
    string name = "Kenneth"s;
}