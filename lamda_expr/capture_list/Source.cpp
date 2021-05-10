#include <iostream>
#include <fstream>
//using Comparator = bool(*)(int, int);
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
bool Comp(int x, int y) {
	return x > y;
}
bool Comp1(int x, int y) {
	return x < y;
}
struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}
template<typename T>
struct __Unnamed {
	int offset;
	__Unnamed(int off) :offset(off) {

	}
	void operator()(T &x) {
		x += offset;
		++offset;
	}
};
class Product {
	std::string name;
	float price;
public:
	Product(const std::string &n, float p) :name(n), price(p) {

	}
	void AssignFinalPrice() {
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		//Capture this, allows access to the member variables, these are modifiable, no way to capture individual members
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			price += taxedPrice;
		});
	}
	float GetPrice()const {
		return price;
	}
};
int main() {

	// you can use it as a function pointer, as long as capture list is empty! (there's a type conversion operator created that returns the function pointer)
	atexit([]() {
		std::cout << "Program is exitting..." << std::endl; 
	});
	/*Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << p.GetPrice() << std::endl;*/

	//Lambda within a lambda
	[](int x) {
		x *= 2;
		[](int x) {
			std::cout << x << std::endl; 
		}(x);
	}(5);
	__Unnamed<int> n(3);
	int x = 5;
	n(x);
	int arr[]{ 1,6,8,4,0 };
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
	});
	std::cout << std::endl; 
	int offset = 0;
	/*ForEach(arr, [offset](auto &x) {
		x += offset;
	});*/

	// mutable allows you to change offset from the capture list [offset] (removes the const from the operator() function overload)
	// everythin in the capture list is passed by value! you could pass it by &ref then mutable is not needed anymore
	//ForEach(arr, [offset](auto &x)mutable {
	//	x += offset;
	//	++offset;
	//});

	int sum{};
	// the & in the capture list indicates that all declared variables in current scope schould be passed by ref
	// here offset is added, because fe we want ot pass that one by value
	// you can also pass everything by value with the = sign [=]
	ForEach(arr, [&, offset](auto &x) {
		sum += x;
	});
	std::cout << "Sum:" << sum << std::endl;
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
	});
	std::cout << std::endl;

	int z{5};
	// generalized lambda capture, creating a new variable
	// to create a new reference use &y = z
	// could be useful for when a resource is only used in the lambda expression, std::move, or unique pointer
	auto f = [y=z](int arg) {
		return y + arg;
	};

	// could be useful in this case fe
	std::ofstream out{"file.txt"};
	// out is only used in this lamda expression for example
	// so you need to move the resource to the local out variable
	// you also need ot make the lamda expression mutable, so you can write to out
	auto write = [out = std::move(out)](int x) mutable {
		out << x;
	};

	write(200);

	return 0;
}

void OldCode(){
	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	auto comp = [](auto x, auto y) {
		return x > y;
	};
	Sort(arr, comp);
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}