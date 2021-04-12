//Add two numbers and return the result through a reference parameter
void Add(int a,int b, int &result)
{
    result = a + b;
}

//Find factorial of a number and return that through a reference parameter
void Factorial(int a, int &result)
{
    result = 1;
    for(int i{a}; i > 0; i--)
    {
        result *= i;
    }
}

 //Swap two numbers through reference arguments
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}          