#include <iostream>
using std::cout;
using std::endl;
using std::swap;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void printArray(char arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else break;
        }
    }
    printArray(arr, n);
}
void insertionSort(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else break;
        }
    }
    printArray(arr, n);
}
void insertionSortDesc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] > arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else break;
        }
    }
    printArray(arr, n);
}
void insertionSortAscLast(int arr[], int n) {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j < n - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            else break;
        }
    }
    printArray(arr, n);
}
int main() {
    int arr[6] = {6, 5, 4, 3, 2, 1};
    char ch[6] = {'v', 'l', 'k', 'h', 'e', 'a'};
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(ch) / sizeof(ch[0]);
    insertionSortAscLast(arr, n);
    insertionSort(ch, n);
    return 0;
}
