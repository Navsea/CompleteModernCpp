#include <iostream>
#include <vector>
#include <list>

const char * GetErrorMessage(int errorNo) {
	return "Empty";
}
//typedef const char *(*PFN)(int);
using PFN = const char *(*)(int);
void ShowError(PFN pfn){
	
}
//typedef std::vector < std::list<std::string>> Names;

// with type aliases you can use templates!
template<typename T>
using Names = std::vector<std::list<T>>;

// type alias
//using Names = std::vector<std::list<std::string>>;

int main() {
	Names<std::string> names;
	Names<Names<std::string>> nnames;

	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
