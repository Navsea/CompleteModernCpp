#include "Integer.h"
#include <iostream>
Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) {
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const {
	return *m_pInt;
}

void Integer::SetValue(int value) {
	if (m_pInt == nullptr)
	{
		m_pInt = new int;
	}
	*m_pInt = value;
}

Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer & Integer::operator++() {
	++(*m_pInt);
	return *this;
	// TODO: insert return statement here
}

// NOte that this is the post increment function definition
// to distinguish the pre and post, the signature has to be different, here we use int as a parameter
// note that post increment has lower performance due to the temporary being created
Integer  Integer::operator++(int) {
	Integer temp(*this);
	++(*m_pInt);
	return temp;
}

bool Integer::operator==(const Integer & a) const {
	return *m_pInt == *a.m_pInt;
}

// need to check for self assignment
// otherwise you would assign a delete memory pointer (no mem allocated)
Integer & Integer::operator=(const Integer & a) {
	if (this != &a) {
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}

Integer & Integer::operator=(Integer && a) {
	if (this != &a) {
		delete m_pInt;
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}


// Note that you cannot return a temporary object by reference (temp is temporary)
Integer Integer::operator+(const Integer & a) const {
	Integer temp;
	*temp.m_pInt = *m_pInt + *a.m_pInt;
	return temp;
}

// overloads as global function
// () is used extensively in std library
// in templates used for callbacks!
void Integer::operator()() {
	std::cout << *m_pInt << std::endl; 
}

Integer operator +(int x, const Integer &y) {
	Integer temp;
	temp.SetValue(x + y.GetValue());
	return temp;
}

// as you cannot change the iostream class
// you write to ostream, read from Integer, so ostream cannot be const
std::ostream & operator <<(std::ostream & out, const Integer &a) {
	out << a.GetValue();
	return out;
}

// Here also example of a friend functions which can access a's private value directly
std::istream & operator >> (std::istream &input, Integer &a) {
	int x;
	input >> x;
	*a.m_pInt = x;
	return input;
}
