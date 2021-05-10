#include <iostream>
#include <string>

template<typename T> 
T add(T a, T b) {
    return a + b;
}

template<typename T>
T array_sum(T* p, int size) {
    T sum{0};
    for(int i = 0; i < size; ++i) {
        sum += *(p+i);
    }
    return sum;
}

template<typename T>
T max(T* p, int size) {
    T max{};
    for(int i = 0; i < size; i++) {
        // init max to first element (cant use zero as negative values are also possible)
        if (i == 0) { max = p[i]; }
        max = max < p[i] ? p[i]:max;
    }
    return max;
} 

template<typename T>
std::pair<T,T> min_max(T* p, int size) {
    T min{}, max{};
    for(int i = 0; i < size; i++) {
        if(i == 0) { min = max = p[i]; }
        min = min > p[i] ? p[i] : min;
        max = max < p[i] ? p[i] : max;
    }
    return std::pair<T,T>{min,max};
}

// now instead of pointers use references to arrays and non-type template arguments
template<typename T, int size>
std::pair<T,T> min_max_ref(T (&ref)[size]) {
    T min{}, max{};
    for(int i = 0; i < size; i++) {
        if(i == 0) { min = max = ref[i]; }
        min = min > ref[i] ? ref[i] : min;
        max = max < ref[i] ? ref[i] : max;
    }
    return std::pair<T,T>{min,max};
} 

// specialization for const char *, needed cause you dont want to compare the addresses
template<int size>
std::pair<const char *,const char *> min_max_ref( const char *(&ref)[size]) {
    char min{}, max{};
    for(int i = 0; i < size; i++) {
        if(i == 0) { min = max = ref[i]; }
        min = min > ref[i] ? ref[i] : min;
        max = max < ref[i] ? ref[i] : max;
    }
    return std::pair<const char *, const char *>{min,max};
} 

// specialization for std::string
template<int size>
std::pair<std::string,std::string> min_max_ref(std::string (&ref)[size]) {
    std::string min{}, max{};
    for(int i = 0; i < size; i++) {
        if(i == 0) { min = max = ref[i]; }
        min = min > ref[i] ? ref[i] : min;
        max = max < ref[i] ? ref[i] : max;
    }
    return std::pair<std::string,std::string>{min,max};
} 


int main() {
    int x{5}, y{4};
    int result = add(x, y);
    std::cout << "Result of add int is: " << result << std::endl;

    float a{1.2f}, b{3.4f};
    float res = add(a, b);
    std::cout << "Result of add float is: " << res << std::endl;

    int arr[]{1,2,3,4,5};
    int size{5};
    std::cout << "Result of array_sum int is: " << array_sum(arr, size) << std::endl;

    float arr2[]{1.2f,2.5f,3.6f,4.1f,5.9f};
    std::cout << "Result of array_sum float is: " << array_sum(arr, size) << std::endl;

    std::cout << "Result of max int is: " << max(arr, size) << std::endl;
    std::cout << "Result of max float is: " << max(arr2, size) << std::endl;

    std::pair res3 = min_max(arr, size);
    std::cout << "Result of min_max int is: (" << res3.first << ", " << res3.second << ")" << std::endl;
    std::pair res4 = min_max(arr2, size);
    std::cout << "Result of min_max float is: (" << res4.first << ", " << res4.second << ")" << std::endl;

    // does this mean that for every size of arr2 a diferent function is created?
    std::pair res5 = min_max_ref(arr2);
    std::cout << "Result of min_max_ref float is: (" << res5.first << ", " << res5.second << ")" << std::endl;

    float arr3[]{'c','b','a','d','e'};
    // specialization needed as otherwise the pointer addresses would be compared
    std::pair res6 = min_max_ref(arr3);
    std::cout << "Result of min_max_ref const char * is: (" << res6.first << ", " << res6.second << ")" << std::endl;

    std::string arr4[]{"Hello", "How", "Will", "This", "Work"};
    std::pair res7 = min_max_ref(arr4);
    std::cout << "Result of min_max_ref const char * is: (" << res7.first << ", " << res7.second << ")" << std::endl;
}