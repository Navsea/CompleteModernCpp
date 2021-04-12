//Try to modify x1 & x2 and see the compilation output
int x = 5 ;
const int MAX = 12 ;
int &ref_x1 = x ;
const int &ref_x2 = x ;
 
//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
const int *ptr1 = &x ;
int *const ptr2 = &x ;
const int * const ptr3 = &x ;
 
//Find which declarations are valid. If invalid, correct the declaration
//const int *ptr3 = &MAX ; //declared ptr3 already as cst pointer, so you cannot declare it again
const int *ptr4 = &MAX; // this works
//int *ptr4 = &MAX ; // not allowed, ptr is not pointing to const int
 
const int &r1 = ref_x1 ; // that is fine, you wont be able to change the value via r1
//int &r2 = ref_x2 ; // wont work, cst int reference is being assigned to non const ref
 
// int *&p_ref1 = ptr1 ; // wont work, trying to dereference a reference
// const int*&p_ref2 = ptr2 ; // same


int main()
{
    ref_x1 = 5; //works fine
    //ref_x2 = 6; // build error

    //*ptr1 = 6; // compiler error
    ptr1 = ptr2; //works fine

    return 0;
}