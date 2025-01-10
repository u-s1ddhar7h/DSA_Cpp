#include <iostream>
#include <climits>
using std::cout;
using std::endl;
void selection_sort(int arr[], int n) {
    // find min element index
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[index])
                index = j;
        }
        std::swap(arr[i], arr[index]);
    }
    // print the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}
void selection_sort_desc(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int index = i;
        // find max element index
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[index])
                index = j;
        }
        std::swap(arr[i], arr[index]);
    }
    // print the desc sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}
void selectSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // find max element index
        int index = n - i - 1;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[index])
                index = j;
        }
        std::swap(arr[n - i - 1], arr[index]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}
void selectSortCharacter(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[index])
                index = j;
        }
        std::swap(arr[i], arr[index]);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
int main() {
    // int arr[6] = {8, 4, 1, 10, 15, 5};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // selection_sort(arr, size);
    // selection_sort_desc(arr, size);
    // selectSort(arr, size);

    char ch[7] = {'d', 'c', 'a', 'f', 'z', 'x', 't'};
    int n = sizeof(ch)/sizeof(ch[0]);
    selectSortCharacter(ch, n);
    return 0;
}
