#include <iostream>

enum class Case{SENSITIVE, INSENSITIVE};
std::string to_lower(const std::string &string);
 
size_t Find(
    const std::string &source,         //Source string to be searched
    const std::string &search_string,  //The string to search for
    Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
    size_t offset = 0 ) {                //Start the search from this offset
     //Implementation
 
     /*
     return position of the first character 
     of the substring, else std::string::npos
     */
    size_t found_index;
    if (searchCase == Case::SENSITIVE)
    {
        found_index = source.find(search_string);
    }
    else
    {
        auto lower_case = to_lower(source);
        auto search = to_lower(search_string);
        found_index = lower_case.find(search);
    }
    return found_index;
}

std::string to_lower(const std::string &string)
{
    std::string new_string;
    for (char c: string)
    {
        new_string += tolower(c);
    }

    return new_string;
}

int main() {
    std::string complex_string = "YOyoYoyoy what are you doing man, stop typing cause the buffer gets too large, what are you trying to find in this string?";

    size_t found_index_sens = Find(complex_string, "too large", Case::SENSITIVE);
    std::cout << "Sensitive found index: " << found_index_sens << std::endl;

    found_index_sens = Find(complex_string, "Too large", Case::SENSITIVE);
    std::cout << "Sensitive found index: " << found_index_sens << std::endl;


    size_t found_index = Find(complex_string, "Too large");
    std::cout << "Insensitive found index: " << found_index << std::endl;

    found_index = Find(complex_string, "too large", Case::INSENSITIVE);
    std::cout << "Insensitive found index: " << found_index << std::endl;
}