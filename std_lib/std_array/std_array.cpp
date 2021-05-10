#include <iostream>
#include <array>

// its important to note that the end iterator points beyond the last element, so never dereference the end ptr

void array_func(){
    std::array<int,5> arr{3,1,5,6,8};
    for(int i=0; i<arr.size();++i) {
        arr[i] = 5;
    }
    int it = 0;
    for(int i: arr) {
        std::cout << i;
        std::cout << " addr: " << &arr[it] << std::endl;
        ++it;
    }
    std::cout << std::endl;

    auto itr = arr.begin();

    // return the data array (c array)
    // even though you allocated new memory, you changed the addresses c_arr was pointing to!
    // if you wanted to move it, you should probably use a unique ptr object wrapper
    int *c_arr = new int[5];
    for (int i = 0; i < 5; i++) {
        std::cout << c_arr[i];
        std::cout << "old c_arr addr: " << &c_arr[i] << std::endl;
    }
    c_arr = arr.data();
    for (int i = 0; i < 5; i++) {
        std::cout << c_arr[i];
        std::cout << "new c_arr addr: " << &c_arr[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    array_func();
    return 0;
}