#include "Integer.h"
#include <iostream>
#include <string>
class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	// issue is that you would need to write a constructor for each combination of r and l values as parameters

	//Employee(const std::string &name, const Integer &id) :
	//	m_Name{ name },
	//	m_Id{ id } {
	//	std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	//}

	// without the forwarding, by using the named reference, the id parameter, even though its an r value, will be converted to a l-value
	// fowarding makes sure that the argument type is preserved when passing it for construction
	template<typename T1, typename T2>
	Employee(T1 &&name,  T2 &&id) :
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;

	}
};
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main() {
	//Employee emp1{ "Umar", Integer{100} };
	/*std::string name = "Umar";
	Employee emp2{ name, 100 }; */
	Integer val{ 100 };
	// here Umar is a temporary (r value), val is an l value
	// the move constructor will be called for umar(step in code to see it happening) and copy for val
	Employee emp3{ std::string{"Umar"}, val };

	// here we pass two r-values, but wihtout forwarding, by naming the parameters a and b, it becomes an l value
	auto emp = Create("Umar", Integer{ 100 });
	return 0;
}