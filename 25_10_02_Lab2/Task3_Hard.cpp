#include <bits/stdc++.h>
using namespace std;

int findKUtil(vector<vector<int>> &mat, int i,
    int j, int n, int m, int k) {

    if (n < 1 || m < 1)
        return -1;

    // If element is in outermost ring
    // Element is in first row
    if (k <= m)
        return mat[i][j + k - 1];

    // Element is in last column
    if (k <= (m + n - 1))
        return mat[i + (k - m)][j + m - 1];

    // Element is in last row
    if (k <= (m + n - 1 + m - 1))
        return mat[i + n - 1][j + m - 1 - (k - (m + n - 1))];

    // Element is in first column
    if (k <= (m + n - 1 + m - 1 + n - 2))
        return mat[i + n - 1 - (k - (m + n - 1 + m - 1))][j];

    return findKUtil(mat, i + 1, j + 1, n - 2, m - 2, k - (2 * n + 2 * m - 4));
}

int findK(vector<vector<int>> &mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    return findKUtil(mat, 0, 0, n, m, k);
}

int main() {
    vector<vector<int>> mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int k = 4;
    cout << findK(mat, k) << endl;
    return 0;
}
