#include "Integer.h"
#include <iostream>
using namespace std;
// memory contains definition of smart pointer
// ALWAYS USE SMART POINTERS BEFORE RAW POINTERS!
#include <memory>


void Process(unique_ptr<Integer> p)
{
	(*p)();
}
void Process(shared_ptr<Integer> p)
{
	(*p)();
}

void CreateInteger(void)
{
	// Here we create a unique ptr to an Integer class
	std::unique_ptr<Integer> p(new Integer{5});
	// this pointer cannot be copied
	//auto p2 = p;
	// Process(p); this would not work as its passed by value
	Process(std::move(p));

	// p cannot be dereferenced anymore!
	// what if  you still want to use p? use shared_ptr
	// shared pointer has an internal ref counter (how many copies are there of myself?)
	// fi the ref counter reaches zero, the destructor is called
	std::shared_ptr<Integer> p2(new Integer{6});
	Process(p2);
	(*p2).GetValue();
}


int main() {
	// the destructor will be called, even when memory is allocated in function, because of unique_ptr
	CreateInteger();
	return 0;
}