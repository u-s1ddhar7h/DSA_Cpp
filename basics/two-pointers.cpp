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

int main() {
    int arr[] = {1, 0, 1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    segregateZeroOne(arr, n);
    return 0;
}
