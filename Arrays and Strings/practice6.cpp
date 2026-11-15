#include <iostream>

int main() {

    int arr[] = { 45, -30, 23, 0, 5, 67 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //a code to find the second largest element
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int secMax = arr[0];
    for (int i = 0; arr[i] != max; i++) {
        if ((secMax < max) && (secMax < arr[i])) {
            secMax = arr[i];
        }
    }
    std::cout << "Second largest: " << secMax << '\n';
    //a code to find total +ve, -ve & 0 elements
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos++;
        }
        else if (arr[i] < 0) {
            neg++;
        }
        else {
            zero++;
        }
    }
    std::cout << "Positive: " << pos << "\tNegative: " << neg << "\tZero: " << zero << '\n';

    return 0;
}