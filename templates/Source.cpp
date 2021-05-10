#include <iostream>
#include <cstring>
/*
You can override template deduction by specifying the type yourself
fe Max<int>(5,4);
*/

//Old Code
//int Max(int x, int y) {
//	return x > y ? x : y;
//}
//float Max(float x, float y) {
//	return x > y ? x : y;
//}

//Primary Template
// compiler will only generate the functions for the 
// types wich calls are made
template<typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}
//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specialization
// used when you need specific handling of a datatype (like strings, if you compare a string, we would compare the addresses if you use the regular template)
template<> const char * Max<const char*>(const char *x, const char *y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

void Examples() {
#pragma region Instantiation Examples
    // explicit cast to make sure the int is a float so that arguments are of the same type
	Max(static_cast<float>(3), 5.5f);

	//Override compiler's deduction process
	Max<double>(3, 6.2);

	//Causes implicit instantiation of Max<int>
    // here we are creating a function pointer
	int(*pfn)(int, int) = Max;

#pragma endregion
#pragma region Explicit Instantiation
	const char *b{ "B" };
	const char *a{ "A" };
	auto s = Max(a, b);
	std::cout << s << std::endl;
#pragma endregion
}

//Non-type template parameter
template<int size>
void Print() {
	char buffer[size];
	std::cout << size << std::endl;
}
//Requires size as explicit argument
template<typename T>
T Sum(T*parr, int size){
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += parr[i];
	}
	return sum;
}
//Size is implicitly calculated in non-type template argument
template<typename T,int size>
T Sum(T (&arr)[size]) {
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
int main() {
	Print<3>();
    // the template non type argument has to be a constant!
    int i = 3;
    //Print<i>();
    // sizeof is calculated at compile time so the argumetn needs to be a constant expression constexpr!
    // you would use this for determining the size of an array for example, thats allowed because the argument is constant and cannot be changed in the template function!
    Print<sizeof(i)>();
	int arr[]{ 3,1,9,7 };
	//int (&ref)[5] = arr ;
	int sum = Sum(arr);
	std::cout << sum << std::endl; 
	return 0;
}