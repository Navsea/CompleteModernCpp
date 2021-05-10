/*
C++ provides support for file io through following classes:
ofstream: write to output stream
ifstream: read from input stream
fstream: read/write
Use <fstream> header
used for both text and binary io
additionally you can decide how the file is opened and operated
is_open() returns a bool indicating if its open
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write() {
    // default mode is already out
    std::ofstream out{"data.txt"};
    out << "Hello world!" << endl;
    out << 10 << endl;
    out.close();
}

void read() {
    // instead of using the constructor you could also use the open function of the class
    std::ifstream in/*{"data.txt"}*/;
    in.open("data.txt");
    if (!in.is_open()) {
        cout << "Could not open the file" << endl;
    }
    // alternate check
    if (in.fail()) {
        cout << "Could not open the file" << endl;
        return;
    }
    string message;
    // the >> would stop after the first encountered space
    // in >> message
    std::getline(in, message);
    int value{};
    in >> value;
    if (in.good()) {
        cout << "All operations have succesfully completed!" << endl;
    }
    else {
        cout << "Some or all IO operations have failed!" << endl;
    }
    
    // this read will fail as the stream is empty
    in >> value;
    if (in.fail()) {
        cout << "could not read from file" << endl;
    }
    if (!in.good()) {
        cout << "Could not read, with good() function" << endl;
    }
    if (in.eof()) {
        cout << "End of file reached!" << endl;
    }

    cout << message << ": " << value << endl;

    // this resets all the bits
    in.clear();
    if (in.fail()) {
        cout << "failbit is set" << endl;        
    }
    else {
        cout << "failbit is not set" << endl;
    }
    // setstate performs an or operation of the current bit state and the requested state (setting it)
    in.setstate(std::ios::failbit);
    if (in.fail()) {
        cout << "failbit is set" << endl;        
    }
    else {
        cout << "failbit is not set" << endl;
    }

    in.close();
}

int main() {
    write();
    read();
    return 0;
}