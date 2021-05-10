#pragma once
#include <string>
class Account {
	std::string m_Name;
	int m_AccNo;
	static int s_ANGenerator;
protected:
	float m_Balance;
public:
	Account(const std::string &name, float balance);
	virtual ~Account();
	const std::string GetName()const;
	float GetBalance()const;
	int GetAccountNo()const;

	// virtual indicates that the functions are implemented by the child classes
	virtual void AccumulateInterest();
	virtual void Withdraw(float amount);
	void Deposit(float amount);
	virtual float GetInterestRate()const;
};

