#include <iostream>
using namespace std;
#include <memory>
#include "Integer.h"

class Printit {
    int * m_int{};
public:
    void set_value(int *value) { m_int = value; }
    int print() { cout << "address: " << m_int << " value: " << *m_int << endl; }
};

class Printit2 {
    shared_ptr<int> m_int{};
public:
    void set_value(shared_ptr<int> value) { m_int = value; }
    int print() { 
        cout << "address: " << m_int << " value: " << *m_int << endl; 
        cout << "Nr of references: " << m_int.use_count() << endl;
    }
};

class Printit3 {
    weak_ptr<int> m_int{};
public:
    void set_value(weak_ptr<int> value) { m_int = value; }
    int print() { 
        if (m_int.expired()) { cout << "Resource was deleted" << endl; return 1;}
        else {
            // retrieve shared pointer
            auto sh_p = m_int.lock();
            cout << "address: " << sh_p << " value: " << *sh_p << endl; 
            cout << "Nr of references: " << sh_p.use_count() << endl;\
            return 0;
        }
    }
};

int main() {
    Printit print;
    int num{};
    cin >> num;
    int *p = new int{num};
    print.set_value(p);
    if (*p > 10) {
        delete p;
        p = nullptr;
    }
    // This may try to dereference a deleted resoruce
    // so print function needs protection against that
    // you cannot check against nullptr because the p object is assigned to null, but not the m_int member
    print.print();
    delete p;

    // USE SMART PTRS
    // You need some communication betwen p pointer and member pointer
    // You should use shared ptr because you share the address between p and m_int
    Printit2 print2;
    int num2{};
    cin >> num2;
    shared_ptr<int> p2{new int{num2}};
    print2.set_value(p2);
    if (*p2 > 10) {
        p2 = nullptr;
        // HERE THE UNDERLYING MEMORY IS NOT RELEASED!!!!
    }
    // This may try to dereference a deleted resoruce
    // so print function needs protection against that
    // you cannot check against nullptr because the p object is assigned to null, but not the m_int member

    print2.print();

    // ======================== WEAKPTRS =============
    // weak ptr is always initialized with a shared ptr
    // weak ptr points to the internal reference count(= control block) of the shared ptr
    // when you reset the shared ptr, the weak ptr will still point to the control block 
    // when the weak ptr is destroyed, only then the control block will be deleted! So the control block also has an internal reference counter for weak ptrs
    // the expired function will return true when the ref count of the shared ptr is zero.
    // when you call the .lock function on the weak ptr, it will return a shared ptr and increase the ref count. (so when original shared ptr is deleted, the underlying resource will not be deleted)
    Printit3 print3;
    int num3{};
    cin >> num3;
    shared_ptr<int> p3{new int{num3}};
    print3.set_value(p3);
    if (*p3 > 10) {
        p3 = nullptr;
        // HERE THE UNDERLYING MEMORY IS NOT RELEASED!!!!
    }
    // This may try to dereference a deleted resoruce
    // so print function needs protection against that
    // you cannot check against nullptr because the p object is assigned to null, but not the m_int member

    print3.print();
}