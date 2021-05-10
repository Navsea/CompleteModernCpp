#include <iostream>
using namespace std;
#include <initializer_list>
#include <cassert>
/*
not to be confused with member initializer list of classes
often used with container classes (classes that can contain multiple datatypes/classes)
it is used to initialize a custom class with uniform initializer

- its a lightweight proxy object that represents an array of objects
- constructed automatically from a braced list of elements
    - when using a ranged for loop
    - when using a constructor that accepts an init list
    - or other function accepting it
    - auto
- not a true container, but similar behaviour
- provides access to its elements through iterators
- defined in <initializer_list> header file
*/

class Bag {
    int arr[10];
    int m_size{};
public:
    Bag(std::initializer_list<int> values) {
        assert(values.size() <= 10);
        auto it = values.begin();
        while (it != values.end()) {
            add(*it);
            it++;
        }
    }
    Bag() {}
    void add(int value) {
        assert(m_size <= 10);
        arr[m_size++] = value;
    }
    void remove() {
        m_size--;
    }
    int operator [](int index) {
        return arr[index];
    }
    int get_size() const {
        return m_size;
    }
};

void print(std::initializer_list<int> values) {
    // auto it = values.begin();
    // while (it != values.end()) {
    //     cout << *it << " ";
    // }
    // cout << endl;

    for( auto x: values ) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int x{0};
    float y{3.1f};
    int arr[4]{1,2,3,4};
    std::string{"Hello world!"};

    std::initializer_list<int> data = {1,2,3,4};

    Bag b;
    b.add(3);
    b.add(1);
    b.add(8);
    for (int i = 0; i < b.get_size(); ++i) {
        cout << b[i] << " ";
    }

    // how to initialize bag with initializer list
    Bag c{1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < c.get_size(); ++i) {
        cout << c[i] << " ";
    }

    print({5,6,7,8});
    return 0;
}