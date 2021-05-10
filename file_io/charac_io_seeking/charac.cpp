#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <string>

using namespace std::experimental::filesystem;

/* filestreams have a pointer where the operations will be performed
for ostreams this is the put pointer,
for istreams this is the get pointer
*/

void write() {
    std::ofstream output{"test.txt"};
    if (!output) {
        std::cout << "Could not open the file for writing" << std::endl;   
    }
    std::string message{"C++ was created by Bjarne"};

    std::cout << "The current position of put pointer is: " << output.tellp() << std::endl;

    for( char ch: message ) {
        output.put(ch); // put function of ostream
    }

    output.seekp(5);
    output.put('#');
}

void read() {
    path i_path{"test.txt"};
    std::ifstream input{i_path};
    if (!input) {
        std::cout << "could not open file: " << i_path.c_str() << std::endl;
    }

    // seeking will start from the beginning
    input.seekg(5, std::ios::beg);
    std::cout << "The current position of get pointer is: " << input.tellg() << std::endl;
    input.seekg(1, std::ios::cur);
    std::cout << "The current position of get pointer is: " << input.tellg() << std::endl;
    // end requires a negative number
    input.seekg(-10, std::ios::end);
    std::cout << "The current position of get pointer is: " << input.tellg() << std::endl;

    char ch{};
    while(input.get(ch)) {
        std::cout << ch;
    }
    std::cout << std::endl;

    // You have to clear the stream because the eof bit is now set
    input.clear();
    input.seekg(0, std::ios::beg);
    std::cout << "The current position of get pointer is: " << input.tellg() << std::endl;

    while(input.get(ch)) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

void fstream_func() {
    // Constructor will not create the file for you!
    std::fstream iostream{"test2.txt"};
    if (iostream.fail()) {
        std::cout << "File does not exist, creating one" << std::endl;
        // create the file yourself
        std::ofstream out{"test2.txt"};
        out.close();
        iostream.open("test2.txt");
    }

    iostream << "Hello world!" << std::endl;

    // both the get pointer and the put pointer at the end after this write!
    // seek the get ptr to the beginning!
    iostream.seekg(0);
    std::string line;
    std::getline(iostream, line);
    std::cout << line << std::endl;
}

int main() {
    write();
    read();
    fstream_func();
    return 0;
}