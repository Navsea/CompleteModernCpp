//Add two numbers and return the sum
int Add(int *a, int *b)
{
    return *a + *b;
}

//Add two numbers and return the sum through the third pointer argument
void AddVal(int *a, int *b, int *result)
{
    *result = *a + *b;
}

//Swap the value of two integers
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Generate the factorial of a number and return that through the second pointer argument
void Factorial(int *a, int *result)
{
    *result = 1;
    for(int i{*a}; i > 0; i--)
    {
        *result *= i;
    }
}