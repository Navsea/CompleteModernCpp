#include <iostream>
/*
Applied to functions (in declarations and definitions)
indicates that the function does not throw any exceptions
this allows the compiler to optimize the code, because it does not need stack unwinding code
if it does throw an exception, the program will immediately terminate and it is not defined if stack unwinding will occur
if you call a library function, you should not specify noexcept as lib might do it

if you use move constructors, use noexcept on those functions
some containers like vector would only use the move function if it has the noexcept specifier
*/

// noexcept can take an argument (false = can throw, true = does not throw, default is true)
void Test(int x)noexcept(false) {
	std::cout << x << std::endl;
	//throw x;
}
// noexcept is also an operator, which takes an expression
// will return a boolean function to check if a function is noexcept true or false
int Sum(int x, int y)noexcept(noexcept(Test(x))) {
	Test(x);
	return x + y;
}
class A {
public:
	//Destructors are implicitly noexcept(true) in C++11
	~A() {
		throw 3; 
	}
};
int main() {
	A a;
	//boolalpha manipulator prints 0 & 1 as false & true
	std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;
	try {
		Sum(3, 5);
		//Other statements
	}
	catch (int x) {
		std::cout << x << std::endl ;
	}
}