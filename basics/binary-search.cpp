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
int bookAllocation(int arr[], int n, int m) {
    int start = -1, end = 0, ans = 0;
    // find max-element and total-sum
    for (int i = 0; i < n; i++) {
        start = std::max(start, arr[i]);
        end += arr[i];
    }
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int page = 0, studCount = 1;
        for (int i = 0; i < n; i++) {
            page += arr[i];
            if (page > mid) {
                studCount++;
                page = arr[i];
            }
        }
        if (studCount <= m) {
            ans = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
    return ans;
}
int painterProblem(int arr[], int n, int k) {
    int start = -1, end = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > start)
            start = arr[i];
        end += arr[i];
    }
    int ans = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int walls = 0, painter = 1;
        for (int i = 0; i < n; i++) {
            walls += arr[i];
            if (walls > mid) {
                painter++;
                walls = arr[i];
            }
        }
        if (painter <= k) {
            ans = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
    return ans;
}
int shipPackages(int arr[], int n, int d) {
    // find the max-element and sum of array
    int start = -1, end = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > start)
            start = arr[i];
        end += arr[i];
    }
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int weight = 0, day = 1;
        for (int i = 0; i < n; i++) {
            weight += arr[i];
            if (weight > mid) {
                day++;
                weight = arr[i];
            }
        }
        if (day <= d) {
            ans = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
    return ans;
}
int main() {
    // int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    // int arr[5] = {2, 4, 4, 4, 5};
    // int arr[7] = {2, 4, 6, 8, 10, 8, 5};
    // int arr[3] = {0, 1, 0};
    // int arr[5] = {3, 5, 3, 2, 0};
    // int arr[6] = {2, 3, 4, 7, 11, 12};
    // int arr[4] = {12, 34, 67, 90};
    // int arr[5] = {5, 10, 30, 20, 15};
    // int arr[6] = {3, 2, 2, 4, 1, 4};
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    // cout << binarySearch(arr, n, key) << endl;
    // cout << firstAndLastPos(arr, n, key) << endl;
    // cout << insertPosition(arr, n, key) << endl;
    // cout << sqRoot(49) << endl;
    // cout << totalOccurrence(arr, n, key) << endl;
    // cout << mountainPeak(arr, n) << endl;
    // cout << kthPositiveMissing(arr, n, key) << endl;
    // cout << bookAllocation(arr, n, 2) << endl;
    // cout << painterProblem(arr, n, 3) << endl;
    cout << shipPackages(arr, n, 5) << endl;
    return 0;
}
