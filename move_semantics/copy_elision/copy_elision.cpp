/* Copy elision

// Named return value optimization
Integer add(int a, int b)
{
    Integer temp(a + b);    // would normally create one object
    return temp;            // another object is created here
}

// Return value optimization (even in debug mode the move constructor into a is avoided)
Integer add(int a, int b)
{
    return Integer(a + b);
}

int main() {
    Integer a = 3; 
    // 3 is a primitive! so compiler could expand this as 
    Integer a =  Integer(3) = COPIED (norally this causes another constructor call)
    Because the compiler sees that theres a constructor for the Integer class it elides the creation of Integer(3) temporary object
    
    Integer a = add(3, 4);
    copy and move elision: copy or move constructor is omnitted and is enabled by default
    can be turned off with -fno-elide-constructors compiler flag

    // if you turn off the no elide flag (fno-elide-constructors) YOU WOULD ONLY SEE ONE CONSTRUCTOR!
    // YOU WOULD ONLY SEE THE CONSTRUCTOR FOR THE temp VARIABLE IN ADD FUNCTION

    // same example is visual studio in debug mode would add the following constructor
    // AND A MOVE CONSTRUCTOR for moving the r value temp into a
    // so the return that would cause a move is omnitted!
    // this is called named return value optimization
    // when using visual studio in release mode, it would also elide that last move constructor


}
