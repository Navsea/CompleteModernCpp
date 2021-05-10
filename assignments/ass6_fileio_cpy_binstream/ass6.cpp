#include <fstream>
#include <iostream>
#include <experimental/filesystem>
#include <string>
using namespace std::experimental::filesystem;

int main() {

    // open text file stream
    path txt_source{current_path()};
    txt_source /= "assignments/ass6_fileio_cpy_binstream/ass6.cpp";
    std::cout << "txt source: " << txt_source << std::endl;
    std::ifstream input{txt_source};
    
    // create binary file stream
    path bin_source = txt_source.parent_path();
    bin_source /= "ass6.bin";
    std::cout << "bin_source: " << bin_source << std::endl;
    std::fstream output{bin_source};
    // if file does not exist
    if (output.fail()) {
        // create the file
        std::ofstream help{bin_source, std::ios::binary | std::ios::out};
        help.close();
        output.open(bin_source);
    }

    // read a line from the input file and write it to the binary file
    std::string line;
    int nr_of_characters{0};
    while (std::getline(input, line)) {
        output.write((const char *)&line, line.size());
        nr_of_characters += sizeof(line);
    }

    // read from the binary file
    char c;
    for(int i = 0; i<nr_of_characters; i++)
    {
        output.read((char *)&c, sizeof(c));
        std::cout << c;
    }
    std::cout << std::endl;
}