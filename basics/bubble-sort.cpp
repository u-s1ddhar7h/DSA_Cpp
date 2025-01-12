#include <iostream>
using std::cout;
using std::endl;
using std::swap;
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// function overloading ...
void bubbleSort(char arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bubbleSortDesc(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = n - 1; j >= i + 1; j--) {
            if (arr[j] > arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bubbleSortAscLastBubble(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = n - 1; j >= i + 1; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    // int arr[6] = {10, 8, 15, 71, 2, 63};
    char ch[6] = {'k', 'b', 's', 'm', 'p', 'f'};
    // int arr[5] = {1, 2, 3, 4, 5};
    // int arr[5] = {5, 4, 3, 2, 1};
    int n = sizeof(ch)/sizeof(ch[0]);
    bubbleSort(ch, n);
    return 0;
}
