#include <iostream>
#include <vector>
#include <climits>

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

// largest sum contiguous subarray
int largestSumSubArray(int arr[], int n) {
    // Prefix Sum : O(N^2)
    // int maxi = INT_MIN;
    // for (int i = 0; i < n; i++) {
    //     int prefix = 0;
    //     for (int j = i; j < n; j++) {
    //         prefix += arr[j];
    //         maxi = std::max(prefix, maxi);
    //     }
    // }

    // Kadane's Algorithm : O(N)
    int maxi = INT_MIN, prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        maxi = std::max(prefix, maxi);
        if (prefix < 0)
            prefix = 0;
    }
    return maxi;
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

// Max difference b/w 2 element
int maxDiff2Element(int arr[], int n) {
    // Brute Force: O(n^2) & O(1)
    int ans = INT_MIN;
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[j] > arr[i]) {
    //             int diff = arr[j] - arr[i];
    //             ans = std::max(ans, diff);
    //         }
    //     }
    // }

    // Suffix Max : O(n) & O(n)
    // vector<int> suffixMax(n);
    // suffixMax[n - 1] = arr[n - 1];
    // for (int i = n - 2; i >= 0; i--)
    //     suffixMax[i] = std::max(arr[i], suffixMax[i + 1]);
    // for (int i = n - 2; i >= 0 ; i--) {
    //     int diff = suffixMax[i + 1] - arr[i];
    //     ans = std::max(ans, diff);
    // }

    // Time-Complexity: O(n) & Space-Complexity: O(1)
    int suffixMax = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixMax = std::max(suffixMax, arr[i + 1]);
        int diff = suffixMax - arr[i];
        ans = std::max(ans, diff);
    }
    return ans;
}

// Trapping Rain Water
int trapWater(int arr[], int n) {
    // Time-Complexity: O(n) & Space-Complexity: O(1)
    int trapped = 0, tallestIndex = 0;
    int leftMax = arr[0], rightMax = arr[n - 1];
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[tallestIndex])
            tallestIndex = i;
    }
    for (int i = 1; i < tallestIndex; i++) {
        if (leftMax > arr[i])
            trapped += leftMax - arr[i];
        else
            leftMax = arr[i];
    }
    for (int i = n - 2; i > tallestIndex; i--) {
        if (rightMax > arr[i])
            trapped += rightMax - arr[i];
        else
            rightMax = arr[i];
    }
    return trapped;
}

// Three sum
bool threeSum(int arr[], int n, int target) {
    // Time-Complexity: O(n^3) & Space-Complexity: O(1)
    // for (int i = 0; i < n - 2; i++) {
    //     for (int j = i + 1; j < n - 2; j++) {
    //         for (int k = j + 1; k < n; k++) {
    //             if (arr[i] + arr[j] + arr[k] == target)
    //                 return 1;
    //         }
    //     }
    // }

    // Binary-Search: O(n^2 log n) & Space-Complexity: O(1)
    // before applying binary-search, we need to sort the array first
    // insertion-sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
        }
    }
    // for (int i = 0; i < n - 2; i++) {
    //     for (int j = i + 1; j < n - 1; j++) {
    //         int search = target - (arr[i] + arr[j]);
    //         int start = j + 1, end = n - 1;
    //         while (start <= end) {
    //             int mid = start + (end - start) / 2;
    //             if (arr[mid] == search)
    //                 return 1;
    //             else if (arr[mid] < search)
    //                 start = mid + 1;
    //             else
    //                 end = mid - 1;
    //         }
    //     }
    // }

    // Two-Pointers: O(n^2) & Space-Complexity: O(1)
    for (int i = 0; i < n - 2; i++) {
        int twoSum = target - arr[i];
        int start = i + 1, end = n - 1;
        while (start < end) {
            if (arr[start] + arr[end] == twoSum)
                return 1;
            else if (arr[start] + arr[end] < twoSum)
                start++;
            else end--;
        }
    }
    return 0;
}

