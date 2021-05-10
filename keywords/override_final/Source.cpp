#include <iostream>


/* None of the functions are marked as virtual, so you cannot override them
Destructor is also not virtual! which might lead to memory leaks as the child class destructor might not be called
THIS SHOULD NOT BE USED TO INHERIT FROM
MARK CLASS AS final to do this
*/
class Zip final {
public:
	Zip() {

	}
	void Compress(const std::string &filename) {

	}
	void Decompress(const std::string &filename) {

	}
	void PrintStatistics() {

	}
	/*
	Destructor is not virtual, therefore it is risky to 
	inherit from this class.

	Zip *p = new FastZip ;
	delete p ;

	This would call Zip destructor only. Therefore, the destructor 
	of FastZip will not execute & it will not be able to release
	any resources
	*/
	~Zip() {
		//release resources
	}
};

//class FastZip : public Zip { //Cannot inherit from a final class
//
//};

// Note that when overriding a function, the signature needs to be the same

#pragma region Override
class Document {
public:
	virtual void Serialize(float version) = 0;
};
class Text : public Document {
public:
	// here we use override, if you use different function signature, it will give error. Its good practice to always use override
	// final indicates that this function cannot be overwritten!
	void Serialize(float version)override final{
		std::cout << "Text::Serialize" << std::endl;
	}
};
class RichText : public Text {
public:
	//Cannot override because the function is final in base    
	/*void Serialize(float version)override {
		std::cout << "RichText::Serialize" << std::endl;
	}*/
};

class XML : public Document {
public:
	void Serialize(float version)override {
		std::cout << "XML::Serialize" << std::endl; 
	}
};

void Write(Document *p) {
	p->Serialize(1.1f);
}
#pragma endregion

int main() {
	XML xml;
	Write(&xml);
	return 0;
}