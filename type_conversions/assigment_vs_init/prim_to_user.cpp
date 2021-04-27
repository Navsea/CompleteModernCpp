#include <iostream>
#include "Integer.h"
using namespace std;

void print(const Integer a)
{

}

class Product
{
    Integer m_id; 
    public:
        Product(const Integer &id) {
            cout << "Public(const Integer &id)" << endl;
            m_id = id;
        }
        ~Product()
        {
            cout << "~Product()" << endl;
        }

};

class Product2
{
    Integer m_id; 
    public:
        Product2(const Integer &id): m_id(id) {
            cout << "Public(const Integer &id)" << endl;
            //m_id = id;
        }
        ~Product2()
        {
            cout << "~Product()" << endl;
        }

};

int main()
{
    Integer a{1}; // invoked explicitly
    // INITIALIZATION VS
    Integer b; // may be invoked implicitly it will search for parameterzed constructor
    //Integer b = "abc" // will try to find constructor with string

    print(5);   // parameterized constructor is invoked

    // ASSIGNMENT
    b = 7;  // there is no constructor with int, but there is one with r values so that one is used
            // the move assigment will construct an object through its parameter and temporary is moved in object on left hand side

    // what if we dont want implicit type conversions!!
    // use keyword explicit before function declaration

    /* initialization vs assigment
    note that the creation of "a" only calls the constructor
    while with b you first call default constructor for b
    then you call the parameterized constructor for the creation of the temp r value
    then you move that resource to variable b
    then temp is destroyed

    SO INITIALIZATION IS ALWAYS BETTER THAN ASSIGNMENT
    */
    Product p{5};
    /*
    Integer(int): the 5 in the uniform init is converter to Integer object
    Integer():  The Integer member m_id is constructed
    Public(const Integer &id): the constructor is called with the r value Integer object
    operator=(const Integer & a): the r value is moved into b
    ~Integer()
    ~Product()

    You can avoid this, by using member initialization
    */

    Product2 p2{6};
    /* gives one less function call
    Integer(int): 6 is converted to Integer object
    Integer(const Integer&): Integer object is copied into member
    Public(const Integer &id): Constructor Product
    */
    return 0;
}