/*Array is a linear data structure, which stores same kind of data in a single variable. It stores data in memory contiguosly.
In an array only base address(address of first element) is accessible. */
#include <iostream>

int main() {

    int n1;
    std::cout << "Enter the size of array: ";
    std::cin >> n1;

    //taking array as input through traversing
    int arr1[n1];
    std::cout << "Enter " << n1 << " elements: ";
    for (int i = 0; i < n1; i++) {
        std::cin >> arr1[i];
    }

    //printing array entered by user
    std::cout << "Array you entered is: ";
    for (int i = 0; i < n1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << '\n';
    //sum of array elements
    int sum = 0;
    for (int i = 0; i < n1; i++) {
        sum += arr1[i];
    }
    std::cout << "Sum: " << sum << '\n';
    //maxm element in array
    int max = arr1[0];
    for (int i = 0; i < n1; i++) {
        if (arr1[i] > max) {
            max = arr1[i];
        }
    }
    std::cout << "Maximum: " << max << '\n';
    //count even and odd elements
    int odd = 0, even = 0;
    for (int i = 0; i < n1; i++) {
        if (arr1[i] % 2 == 0) {
            even++;
        }
        else
            odd++;
    }
    std::cout << "Odd elements: " << odd << " Even elements: " << even << '\n';
    //reverse an array 
    std::cout << "Reversed: ";
    for (int i = n1 - 1; i >= 0; i--) {
        std::cout << arr1[i] << " ";
    }
    std::cout << '\n';


    //left rotate by one element
    int n2;
    std::cout << "Enter the size of array: ";
    std::cin >> n2;
    int arr2[n2];
    std::cout << "Enter " << n2 << " elements: ";
    for (int i = 0; i < n2; i++) {
        std::cin >> arr2[i];
    }
    int temp1 = arr2[0];
    for (int i = 0; i < n2 - 1; i++) {
        arr2[i] = arr2[i + 1];
    }
    arr2[n2 - 1] = temp1;

    std::cout << "Left roated by one: ";
    for (int i = 0; i < n2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << '\n';

    //right rotate by one element
    int n3;
    std::cout << "Enter the size of array: ";
    std::cin >> n3;
    int arr3[n3];
    std::cout << "Enter " << n3 << " elements: ";
    for (int i = 0; i < n3; i++) {
        std::cin >> arr3[i];
    }
    int temp2 = arr3[n3 - 1];//1 2 3 4 5   5 1 2 3 4
    for (int i = n3 - 1; i >= 1; i--) {
        arr3[i] = arr3[i - 1];
    }
    arr3[0] = temp2;

    std::cout << "Right roated by one: ";
    for (int i = 0; i < n3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << '\n';
    return 0;
}