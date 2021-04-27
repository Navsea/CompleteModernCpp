/*
You have different memory areas
- stack: allocated automatically for variables
- data section: allocated for global and static data
- heap: allocated at runtime 
All the memory is taken from the process address space (auto created when starting program)
Programs can support memory allocation during runtime (dynamic memory allocation)
Allocations on the heap, have to be managed by the programmer (free the memory)
Stack and data section is managed by runtime

Dynamic memory allocation
C provides various functions for allocation memory on the heap
- malloc: allocate raw memory
- calloc: allocate memory and initialize to zero
- realloc: allocates larger chunk of memory for an existing allocation (expand allocated memory)
- free: deallocates/frees up the memory, which was reserved by above functions 

Cpp provides two operators for dynamic memory allocation
- new: allocates new memory on the heap
- delete: deallocates memory on the heap
<type> * <variable> = new <type> (optional args)
delete <variable>
memory allocated with new, needs to be freed with delete
this operator can intialize memory (which C functions cannot (except calloc to zero))
it will also call the constructor if you use objects

new will return an exception when it cant allocate the memory, see exception handling
-----------------

differences c functions and new:
1. function vs operator
2. dize required vs deduced from type
3. cannot initialize vs can
4. cannot call constructors vs can
5. returns void pntr that needs to be casted vs correct pointer type
6. cannot be customized vs can be customized via operator overloading
7. malloc, calloc & realloc vs different forms of new (fe new type[] for arrays)
8. returns null vs returns exception when failed to allocate

--> always use new in cpp
*/

// these libraries are part of the c library, not cpp, thats why you need the .h
#include <stdio.h>
#include <stdlib.h> // where memory allocation functions are located
#include <string.h>
#include <iostream>

void new_f()
{
    int *p = new int(5);
    *p = 6;
    std::cout << "p contains: " << *p << std::endl;
    delete p;       // becomes dangling pointer (pointer to memory that has not been assigned)
    p = nullptr;    // now uninitialized ptr, strictly not necessary because the variable will be destroyed anyway when it exits function scope
}

void new_array()
{
    int *p = new int[5];
    for (int i=0; i<5; i++)
    {
        p[i] = i;
    }
    for (int i=0; i<5; i++)
    {
        // notice no dereferencing needed, as array elements are considered as pointers
        std::cout << "p[" << i << "] = " << p[i] << std::endl;
    }
    delete[] p;
}

void strings()
{
    // Note that we only used three characters, but you need to add one element for the string null terminating character 
    char *p_str = new char[4];
    strcpy(p_str, "C++");
    std::cout << p_str << std::endl;
}

void 2d()
{
    int *p1 = new int[3];
    int *p2 = new int[3];
    // allocate memory for a one D array of integer pointers
    int **pData = new int *[2];
    pData[0] = p1;
    pData[1] = p2;

    // pData[0] returns p1 and [1] returns second value of p1
    pData[0][1] = 2;

    // !!!!!!! free memory in the same order you allocated it !!!!!!!!
    delete[] p1; // same as delete[] pData[0]
    delete[] p2; // same as delete[] pData[1]
    delete[] pData;

    // note that the nr of new operators = nr of delete operators
}

int main()
{
    // note that malloc returns a void pointer, so you need to cast it to int pointer in cpp (not needed in c)
    int *p = (int*)malloc(sizeof(int));
    *p = 5;
    printf("%d\n", *p);
    // p is now a dangling pointer!
    free(p);
    // freeying an already freed pointer, will not compile
    //free(p);
    // after freeing, you need to assign null to the pointer
    p = nullptr;
    // does compile
    free(p);

    // use calloc to inialize the memory
    int *p2 = (int*)calloc(2, sizeof(int));
    printf("%d\n", *p2);

    // after using one of these functions, you should check the returned value, if it failed to allocated, it will return nullptr
    // to increase the amount of reserved ints, you need to multiply the sizeof with the number of elements
    int *p3 = (int*)malloc(5*sizeof(int));
    if (p3 != 0)
    {
        printf("%d\n", *p3);
    }
    else
    {
        printf("%s", "failed to allocate");
    }

    // NOTE THAT WE DID NOT FREE p2 and p3, THIS IS A MEMORY LEAK
    // it will be freed when process memory is freed
    new_f();

    // new for arrays
    int *p_array = new int[5];

    // delete for arrays delete[]
    delete[] p_array;

    new_array();

    // directly initialize values 
    int *p_array2 = new int[5]{1,2,3,4,5};

    // dont forget to allocate space for the null terminating character
    strings();

    // allocating memory for 2D array
    // not that in memory its just a single 1D array
    int data[2][3] = {
        1, 2, 3,
        4, 5, 6
    }

    return 0;
}