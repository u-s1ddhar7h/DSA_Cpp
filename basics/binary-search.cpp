#include <iostream>
using std::cout;
using std::endl;
using std::swap;
int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid =  start + (end - start) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}
int firstAndLastPos(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int first = -1, last = -1;
    // first occurrence
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            first = mid;
            end = mid - 1;
        } else if (arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    // last occurrence
    start = first != -1 ? first : 0;
    end = n - 1;
    if (first != -1) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key) {
                last = mid;
                start = mid + 1;
            } else if (arr[mid] < key) start = mid + 1;
            else end = mid - 1;
        }
    }
    return last;
}
int main() {
    int arr[10] = {2, 4, 6, 8, 10, 10, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    // cout << binarySearch(arr, n, key) << endl;
    cout << firstAndLastPos(arr, n, key) << endl;
    return 0;
}
