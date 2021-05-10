#include <iostream>
//using Comparator = bool(*)(int, int);
// use std::move to ensure move semantics and not copies (std::move makes r value from l value)
// its better to use templates and function objects than function pointers as this can be optimized (inline at compile time) as opposed to  function pointers
template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size-1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}
//Function pointers as comparators
// these cannot be inlined by compiler, as you only know at runtime which function needs to be called
// they need to be global, so you cannot use locals to store some state like nr of calls to function for a specific caller
bool Comp(int x, int y) {
	return x > y;
}
bool Comp1(int x, int y) {
	return x < y;
}


//Function Object as comparator
// this is an object, so you can store some state! as opposed to the function pointers
// this is the preferred method also because its more effecient because function can be inlined
struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};
int main() {
	Comp(3, 5);
	Comp2 comp;
	comp(3, 5);//comp.operator()(3,5) ;
	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	Sort(arr, comp);
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}