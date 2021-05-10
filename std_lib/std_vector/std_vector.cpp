/* 
good for random access of elements vector[5] for example,
but not good for insertion and deletion except for at the end */

#include <iostream>
#include <vector>

void vector() {
    std::vector<int> coll{1,2,3,4};
    // infinite loop, you are adding elements so vector size if ever increasing
    for(int i=0; i<5;++i) {
        coll.push_back(i*10);
        std::cout << coll.size() << std::endl;
    }
    coll[0] = 100;

    for(int i=0; i<coll.size(); ++i) {
        std::cout << coll[i] << std::endl;
    }

    auto it = coll.begin();
    while(it!=coll.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // will have performance hit, because everything has to be shifted
    coll.insert(coll.begin(), 700);
    coll.erase(coll.end()-1); // cannot deref last element so do -1
    // even better
    coll.pop_back();

}

int main() {
    vector();
    return 0;
}