//
int find4Numbers(int arr[], int n, int target) {
    // Time-Complexity: O(n^4) & Space-Complexity: O(1)
    // for (int a = 0; a < n - 3; a++) {
    //     for (int b = a + 1; b < n - 2; b++) {
    //         for (int c = b + 1; c < n - 1; c++) {
    //             for (int d = c + 1; d < n; d++) {
    //                 if (arr[a] + arr[b] + arr[c] + arr[d] == target)
    //                     return 1;
    //             }
    //         }
    //     }
    // }

    // Binary-Search: O(n^3 log n) & Space-Complexity: O(1)
    // insertion-sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
        }
    }
    // for (int a = 0; a < n - 3; a++) {
    //     for (int b = a + 1; b < n - 2; b++) {
    //         for (int c = b + 1; c < n - 1; c++) {
    //             int search = target - arr[a] - arr[b] - arr[c];
    //             int start = c + 1, end = n - 1;
    //             while (start <= end) {
    //                 int mid = start + (end - start) / 2;
    //                 if (arr[mid] == search)
    //                     return 1;
    //                 else if (arr[mid] < search)
    //                     start = mid + 1;
    //                 else
    //                     end = mid - 1;
    //             }
    //         }
    //     }
    // }

    // Two-Pointer: O(n^3) & Space-Complexity: O(1)
    for (int a = 0; a < n - 3; a++) {
        for (int b = a + 1; b < n - 2; b++) {
            int twoSum = target - arr[a] - arr[b];
            int start = b + 1, end = n - 1;
            while (start < end) {
                if (arr[start] + arr[end] == twoSum)
                    return 1;
                else if (arr[start] + arr[end] < twoSum)
                    start++;
                else
                    end--;
            }
        }
    }
    return 0;
}

// Remove Element from Vector
void removeElement(vector<int> &A, int B) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B) {
            A.erase(A.begin() + i);
            i--;
        }
    }
    cout << A.size() << endl;
    printVector(A);
}

int main() {
    // int arr[] = {1, 0, 1, 0, 1, 0};
    // int arr[] = {2, 7, 11, 15, 27};
    // int arr[] = {1, 2, 4, 6, 18, 25};
    // int arr[] = {2, 3, 5, 10, 50, 80};
    // int arr[] = {3, 7, 8, 11, 25};
    // int arr[] = {6, 4, 5, -3, 2, 8};
    // int arr[] = {1, 2, 3, 4};
    // int arr[] = {3, 4, -2, 5, 8, 20, -10, 8};
    // int arr[] = {3, 4, -5, 8, -12, 7, 6, -2};
    // int arr[] = {4, -6, 2, 8};
    // int arr[] = {9, 5, 8, 12, 2, 3, 7, 4};
    // int arr[] = {4, 2, 0, 5, 2, 6, 2, 3};
    // int arr[] = {1, 4, 45, 6, 10, 8};
    // int arr[] = {1, 5, 1, 0, 6, 0};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // segregateZeroOne(arr, n);
    // twoSum(arr, n, 10);
    // cout << twoDifference(arr, n, 45) << endl;
    // twoProduct(arr, n, 56);
    // vector<int> priSum = prifixSum(arr, n);
    // vector<int> sufSum = suffixSum(arr, n);
    // printArray(arr, n);
    // printVector(priSum);
    // printVector(sufSum);
    // printSubArray(arr, n);
    // cout << equalSumSubArray(arr, n);
    // cout << largestSumSubArray(arr, n) << endl;
    // cout << maxDiff2Element(arr, n) << endl;
    // cout << trapWater(arr, n) << endl;
    // cout << threeSum(arr, n, 59) << endl;
    // cout << find4Numbers(arr, n, 7) << endl;
    // vector<int> A = {4, 1, 1, 2, 1, 3};
    vector<int> A = {1, 1, 2, 4, 8};
    removeElement(A, 1);
    return 0;
}
