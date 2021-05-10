#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

struct Record {
    int id;
    char name[10];
};

void write_record(Record *p) {
    std::ofstream binstream{"records", std::ios::binary | std::ios::out };
    binstream.write((const char *)p, sizeof(Record));
}

// when reading a binary file, you need to know how many records there are
// there is no eof flag for a binary stream!
Record read_record() {
    std::ifstream input{"records", std::ios::binary | std::ios::in };
    Record r;
    input.read((char*)&r, sizeof(Record));
    return r;
}

int main() {
    std::ofstream textstream{"data"};
    // 8 bytes of data
    textstream << 12345678;

    // now open a file in binary mode
    std::ofstream binstream{"binary", std::ios::binary | std::ios::out};
    int num{12345678};
    // this writes bytes, so you have to cast num to ...
    // written as binary data (0x00BC614E), only uses 4 byes 
    binstream.write((const char *)&num, sizeof(num));
    // close it so we can read it next, seems not to be necessary
    binstream.close();

    std::ifstream input{"binary", std::ios::binary | std::ios::in};
    input.read((char *)&num, sizeof(num));
    std::cout << num << std::endl;

    Record r;
    r.id = 1000;
    // you cannot directly write string into character array (you cannot use assigment operator on arrays)
    //r.name = "Hello";
    strcpy(r.name, "Hello");

    write_record(&r);

    Record other = read_record();
    std::cout << other.id << ": " << other.name << std::endl;
    
    return 0;
}