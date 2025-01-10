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
int main() {
    int arr[6] = {10, 8, 2, 3, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);
    return 0;
}
