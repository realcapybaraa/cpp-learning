#include <iostream>

int main() {

    //sorting in ascending order
    int arr[] = { 3, 0, 34, 20, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {//for accessing no.of iteration
        bool isSorted = false;
        for (int j = 0; j < n - 1 - i; j++) {//for accessing elements in each iteration
            //compare
            if (arr[j] > arr[j + 1]) {
                //int temp = arr[j];
                //arr[j] = arr[j + 1];
                //arr[j + 1] = temp;
                std::swap(arr[j], arr[j + 1]);
                isSorted = true;
            }
        }
        if (!isSorted) break;//to avoid unnecessary comparison, for optimization
    }
    std::cout << "Sorted in ascending order: ";
    //enhanced for loop, used when no require of index
    for (int ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << '\n';

    //sorting in descending order
    int arr1[] = { 3, 0, 34, 20, 15 };
    int n1 = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n1 - 1; i++) {//for accessing no.of iteration
        bool isSorted = false;
        for (int j = n1 - 1; j > 0 + i; j--) {//for accessing elements in each iteration
            //compare
            if (arr1[j] > arr1[j - 1]) {
                //int temp = arr[j];
                //arr[j] = arr[j + 1];
                //arr[j + 1] = temp;
                std::swap(arr1[j], arr1[j - 1]);
                isSorted = true;
            }
        }
        if (!isSorted) break;//to avoid unnecessary comparison, for optimization
    }
    std::cout << "Sorted in descending order: ";
    //enhanced for loop, used when no require of index
    for (int ele : arr1) {
        std::cout << ele << " ";
    }
    std::cout << '\n';
    return 0;
}