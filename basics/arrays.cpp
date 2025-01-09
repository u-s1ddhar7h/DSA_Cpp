#include <iostream>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
// sum of an array
int arraySum(int arr[20]) {
    int sum = 0;
    for (int i = 0; i < 20; i++) {
        sum += arr[i];
    }
    return sum;
}
// average of element in an array
float arrayAvg(int arr[18]) {
    int sum = 0;
    for (int i = 0; i < 18; i++) {
        sum += arr[i];
    }
    return sum / 18.0;
}
// find an index of an element from an array
int elementAt(int arr[18], int target) {
    for (int i = 0; i < 18; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
// print 'a' to 'z' character from an array
void charArray(char chArray[26]) {
    for (int i = 0; i < 26; i++) {
        cout << chArray[i] << " ";
    }
    cout << endl;
}
// find second largest element in an array
int secondLargest(int arr[], int size) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    // find largest
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) largest = arr[i];
    }
    // find secondLargest
    for (int i = 0; i < size; i++) {
        if (arr[i] > secondLargest && arr[i] != largest) secondLargest = arr[i];
    }
    return secondLargest;
}
// find third largest element in an array
int thirdLargest(int arr[], int size) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int thirdLargest = INT_MIN;
    // find largest
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    // find secondLargest
    for (int i = 0; i < size; i++) {
        if (arr[i] > secondLargest && arr[i] != largest)
            secondLargest = arr[i];
    }
    // find thirdLargest
    for (int i = 0; i < size; i++) {
        if (arr[i] > thirdLargest && arr[i] != largest && arr[i] != secondLargest)
            thirdLargest = arr[i];
    }
    return thirdLargest;
}
int main() {
    // array-declaration
    // syntax:
    // dataType variableName[size];
    // int arr[5];

    // Array-Initialization
    // int arr1[5] = {6, 8, 5, 1, 9};

    // Skip-size during initialization
    // int arr2[] = {9, 7, 2};

    // less values
    // int arr3[5] = {8, 4};

    // Initializing the arrays with zero's 0
    // int arrZeros[5] = {0};

    // Printing arrays
    // for (int i = 0; i < 5; i++) {
    //     cout << arr1[i] << endl;
    // }

    // minimum element in array
    // int minElement = INT_MAX;
    // for (int i = 0; i < 5; i++) {
    //     if (arr1[i] < minElement) minElement = arr1[i];
    // }
    // cout << minElement << endl;

    // maximum element in array
    // int maxElement = INT_MIN;
    // for (int i = 0; i < 5; i++) {
    //     if (arr1[i] > maxElement) maxElement = arr1[i];
    // }
    // cout << maxElement << endl;

    // find size of an array
    // cout << sizeof(arr3) << endl;

    // find totalElements in an array
    // cout << sizeof(arr) / sizeof(arr[0]) << endl;

    // int arr[20];
    // for (int i = 0; i < 20; i++) {
    //     cin >> arr[i];
    // }
    // cout << "Sum of array: " << arraySum(arr) << endl;
    // int arr[18] = {0};
    // int arr[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    // cout << "Average of array: " << arrayAvg(arr) << endl;
    // cout << "Element is present at: " << elementAt(arr, 0) << endl;

    // char chArr[26];
    // for (int i = 0; i < 26; i++) {
    //     chArr[i] = 'a' + i;
    // }
    // charArray(chArr);

    int arr[6] = {12, 35, 1, 10, 34, 2};
    cout << secondLargest(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    cout << thirdLargest(arr, sizeof(arr)/sizeof(arr[0])) << endl;

    return 0;
}
