#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int nCr(int n, int r) {
        if (n == 0) return 1;
        r = min(r, n - r);
        long ans = 1;
        for (int i = 0; i < r; i++) ans *= n - i;
        for (int i = 0; i < r; i++) ans /= i + 1;
        return int(ans);
    }

    vector<vector<int>> generate(int numRows) {
        vector<int> tmp;
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            tmp.clear();
            for (int j = 0; j < i + 1; j++) {
                tmp.push_back(nCr(i, j));
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};