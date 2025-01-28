#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print2DVector(const vector<vector<int>>& vec) {
    // print through help of index
    // for (int i = 0; i < vec.size(); i++) {
    //     for (int j = 0; j < vec[0].size(); j++) {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // using for each loop
    for (const auto& row : vec) {
        for (const auto& col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

void waveForm(vector<vector<int>> vec) {
    int n = vec.size();
    int m = vec[0].size();
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                cout << vec[i][j] << " ";
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                cout << vec[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void spiralForm(vector<vector<int>> vec) {
    int top = 0, right = vec[0].size() - 1, bottom = vec.size() - 1, left = 0;
    while (top <= bottom && right >= left) {
        // Top
        for (int i = left; i <= right; i++) {
            cout << vec[top][i] << " ";
        }
        top++;
        // Right
        for (int i = top; i <= bottom; i++) {
            cout << vec[i][right] << " ";
        }
        right--;
        // Bottom
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << vec[bottom][i] << " ";
            }
        }
        bottom--;
        // Left
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << vec[i][left] << " ";
            }
        }
        left++;
    }
    cout << endl;
}

int main() {
    // vector<vector<int>> vec(rows, vector<int>(cols, value));
    vector<vector<int>> vec = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    // print2DVector(vec);
    // waveForm(vec);
    spiralForm(vec);
    return 0;
}
