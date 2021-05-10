#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <climits>
class Test {
	int x;
public:
	Test() { 
		std::cout << "Test():Acquire resources" << std::endl; 
	}
	~Test() { 
		std::cout << "~Test():Release resources" << std::endl; 
	}
};

/*
By use exception handling, we can force the user of a function to check if a function has succesfully executed or nto
while by using just returns, the user could just not check the return value
This is a method to handle runtime errors and must be handled immediately, otherwise the program crashes
*/

void ProcessRecords(int count) {
	// t is now an object, and not a pointer, so when the object goes out of scope, it will destroy the underlying memory because its a smart pointer
	std::unique_ptr<Test> t(new Test);
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	std::vector<int> p;
	// reserve memory for count elements
	// if the reserve fails, it will throw a bad alloc exception
	// USE SMART POINTERS OR CONTAINERS NO DYNAMICALLY ALLOCATED ARRAYS
	p.reserve(count);
	std::vector<int> records;
	records.reserve(count);
	//Process the records
	for (int i = 0; i < count; ++i) {
		records.push_back(i);
	}
	// part of <random>
	std::default_random_engine eng;
	std::bernoulli_distribution dist;
	int errors{};
	for (int i = 0; i < count; ++i) {
		// handle exception locally, so the whole functions is not aborted
		try {
			std::cout << "Processing record # : " << i << " ";
			if (!dist(eng)) {
				++errors;
				throw std::runtime_error("Could not process the record");
			}
			std::cout << std::endl;
		}
		catch (std::runtime_error &ex) {
			std::cout << "[ERROR " << ex.what() << "]" << std::endl;
			if (errors > 4) {
				// create a custom msg for the error
				std::runtime_error err("Too many errors. Abandoning operation");
				// original exception is modified (as ex is passed by ref)
				ex = err;
				throw;
			}
		}
	}
}
/*
Old code using raw pointers
*/
void ProcessRecordsOld(int count) {
	/*
	Compare this code with the code that uses RAII.
	*/
	// Test on the heap is not properly destroyed, this can cause a memory leak!
	// but t2 on the stack is, the stack is properly unwinded when an exception occurs
	Test *t = new Test;
	// You create an R value object here, then use the default copy assigment operator! and then the r value is destroyed
	//Test t2 = Test();
	Test t2;
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	// will also cause a memory leak
	// you can also use a vector here so that its an object again
	// AVOID DYNAMIC ARRAYS USE CONTAINERS INSTEAD
	int *p = new int[count];
	int *pArray = (int*)malloc(count * sizeof(int));
	if (pArray == nullptr) {
		throw std::runtime_error("Failed to allocate memory");
	}
	//Process the records
	for (int i = 0; i < count; ++i) {
		pArray[i] = i;
	}
	//Unreachable code in case of an exception
	free(pArray);
	delete[] p;
	//delete t;

}
int main() {
	// try {
	// 	//numeric_limits is a class that gives access to the limits of primitives, alternative to limits.h
	// 	ProcessRecordsOld(9);
	// }
	// catch (...) {
	// 	std::cout << "something failed" << std::endl;
	// }

	try {
		//ProcessRecords(std::numeric_limits<int>::max());
		ProcessRecords(10);
	}
	catch (std::runtime_error &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::bad_alloc &ex) {
		std::cout << ex.what() << std::endl;

	}

	/*
	std::exception is the base class for all standard
	exception classes. It can be used as a handler if
	the exception handling code is same for all child
	class exception objects
	*/
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	/*
	All-catch handler. Avoid as it does not give any
	information about the exception, so it is difficult
	to take any preventative action
	this also will catch non standard exceptions
	should be the last one of the catch statements
	*/
	catch (...) {
		std::cout << "Exception" << std::endl;
	}
	return 0;
}

