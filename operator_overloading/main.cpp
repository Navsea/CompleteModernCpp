#include "Integer.h"
#include <iostream>
using namespace std;
#include <memory>

/*
Rules of operator overloading:
- associative, precedence and arity(operand count) does not change during overloading
- Operator functions should be non-static EXCEPT NEW and DELETE
- At least one of the operands should be a user defined type
- If the first operand can be primitive type, it has to be overloaded as a global function
- not all can be overloaded: . ? sizeof ect
- No new operators!
*/

class IntPtr {
	Integer *m_p;
public:
	IntPtr(Integer *p) :m_p(p) {

	}
	~IntPtr() {
		delete m_p;
	}
	Integer *operator ->() {
		return m_p;
	}
	Integer & operator *() {
		return *m_p;
	}
};
void CreateInteger() {
	std::unique_ptr<Integer> p(new Integer);
	//auto p2(p);
	(*p).SetValue(3);
	//std::cout << p->GetValue() << std::endl; 
}
void Process(Integer val) {

}

int main() {
	Integer a(3);
	/*auto b(std::move(a));
	std::cout << a << std::endl;*/
	Process(std::move(a));

	a.SetValue(4);

	// you can sum a primitive with custom class, uses type conversion (int 5 to Integer(5) )
	Integer b = a + 5; // a.operator+(5)
	Integer c = 5 + a; // 5 does not have integer sum definition --> created one in Integer.cpp (global function)

	cout << "using Integer class with << operator " << c << endl;
	// this is expanded as
	// operator <<(cout, c).operator <<(endl)

	cin >> c;
	cout << "new value of c: " << c << endl;

	// using () operator
	b();
	
	return 0;
}