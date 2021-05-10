#include <iostream>
using namespace std;

#include <vector>

int main() {
    // what if you would want to change the size dynamically
    int arr[10];

    // you could allocate mem on the heap
    int *ptr = new int[10];
    for (int i = 0; i < 10; ++i) {
        ptr[i] = i * 10;
    }
    // now you would need to allocate new memory that has a bigger memory allocation
    // and then copy over everything from the old to the new
    // and free the old memory
    // this is very involved, instead use vector class!

    std::vector<int> arr2{1,2,3};
    // grows with one element
    arr2.push_back(4);
    for (int i = 0; i < 5; i++) {
        arr2.push_back(i*10);
    }
    // access
    arr2[0] = 100;
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i: arr2) {
        cout << i << " ";
    }
    cout << endl;
    auto it = arr2.begin();
    cout << *it << endl;
    ++it;
    it = it + 5;
    // delete
    auto it2 = arr2.begin();

    arr2.erase(it2);
    for (int i: arr2) {
        cout << i << " ";
    }
    cout << endl;
    // insert
    it2 += 5;
    arr2.insert(it2, 500);
    for (int i: arr2) {
        cout << i << " ";
    }


    return 0;
}