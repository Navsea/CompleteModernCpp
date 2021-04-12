#include <iostream>
using namespace std;

/* Namespace
1. Named declarative region use for delaring types (functions, variables, classes, structures)
2. The types are not visible ouside of the namespace
3. The std library is in the std namespace
4. Prevents name clashes (it will build if same name is reused under different namespace)
5. Helps to modularize code (everything that belongs together is grouped)
6. You can nest namespaces

namespace <name> {
    <insert everything belonging to the same namespace>
}

Access to namespace
1. types inside of namespace have a scope, they cannot be accessed outside of the namespace scope
2. to use the types, you need to open the namespace, using "using namespace <name>" (access all functionality within the scope this statement was put (like inside a function)
3. its better to open only what you need, so instead of using namespace, use using std::cout for example
*/
float calculate(float x, float y)
{
    return (x + y) / 2;
}
namespace sum
{
    // this would cause name clash and will not compile if in same namespace
    float calculate(float x, float y)
    {
        return x + y;
    }
}
namespace sort
{
    void quick_sort()
    {

    }
    void insertion_sort()
    {

    }
    void merge_sort()
    {

    }
    namespace comparison
    {
        void less()
        {

        }
        void greater_c()
        {

        }
    }
}

namespace 
{
    int my_var{5};
}


int main()
{
    float average = calculate(5.0,4.1);
    cout << "Average: " << average << endl;

    float sum = sum::calculate(5.0,4.1);
    cout << "Sum: " << sum << endl;

    // using namespace sum --> This will not work
    // you opened the namespace and now you have two definitions with the name calculate in the same scope
    float result = calculate(5.0,4.1);
    cout << "result: " << result << endl;

    // open namespace
    using namespace sort::comparison;
    greater_c();
    // or
    sort::comparison::less();

    // you can also use a nameless namespace and then you dont have to open the namespace
    cout << "nameless namespace: " << my_var << endl;

    return 0;
}