/*It is optimized solution for searching an element compared to linear search, as it requires lesser no.of iteration.
Note: this searching algorithm applies only in sorted array.*/
#include <iostream>

int main() {

    int arr[] = { 1, 4, 20, 45, 69, 99 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 69;
    int ans = -1;

    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (arr[m] == target) {
            ans = m;
            break;
        }
        else if (arr[m] < target) {
            s = m + 1;
        }
        else
            e = m - 1;
    }
    std::cout << "Target is at index: " << ans << '\n';
    return 0;
}