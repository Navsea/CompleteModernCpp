#include <iostream>
using namespace std;


int main() {
    // this code checks if the program is used on 32bit system
    // but you can still compile it if 64-bit because its checked at runtime
    if(sizeof(void *) != 4) {
        cout << "not in 32-bit mode" << endl;
        return 1;
    }
    else {
        cout << "everything AOK!" << endl;
    }

    // instead use
    static_assert(sizeof(void *)==4, "Compile in 32-bit mode only!");
}