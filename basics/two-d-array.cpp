#include <iostream>
#include <climits>

using std::cout;
using std::endl;

void print2DArray(int arr[][4], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int findElement(int arr[][3], int row, int col, int target) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == target)
                return 1;
        }
    }
    return 0;
}

// print row index with max sum
int rowMaxSum(int arr[][4], int row, int col) {
    int max = INT_MIN, rowIndex = -1;
    for (int i = 0; i < row; i++) {
        int rowSum = 0;
        for (int j = 0; j < col; j++) {
            rowSum += arr[i][j];
        }
        if (max < rowSum) {
            max = rowSum;
            rowIndex = i;
        }
    }
    cout << max << endl;
    return rowIndex;
}

void diagonalSum(int arr[][3]) {
    int diagonalOne = 0, diagonalTwo = 0;
    // TC:O(n^2) & SC:O(1)
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         if (i == j)
    //             diagonalOne += arr[i][j];
    //         if (i + j == col - 1)
    //             diagonalTwo += arr[i][j];
    //     }
    // }

    // TC: O(n) & SC: O(1)
    // for (int i = 0; i < 3; i++) {
    //     diagonalOne += arr[i][i];
    // }
    // int j = 2, i = 0;
    // while (j >= 0) {
    //     diagonalTwo += arr[i][j];
    //     i++;
    //     j--;
    // }

    // TC: O(n) & SC: O(1) - in single iteration
    int size = 3; // assuming a 3x3 matrix
    for (int i = 0; i < size; i++) {
        diagonalOne += arr[i][i];
        int j = size - i - 1;
        diagonalTwo += arr[i][j];
    }
    cout << "First diagonal: " << diagonalOne << endl;
    cout << "Second diagonal: " << diagonalTwo << endl;
}

// Given a matrix of size n*n, Print sum of diagonal element.
int diagonalElementSum(int arr[][4]) {
    int size = 4, diagonalSum = 0;
    for (int i = 0; i < size; i++) {
        diagonalSum += arr[i][i];
        int j = size - i - 1;
        if (j != i)
            diagonalSum += arr[i][j];
    }
    return diagonalSum;
}

void reverseRow(int arr[][4], int row, int col) {
    // TC: O(n^2)
    for (int i = 0; i < row; i++) {
        // two pointer
        int start = 0, end = col - 1;
        while (start < end) {
            std::swap(arr[i][start], arr[i][end]);
            start++, end--;
        }
    }
    print2DArray(arr, row, col);
}

int main() {
    // initialize
    // int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // int arr2[3][4] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 20, 15};
    // int ans[3][4];
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         ans[i][j] = arr1[i][j] + arr2[i][j];
    //     }
    // }
    // passing 2d array to a function.
    // print2DArray(ans, 3, 4);
    // cout << findElement(arr1, 4, 3, 17) << endl;
    // int arr[5][4] = {3, 4, 7, 18, 2, 8, 3, 9, 5, 4, 2, 2, 7, 3, 0, 8, 2, 8, 9, 1};
    // cout << rowMaxSum(arr, 5, 4) << endl;
    // int arr[4][4] = {5, 8, 3, 9, 6, 2, 8, 4, 5, 3, 2, 2, 2, 8, 1, 9};
    // diagonalSum(arr);
    // int arr[3][4] = {2, 3, 4, 5, 1, 2, 6, 8, 4, 9, 3, 2};
    // reverseRow(arr, 3, 4);
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, };
    cout << diagonalElementSum(arr) << endl;
    return 0;
}
