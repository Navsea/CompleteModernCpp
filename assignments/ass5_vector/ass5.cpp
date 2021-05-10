#include <iostream>
using namespace std;
#include <vector>

enum class Case{SENSITIVE, INSENSITIVE};
std::string to_lower(const std::string &string);
size_t Find( const std::string &source, const std::string &search_string, Case searchCase, size_t offset);

std::vector<int>
FindAll(
 const std::string &target,         //Target string to be searched
 std::string search_string,         //The string to search for
 Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
 size_t offset = 0) {                //Start the search from this offset
    std::vector<int> indices;
     while(offset < target.length()) {
        size_t curr_index = Find(target, search_string, searchCase, offset);
        if (curr_index == std::string::npos)
            break;
        indices.push_back(static_cast<int>(curr_index));
        offset = static_cast<size_t>(curr_index+1);
     }
    return indices;
}

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
        found_index = source.find(search_string, offset);
    }
    else
    {
        auto lower_case = to_lower(source);
        auto search = to_lower(search_string);
        found_index = lower_case.find(search, offset);
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

    std::vector<int> indices;
    indices = FindAll(complex_string, "what", Case::SENSITIVE, 0);
    cout << "Found word at indices: ";
    for (int i: indices) {
        cout << i << " ";
    } 
    cout << endl;

    return 0;
}