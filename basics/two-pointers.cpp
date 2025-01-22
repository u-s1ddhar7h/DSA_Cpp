#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

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

// find pair with given difference
int twoDifference(int arr[], int n, int target) {
    int start = 0, end = 1;
    while (end < n) {
        if (arr[end] - arr[start] == target)
            return 1;
        else if (arr[end] - arr[start] < target)
            end++;
        else start++;
    }
    return 0;
}

// find pair with given product
void twoProduct(int arr[], int n, int target) {
    int start = 0, end = n - 1;
    while (start < end) {
        if (arr[start] * arr[end] == target) {
            cout << "a: " << arr[start] << "\nb: " << arr[end] << endl;
            return;
        }
        else if (arr[start] * arr[end] < target)
            start++;
        else end--;
    }
    cout << "No pair found" << endl;
}

// prifix sum
vector<int> prifixSum(int arr[], int n) {
    vector<int> sum(n);
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + arr[i];
    return sum;
}

// suffix sum
vector<int> suffixSum(int arr[], int n) {
    vector<int> sum(n);
    sum[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        sum[i] = sum[i + 1] + arr[i];
    return sum;
}

void printVector(const vector<int>& vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// print all Sub-Array
void printSubArray(int arr[], int n) {
    // Use two nested loops:
    // The outer loop determines the starting index.
    // The inner loop determines the ending index.
    // For each pair of indices (i, j), print the elements from index i to j.
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

// divide array is 2-sub-array with equal sum
bool equalSumSubArray(int arr[], int n) {
    // for (int i = 0; i < n - 1; i++) {
    //     int sum1 = 0, sum2 = 0;
    //     for (int j = 0; j <= i; j++)
    //         sum1 += arr[j];
    //     for (int j = i + 1; j < n; j++)
    //         sum2 += arr[j];
    //     if (sum1 == sum2)
    //         return 1;
    // }
    int totalSum = 0, prefix = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];
    for (int i = 0; i < n - 1; i++) {
        prefix += arr[i];
        if (prefix == totalSum - prefix)
            return 1;
    }
    return 0;
}

int main() {
    int arr[] = {1, 0, 1, 0, 1, 0};
    int arr[] = {2, 7, 11, 15, 27};
    int arr[] = {1, 2, 4, 6, 18, 25};
    int arr[] = {2, 3, 5, 10, 50, 80};
    int arr[] = {3, 7, 8, 11, 25};
    int arr[] = {6, 4, 5, -3, 2, 8};
    int arr[] = {1, 2, 3, 4};
    int arr[] = {3, 4, -2, 5, 8, 20, -10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    segregateZeroOne(arr, n);
    twoSum(arr, n, 10);
    cout << twoDifference(arr, n, 45) << endl;
    twoProduct(arr, n, 56);
    vector<int> priSum = prifixSum(arr, n);
    vector<int> sufSum = suffixSum(arr, n);
    printArray(arr, n);
    printVector(priSum);
    printVector(sufSum);
    printSubArray(arr, n);
    cout << equalSumSubArray(arr, n);
    return 0;
}
