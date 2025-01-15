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
// number of occurrence
int totalOccurrence(int arr[], int n, int target) {
    int first = -1, last = -1, start = 0, end = n - 1, mid;
    // first occurrence
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            first = mid;
            end = mid - 1;
        } else if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    // last occurrence
    start = first != -1 ? first : 0;
    end = n - 1;
    if (first != -1) {
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                last = mid;
                start = mid + 1;
            } else if (arr[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
    }
    return last - first + 1;
}
int mountainPeak(int arr[], int n) {
    int start = 0, end = n - 1;
    int peak = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1]) {
            peak = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
    return peak;
}
int kthPositiveMissing(int arr[], int n, int k) {
    int start = 0, end = n - 1;
    int ans = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] - mid - 1 >= k) {
            ans = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
    // after the above loop we get the index at which we are missing kth integers.
    return ans + k;
}
int main() {
    // int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    // int arr[5] = {2, 4, 4, 4, 5};
    // int arr[7] = {2, 4, 6, 8, 10, 8, 5};
    // int arr[3] = {0, 1, 0};
    // int arr[5] = {3, 5, 3, 2, 0};
    int arr[6] = {2, 3, 4, 7, 11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    // cout << binarySearch(arr, n, key) << endl;
    // cout << firstAndLastPos(arr, n, key) << endl;
    // cout << insertPosition(arr, n, key) << endl;
    // cout << sqRoot(49) << endl;
    // cout << totalOccurrence(arr, n, key) << endl;
    // cout << mountainPeak(arr, n) << endl;
    cout << kthPositiveMissing(arr, n, key) << endl;
    return 0;
}
