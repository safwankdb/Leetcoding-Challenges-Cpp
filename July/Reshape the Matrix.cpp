#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n) return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int t = 0; t < r * c; t++) ans[t / c][t % c] = mat[t / n][t % n];
        return ans;
    }
};