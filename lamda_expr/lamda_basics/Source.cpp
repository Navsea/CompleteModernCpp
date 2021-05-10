#include <iostream>
//Possible implementation of a lambda expression as a function object
template<typename T>
struct Unnamed {
	T operator()(T x, T y)const {
		return x + y;
	}
};
int main() {
	//
	[]() {
		std::cout << "Most basic lamda expression" << std::endl;
	}();	// dont forget the last () if you want to call the anonymous function
	//Compiler automatically creates a function object
	auto fn = []() {
		std::cout << "Welcome to Lambda expressions" << std::endl ;
	};
	fn();
	std::cout << typeid(fn).name() << std::endl;
	//Generic/polymorphic lambda
	//							  <optional specifiers>
	// when the return type is the same as the arguments, you dont need to specify the return type
	// auto allows you to use any datatype, such as templates
	auto sum = [](auto x, auto y) mutable noexcept(false){
		return x + y;			//	^^^^		^^^^
	};
	Unnamed<int> n;
	std::cout << "Sum is:" << sum(5.5f, 2.2f) << std::endl;

	// here sum of two ints, returns a float, so you need to specify the return type ->
	auto sum2 = [](int x, int y) mutable noexcept(false)->float{
		return (float)x + y;			//	^^^^		^^^^
	};

	return 0;
}