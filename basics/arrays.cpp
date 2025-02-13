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
// Linear Search in array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
// Reverse array
void arrReverse(int arr[], int size) {
    // int temp[size];
    // int i = size - 1, j = 0;
    // while (i >= 0) {
    //     temp[j] = arr[i];
    //     i--;
    //     j++;
    // }
    // for (int i = 0; i < size; i++) {
    //     cout << temp[i] << " ";
    // }
    int i = 0, j = size - 1;
    while (i < j) {
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return;
}
// fibonacci series using array
int fiboArray(int n) {
    int arr[1000] = {0, 1};
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n-1];
}
// Rotate array by 1 position.
void rotateArr(int arr[], int arrSize) {
    int temp = arr[arrSize - 1];
    for (int i = arrSize - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
// Rotate array 'n' times
void rotateArrNTimes(int arr[], int arrSize, int cycle) {
    int count = 1;
    while (count <= cycle) {
        int temp = arr[arrSize - 1];
        for (int i = arrSize - 2; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }
        arr[0] = temp;
        cout << "Rotation " << count << ": ";
        for (int i = 0; i < arrSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        count ++;
    }
    return;
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

    // int arr[6] = {12, 35, 1, 10, 34, 2};
    // int arr[3] = {10, 5, 10};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // cout << secondLargest(arr, size) << endl;
    // cout << thirdLargest(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    // cout << linearSearch(arr, size, 7) << endl;
    // arrReverse(arr, size);

    // cout << fiboArray(9) << endl;
    int arr[6] = {2, 7, 4, 11, 5, 8};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    rotateArr(arr, arrSize);
    rotateArrNTimes(arr, arrSize, 3);

    return 0;
}
