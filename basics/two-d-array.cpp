#include <iostream>

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



int main() {

    // initialize
    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[3][4] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 20, 15};
    int ans[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            ans[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    // passing 2d array to a function.
    print2DArray(ans, 3, 4);

    cout << findElement(arr1, 4, 3, 17) << endl;

    return 0;
}
