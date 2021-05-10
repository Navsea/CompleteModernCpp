#include <iostream>
#include <memory>
#include <vector>
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};
class Test {
	// if pA was a regular pointer, the memory would not be released when teh constructor fails
	// dont use exception handling together with raw pointers
	std::unique_ptr<A> pA{};
	B b{};
	// use unique ptr object instead of raw ptr
	std::unique_ptr<int> pInt{};
	// use string object instead of character array
	std::string pStr{};
	// use container instead of int array
	std::vector<int> pArr{};
public:
	Test() { 
		std::cout << "Test():Acquire resources" << std::endl;
		pA.reset(new A);

		/*pA = new A;
		pInt = new int;
		pStr = new char[1000];
		pArr = new int[50000];*/
	}
	~Test() {  

		std::cout << "~Test():Release resources" << std::endl; 
		// you should handle exceptions in the destructor itself, otherwise this could again give rise to memory leaks
		// The stack unwinding could not complete for example
		try {
			std::cout << "blabla" << std::endl;
			if (false) {
				throw std::runtime_error("Failed to initialize");
			}
		}
		catch(std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
		/*delete pA;
		delete pInt;
		delete[]pStr;
		delete[] pArr;*/
	}
};

int main() {
	try {
		Test t;
		throw std::runtime_error{ "Exception" };
	}
	catch (std::runtime_error &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}