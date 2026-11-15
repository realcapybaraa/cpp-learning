#include <iostream>

int main() {

    int n1;
    std::cout << "Enter the number of array elements: ";
    std::cin >> n1;

    int arr1[n1];
    std::cout << "Enter " << n1 << " elements: ";
    for (int i = 0; i < n1; i++) {
        std::cin >> arr1[i];
    }
    //a code to check if array is sorted
    bool isSorted = true;
    for (int i = 0; i < n1 - 1; i++) {
        if (arr1[i + 1] < arr1[i]) {
            isSorted = false;
            break;
        }
    }
    std::cout << ((isSorted == true) ? "Sorted\n" : "Not sorted\n");
    //a code to reverse an array using two pointer algorithm
    int s = 0, e = n1 - 1;
    while (s < e) {
        //swap
        int temp = arr1[s];
        arr1[s] = arr1[e];
        arr1[e] = temp;
        s++;
        e--;
    }
    std::cout << "Reversed: ";
    for (int i = 0; i < n1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << '\n';

    //a code to left rotate by k element
    int n2, k;
    std::cout << "Enter the number of array elements: ";
    std::cin >> n2;

    int arr2[n2];
    std::cout << "Enter " << n2 << " elements: ";
    for (int i = 0; i < n2; i++) {
        std::cin >> arr2[i];
    }
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    k = k % n2;//handle cases where k is grater than n
    int temp[k];//temporary array to store first rotating elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr2[i];
    }
    for (int i = 0; i < n2 - k; i++) {
        arr2[i] = arr2[i + k];
    }
    for (int i = 0; i < k; i++) {
        arr2[n2 - k + i] = temp[i];
    }

    std::cout << "Left roated by k: ";
    for (int i = 0; i < n2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << '\n';
    //count subarray sum equals target
    int target, count = 0;
    std::cout << "Enter the target: ";
    std::cin >> target;
    for (int i = 0; i < n2; i++) {
        int sum = 0;
        for (int j = i; j < n2; j++) {
            sum += arr2[j];
            if (sum == target) {
                count++;
            }
        }
    }
    std::cout << "No.of subarray sum that equals target: " << count << '\n';
    return 0;
}