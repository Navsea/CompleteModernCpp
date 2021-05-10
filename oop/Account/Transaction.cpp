#include "Transaction.h"
#include <iostream>
#include "Checking.h"
#include <typeinfo>


void Transact(Account * pAccount, Account &Account2) {
	std::cout << "Transaction started" << std::endl; 
	std::cout << "Initial balance:" << pAccount->GetBalance() << std::endl;
	pAccount->Deposit(100);
	/* polymorphism
		This function has different implementations for different objects of the same basetype Account
		So this object can be seen as an account, checking or savings object
	*/
	pAccount->AccumulateInterest();
	//if (typeid(*pAccount) == typeid(Checking)) {
	//	Checking *pChecking = static_cast<Checking*>(pAccount);
	//	std::cout << "Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;
	//}

	// Account does not have this function!
	// We need to apply downcast to the account ptr
	// What if account is not a checking acount???
	// RTTI concept typeid, but this causes some overhead
	// The type information is stored in the objects!
	if (typeid(*pAccount) == typeid(Checking))
	{
		std::cout << "call specific checking account function" << std::endl;
	}
	// this is a better way to do it:
	// dynamic checks if the cast can occur
	// and will return a nullptr if it cant
	Checking *pChecking = dynamic_cast<Checking*>(pAccount);
	if (pChecking != nullptr) {
		std::cout << "Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;
	}

	// note that for references this can cause issues, as a reference always needs to be intialized with a value, so it cannot contain nullptr
	// it would throw an exception, which you could catch in try-catch block
	try {
		Checking& Checking_ref = dynamic_cast<Checking&>(Account2);
	}
	catch(std::exception &ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	// if (Checking_ref != nullptr) {
	// 	std::cout << "Minimum balance of Checking_ref:" << Checking_ref.GetMinimumBalance() << std::endl;
	// }

	pAccount->Withdraw(170);
	std::cout << "Interest rate:" << pAccount->GetInterestRate() << std::endl;
	std::cout << "Final balance:" << pAccount->GetBalance() << std::endl;
}
