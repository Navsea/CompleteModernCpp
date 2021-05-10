#include <iostream>
using namespace std;

/* access modifiers (not really shown in code)
- public Animal: will keep the inherited members as is
- protected Animal: all more open modifiers will be downgraded to protected (public -> protected)
- private Animal: everything will not be accessable, even public stuff
*/

class Animal {
public:
    void eat() {
        cout << "Animal eating" << endl;
    }
    void run() {
        cout << "Animal running" << endl;
    }
    void speak() {
        cout << "Animal speaking" << endl;
    }
};

class Dog: public Animal {
public:
    void speak() {
        cout << "Dog barking" << endl;
    }
};

int main() {
    Dog d;
    d.eat();
    d.speak();
    return 1;
}