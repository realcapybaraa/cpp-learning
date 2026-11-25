#include <iostream>

void swap(int* n1, int* n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
int sum(int* arr1, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr1[i];
    }
    return sum;
}
void maxMin(int* arr, int* max, int* min, int n) {
    *max = arr[0], * min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}
void reverse(int* arr, int n) {
    int* s = arr, * e = arr + n - 1;
    while (s < e) {
        //swap
        int temp = *s;
        *s = *e;
        *e = temp;
        s++;
        e--;
    }
}
int main() {

    //a code to swap to numbers using pointer
    int n1 = 10, n2 = 20;
    std::cout << "Before swap: " << n1 << " " << n2 << "\n";

    swap(&n1, &n2);
    std::cout << "After swap: " << n1 << " " << n2 << "\n";

    //a code to find sum of array elements using pointers
    int arr1[] = { 12, 23, 42, 56, 34 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int sumValue = sum(arr1, n);
    std::cout << "Sum = " << sumValue << "\n";
    //a code to find maxm and minm element in array using pointer
    int max, min;
    maxMin(arr1, &max, &min, n);
    std::cout << "Largest element: " << max << " " << "Smallest element: " << min << "\n";
    //a code to reverse an array using pointers
    reverse(arr1, n);
    std::cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n";
    return 0;
}