/*
  In C++, memory used by a program includes regions like the Stack (automatic/local
  variables) and the Heap (dynamic memory).
  - Stack variables are managed automatically and destroyed when they go out of scope.
  - Heap memory is allocated dynamically with 'new'/'new[]' and must be freed
    manually with 'delete'/'delete[]' (or managed via smart pointers).
  - Memory leak: Heap memory allocated with new/new[] that is never freed with delete/delete[], leaving it unusable until the program exits.
*/
#include <iostream>

int main() {

    //int x = 10;//stores in Stack by default
    //allocate variable on the Heap
    int* ptr = new int(10);//stores in Heap we can access its address only in return
    std::cout << *ptr << "\n";
    //free the memory manually
    delete ptr;//deletes the value from Heap but still ptr itself is not deleted
    //std::cout << *ptr << "\n";//undefined behaviour
    ptr = nullptr;// Reset 'ptr' to nullptr so it no longer dangles
    //using null-check to accress values without any undefined behaviour
    if (ptr != nullptr) {
        std::cout << *ptr << "\n";
    }

    // Allocates an array of 10 ints on the Heap (size can be a runtime variable, unlike fixed stack arrays)
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {//using the array
        arr[i] = i * 10;
    }
    std::cout << arr[2] << "\n";
    //free the memory manually
    delete[] arr;//deletes the array
    arr = nullptr;//Prevent dangling pointer bugs
    return 0;
}