#include <iostream>

using std::cout;
using std::endl;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void segregateZeroOne(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        if (arr[start] == 0)
            start++;
        else {
            if (arr[end] == 0) {
                std::swap(arr[start], arr[end]);
                start++, end--;
            } else end--;
        }
    }
    printArray(arr, n);
}

void twoSum(int arr[], int n, int target) {
    // O(N^2): Brute force approach
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[i] + arr[j] == target) {
    //             cout << "a = " << arr[i] << "\nb = " << arr[j] << endl;
    //             return;
    //         }
    //     }
    // }

    // O(NlogN): binary search approach
    // for (int i = 0; i < n - 1; i++) {
    //     int x = target - arr[i];
    //     int start = i + 1, end = n - 1;
    //     while (start <= end) {
    //         int mid = start + (end - start) / 2;
    //         if (arr[mid] == x) {
    //             cout << "a = " << arr[i] << "\nb = " << arr[mid] << endl;
    //             return;
    //         } else if (arr[mid] < x) start = mid + 1;
    //         else end = mid - 1;
    //     }
    // }

    // O(N): tow pointer approach
    int start = 0, end = n - 1;
    while (start < end) {
        if (arr[start] + arr[end] == target) {
            cout << "a: " << arr[start] << "\nb: " << arr[end] << endl;
            break;
        }
        else if (arr[start] + arr[end] < target) start++;
        else end--;
    }
}

int main() {
    int arr[] = {1, 0, 1, 0, 1, 0};
    int arr[] = {2, 7, 11, 15, 27};
    int arr[] = {1, 2, 4, 6, 18, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    segregateZeroOne(arr, n);
    twoSum(arr, n, 10);
    return 0;
}
