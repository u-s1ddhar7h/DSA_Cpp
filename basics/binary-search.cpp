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
// Insert position
int insertPosition(int arr[], int n, int target) {
    int start = 0, end = n - 1, mid;
    int index = n;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) start = mid + 1;
        else {
            index = mid;
            end = mid - 1;
        }
    }
    return index;
}
// Square Root of a number
int sqRoot(int num) {
    int start = 1, end = num, mid, ans;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (mid * mid == num) return mid;
        else if (mid * mid < num) {
            ans = mid;
            start = mid + 1;
        } else end = mid - 1;
    }
    return ans;
}
int main() {
    int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    // cout << binarySearch(arr, n, key) << endl;
    // cout << firstAndLastPos(arr, n, key) << endl;
    // cout << insertPosition(arr, n, key) << endl;
    cout << sqRoot(49) << endl;
    return 0;
}
