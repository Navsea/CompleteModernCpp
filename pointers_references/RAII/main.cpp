#include "Integer.h"
#include <iostream>
using namespace std;
#include <memory>
// Resource acquisition is initialization (RAII)
// When using ptrs you have to be careful, cause memory is not automatically freed
// RAII can solve this, see IntPtr, this behaves as a smart pointer

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

	Integer *p1 = new Integer;
	p1->SetValue(5);
	//std::unique_ptr<Integer> p(new Integer);
	//auto p2(p);
	//(*p).SetValue(3);
	std::cout << p1->GetValue() << std::endl; 
	// YOU NEED TO CALL DELETE ON THE POINTER! OTHERWISE IT p1 IS NOT DESTROYED!
	// DYNAMICALLY ALLOCATED MEMORY DOES NOT GET DELETED OUTSIDE THE SCOPE OF THE FUNCTION
	// IT IS OWNED BY THE PROCESS
	delete p1;
}
void CreateIntegerRAII() {

	IntPtr p2(new Integer);
	p2->SetValue(4);
	(*p2).SetValue(3);
}
void Process(Integer val) {

}

int main() {
	CreateInteger();
	CreateIntegerRAII(); // Resource is automatically freed when p2 goes out of scope

	
	return 0;
}