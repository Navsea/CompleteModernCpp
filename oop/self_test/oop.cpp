#include <iostream>
using namespace std;
#include <typeinfo>

/* Testing function overloading
func1: compile time function overloading
func2-4: runtime function overloading
func4: pure function (needs to be implemented by child class)
func5: final function (cannot be overridden)
DerivedPriv is testing the private inheritance keyword
*/

class Base {
public:
    int x;
    
    // Base() {
    //     cout << __PRETTY_FUNCTION__ << endl;
    // }
    Base(int x) {
        this->x = x;
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void func1() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    virtual void func2() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    virtual void func3() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    virtual void func4() = 0;

    virtual void func5() final {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class BaseNonVirt {

};
class DerivedNonVirt: public BaseNonVirt {

};

class Derived: public Base {
public:
    int x;

    // You cannot use the default constructor because the class you inherit from does not have a default constructor
    // Derived() = default;
    Derived(int x): Base(5) {
        this->x = x;
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void func1() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void func2() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void func4() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    // you cannot override a final function!
    // void func5() {
    //     cout << __PRETTY_FUNCTION__ << endl;
    // }
};

class DerivedPriv: private Base {
public:
    int x;

    DerivedPriv(int x): Base(5) {
        this->x = x;
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void func1() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void func2() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void func4() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    // you cannot override a final function!
    // void func5() {
    //     cout << __PRETTY_FUNCTION__ << endl;
    // }
};

int main() {

    Derived der = Derived(3);
    der.func1();
    der.func2();
    der.func3();
    der.func4();
    der.func5();

    Base* base = &der;
    base->func1();
    base->func2();
    base->func3();
    base->func4();
    base->func5();

    cout << der.x << endl;
    cout << base->x << endl;

    DerivedPriv derpriv = DerivedPriv(3);
    derpriv.func1();
    derpriv.func2();
    // this function is not implemented in the derived class
    // as it is inherited with private, you cannot call the base class function
    //derpriv.func3();
    derpriv.func4();
    // same here
    //derpriv.func5();

    cout << "typeid(der).name(): " << typeid(der).name() << endl;
    cout << "typeid(base).name(): " << typeid(base).name() << endl;
    cout << "typeid(*base).name(): " << typeid(*base).name() << endl;
    cout << "typeid(derpriv).name(): " << typeid(derpriv).name() << endl;

    DerivedNonVirt dernonvirt = DerivedNonVirt();
    BaseNonVirt* basenonvirt = &dernonvirt;

    cout << "typeid(dernonvirt).name(): " << typeid(dernonvirt).name() << endl;
    cout << "typeid(basenonvirt).name(): " << typeid(basenonvirt).name() << endl;
    // Even thought the pointer basenonvirt is pointing to a DerivedNonVirt object, it still says BaseNonVirt when you do typeid on the dereffed ptr
    // This is because non of the base class functions are virtual, so no typeid information is saved in the object of BaseNonVirt!
    cout << "typeid(*basenonvirt).name(): " << typeid(*basenonvirt).name() << endl;

    return 0;
}