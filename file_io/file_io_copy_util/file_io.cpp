#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

int main() {
    using namespace std::experimental::filesystem;

    path source(current_path());
    std::cout << source.c_str() << std::endl;

    // overloaded compound operator /=
    // every x= operator is a compound operator like *=
    // optional to add the first /
    source /= "file_io/file_io_copy_util/file_io.cpp";
    std::cout << source.c_str() << std::endl;

    path dest(current_path());
    dest /= "file_io/file_io_copy_util/copy.cpp";

    std::ifstream input{source};
    if (!input) {
        std::cout << "Source file not found!: " << source.c_str() << std::endl;
        return -1;
    }
    std::ofstream output{dest};
    if (!output) {
        std::cout << "Output file not opened" << std::endl;
        return -1;
    }

    std::string line;
    while (!std::getline(input, line).eof()) {
        output << line << std::endl;
    }

    // close files explicitly
    // would be done automatically with destructors when reaching end
    input.close();
    output.close();

    return 0;
}