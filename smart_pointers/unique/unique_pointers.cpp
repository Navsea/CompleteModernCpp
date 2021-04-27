#include <iostream>
#include <memory>
using namespace std;
#include "Integer.h"


void display(Integer *p) {
    if (!p)
    {
        return;
    }
    cout << p->GetValue() << endl;
}

// Function create object, but can be null
Integer * get_pointer(int value)
{
    Integer * p = new Integer{value};
    return p;
}

// the copy constructor for a unique ptr is deleted!
// so it cannot be a parameter of a function, unless you move it inside here
void store(unique_ptr<Integer> p) {
    cout << "storing data in p: " << p->GetValue() << endl;
}
// pass unique ptr by reference, this works
void store_ref(unique_ptr<Integer> &p) {
    cout << "storing data in p: " << p->GetValue() << endl;
}

void operate(int value)
{
    // writing code like this is not recommended
    Integer *p = get_pointer(value);
    if (p == nullptr) {
        p = new Integer{value};
    }
    p->SetValue(5);
    display(p);
    delete p;
    p = nullptr; // otherwise p would still contain address that has been deleted
    p = new Integer{};
    *p = __LINE__; // std c macro that expands to the current line number
    display(p);
    delete p;
    // end not recommended, use smart pointers instead

    // this code does the same as above, but w smart pointers
    unique_ptr<Integer> smart_p{get_pointer(value)};
    if (smart_p == nullptr) {
        // once a unique pointer has been assigned, you cannot change it
        // you need to use the reset function to clear everything so you can re-initialize it
        // if it would have contained something, the smart_p resource would be deleted and then the new resource assigned
        smart_p.reset(new Integer{value});
    }

    smart_p->SetValue(5);
    // display expects a reference to an integer, not the smart pointer!
    // use the get() function on the smart pointer object to get the underlying object pointer
    display(smart_p.get());
    
    // deleting smart_p is not really necessary as that is handled by itself when it goes out of scope
    // delete smart_p wouldnt work because its not a pointer, its an object
    smart_p = nullptr;  // theres an overloaded function for =, this resets the underlying resource to nullptr (does it also free the resource? YES IT DOES (check cpp reference))

    // reset also takes care of clearing the underlying resource, so above is not really necessary
    smart_p.reset(new Integer{});

    *smart_p = __LINE__;
    display(smart_p.get());

    // does not work as store uses a smart ptr as parameter, which requires a copy to be made of a unique ptr, this is a deleted function
    //store(smart_p);
    // instead, use the move function
    store(std::move(smart_p)); // moves smart_p resource to local parameter p inside store function
    // you can no longer access underlying resource, but you can use reset()

    smart_p.reset(new Integer{100});

    store_ref(smart_p);
    // underlying resource still available
    *smart_p = 200;

}

int main()
{
    operate(6);
    return 0;
}