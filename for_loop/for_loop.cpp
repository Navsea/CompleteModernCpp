#include <iostream>     // cout
using namespace std;
#include <random>       // mt199937 and uniform_int_distribution
#include <algorithm>    // generate
#include <vector>       // vector
#include <iterator>     // begin, end, and ostream_iterator
#include <functional>   // bind
#include <chrono>

std::vector<int> creat_random_data(int n);

void test_copy_vs_ref_performance(void);

int main()
{
    int arr[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    // range based for loop
    // it does not need an index variable
    // can be used with any variable that behaves like a range
    // this will create a copy to i every iteration!!!
    for (auto i: arr)
    {
        cout << i;
    }
    cout << endl;

    // the copy can be avoided by defining the variable as a reference
    for (auto &i: arr)
    {
        cout << i;
    }
    cout << endl;

    int *p_begin = &arr[0];
    int *p_end = &arr[5];
    // its better to use:
    p_begin = begin(arr);
    p_end = end(arr);

    while(p_begin!=p_end)
    {
        cout << *p_begin;
        p_begin++;
    }
    cout << endl;

    // range based for loop
    auto p_begin2 = begin(arr);
    int * p_end2 = end(arr);
    // this is how the ranged based for loop is implemented internally
    // So everything you want to use the range for loop for should support begin and end function and which returns iterators that support certain operators such as !=
    for (;p_begin2!=p_end2; ++p_begin2)
    {
        auto v = *p_begin2;
    }

    // here range represents something that you loop over 
    // this notation is called a forwarding reference, that means that you can use both l and r-values (arr would be l value, {0,1,2,3} would be an l value)
    auto &&range = arr

    // in cpp17 begin and end iterator do not need to be the same type, for example in a character array, null terminated, range based for loop would not work

    /*
    Summary for vs range based
    1. range does not use index to iterate
    2. end condition is provided by the range (no danger of going outside of range)
    3. index does not need to be manually increased to decreased
    4. So regular for loop is more prone to errors
    5. for loop does give more control over the loop
    */

    // test this out with very large array
    // its probably not faster because we are using built in types for the array
    // will become important for objects
    //test_copy_vs_ref_performance();

    return 0;
}

std::vector<int> creat_random_data(int n)
{
    random_device r;
    seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    mt19937 eng(seed); // a source of random data

    uniform_int_distribution<int> dist;
    std::vector<int> v(n);

    generate(begin(v), end(v), bind(dist, eng));
    return v;
}

void test_copy_vs_ref_performance(void )
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    auto arr2 = creat_random_data(100000000);
    // using copy
    auto start = high_resolution_clock::now();
    auto start_copy_epoch = start.time_since_epoch().count();
    cout << "start time copy: " << start_copy_epoch << endl;
    for (int i: arr2)
    {
        static int prev = 0;
        prev = i*2;
    }
    auto end = high_resolution_clock::now();
    auto end_copy_epoch = end.time_since_epoch().count();
    auto epoch_copy_duration = end_copy_epoch-start_copy_epoch;
    cout << "end time copy: " << end_copy_epoch << endl;
    auto copy_duration = duration_cast<milliseconds>(end - start).count();

    // using reference
    start = high_resolution_clock::now();
    auto start_ref_epoch = start.time_since_epoch().count();
    cout << "start time reference: " << start_ref_epoch << endl;
    for (const int &i: arr2)
    {
        static int prev = 0;
        prev = i*2;
    }
    end = high_resolution_clock::now();
    auto end_ref_epoch = end.time_since_epoch().count();
    cout << "end time reference: " << end_ref_epoch << endl;
    auto epoch_ref_duration = end_ref_epoch-start_ref_epoch;
    auto reference_duration = duration_cast<milliseconds>(end - start).count();

    cout << "The time for copy took: " << copy_duration << " and for reference: " << reference_duration << " The difference is: " << copy_duration-reference_duration << endl;
    cout << "The time for copy using epoch took: " << epoch_copy_duration << " and for reference: " << epoch_ref_duration << " The difference is: " << epoch_copy_duration-epoch_ref_duration << endl;
}