/*Pointer is a special type of variable that stores address of another variable of same kind. */
#include <iostream>

void solve(int* num) {
    *num = 20;
}
int* getAddr(int* num) {
    return num;
}
void multipleReturn(int* sum, int* diff, int* prod, int x1, int x2) {
    *sum = x1 + x2;
    *diff = x1 - x2;
    *prod = x1 * x2;
}
void printValue(void* ptr) {
    // Cast void* back to int* before dereferencing
    std::cout << *static_cast<int*>(ptr) << '\n';
}
int main() {

    int x = 10;
    int* ptr = &x;

    std::cout << ptr << "\n";
    std::cout << &x << "\n";//address of operator
    std::cout << *ptr << "\n";//value pointed by operator(dereferencing operator)
    std::cout << *&ptr << "\n";//* and & cancels each others

    //learn pointer arithmetic
    (*ptr)++;//pointer increment
    std::cout << *ptr << "\n";
    (*ptr)--;//pointer decrement
    std::cout << *ptr << "\n";
    std::cout << *ptr + *ptr << "\n";
    std::cout << *ptr - *ptr << "\n";
    //comparing pointers
    int n1 = 10, n2 = 20;
    int* ptr1 = &n1, * ptr2 = &n2;
    std::cout << (*ptr1 == *ptr2) << "\n";
    //size of pointer is alz 8 for 64bit, and 4 for 32bit architecture
    std::cout << sizeof(ptr1) << "\n";

    //pointer and functions
    int num = 10;
    solve(&num);//this ic pass by reference
    std::cout << num << "\n";

    int* addr = getAddr(&num);//returning pointer from function
    std::cout << *addr << "\n";

    int x1 = 10, x2 = 5;
    int sum = 0, diff = 0, prod = 0;
    multipleReturn(&sum, &diff, &prod, x1, x2);
    std::cout << "Sum: " << sum << " " << "Difference: " << diff << " " << "Product: " << prod << "\n";

    //pointer and arrays
    int arr[] = { 23, 12, 42, 16, 57 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int* ptr3 = &arr[1];
    std::cout << *ptr3 << "\n";

    int* ptr4 = arr;//array name is already a base address
    for (int i = 0; i < arrSize; i++) {//array traversal using pointer
        std::cout << *(ptr4 + i) << " ";
    }
    std::cout << "\n";

    //advanced pointer
    int* ptr5 = NULL;//null pointer with constant value 0
    std::cout << ptr5 << "\n";

    int num1 = 20;
    void* vPtr = &num1;//A void pointer (void*) can hold the memory address of any data type and is commonly passed to a void function (returns nothing) to handle generic data after casting it back to its original type. but it may cause undefined behavior hence it is not recommended to use.
    printValue(vPtr);

    int num2 = 30;
    int* ptr6 = &num2;
    int** ptr7 = &ptr6;//double pointer which stores address of another point
    std::cout << **ptr7 << "\n";
    std::cout << (**ptr7) * 10 - 100 << "\n";
    return 0;
}