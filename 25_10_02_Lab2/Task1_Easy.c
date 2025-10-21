// find maximum element of each row in a matrix
#include <bits/stdc++.h>
using namespace std;

vector<int> maxElement(vector<vector<int>>& mat) {
    vector<int> res;
  
    for (auto& row : mat) {
        int maxVal = *max_element(row.begin(), row.end());
        res.push_back(maxVal);
    }
  
    return res;
}

int main() {
    vector<vector<int>> mat = {
        {5, 9, 3, 1},
        {1, 5, 2, 15},
        {100, 25, 99, 5},
        {3, 2, 1, 4}
    };
    vector<int> res = maxElement(mat);

    for (int x : res) {
        cout << x << "\n";
    }

    return 0;
}
