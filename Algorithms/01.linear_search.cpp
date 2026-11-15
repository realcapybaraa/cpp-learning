#include <iostream>

int main() {

    int arr[] = { 1, 4, 45, 67, 0, -40, 38, 99 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 67, ans = -1;
    //Linear search is a simple algorithm that sequentially checks every element in a list until the target value is found or the list ends ($O(n)$ time complexity).
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            ans = i;
            break;
        }
    }
    std::cout << "Target found at index: " << ans << '\n';
    return 0;
}