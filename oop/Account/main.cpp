#include <iostream>
using namespace std;
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>
int main()
{
	Account acc("bob", 1000);
	cout << "Initial balance " << acc.GetBalance() << endl;
	acc.Deposit(200);
	acc.Withdraw(380);
	cout << "New balance: " << acc.GetBalance() << endl;

	Checking ch("Bob", 100, 50);
	Transact(&ch, ch);

	Savings sv("Bill", 200, 0.05);
	Transact(&sv, sv);

	// destructor of account class needs to be virtual!
	// otherwise the destructor of savings would not be called
	// the destructor of the pointer type is only called, not the one for what it is pointing at
	// Note that here the savings object is sliced to fit into account
	Account *acc2 = new Savings("Billy", 300, 0.05);

	/* Object slicing
	- Compiler deliberately removes some part of an boject
	- Occurs when a child class is assigned to a concrete base class object (for example passing a child class to a function that accepts a base class by value)
	- Some part of the memory might get overwritten! which would lead to memory corruption
	- To prevent this, the compiler slices the object, effectively masking the memory that contains its attributes, then the object is copied into the base oject
	*/
	// not all accounts are saving accounts
	//Savings* ps = acc2;
	// from base -> child = downcast, from child to base = upcast
	Savings* ps = static_cast<Savings*>(acc2);

	int i{};
	float f{};
	// typeid can tell you what the type is of an object
	// for polymorphic objects, it will be determined at runtime otherwise at compile time
	const std::type_info &ti = typeid(ps);
	cout << ti.name() << endl;

	// returns the type of the pointer
	const std::type_info &ti2 = typeid(acc2);
	cout << ti2.name() << endl;

	// returns what its pointing at
	const std::type_info &ti3 = typeid(*acc2);
	cout << ti3.name() << endl;

	if (ti3 == typeid(Savings)) {
		cout << "yes its a savings account" << endl;
	}

    return 0;
}
 
