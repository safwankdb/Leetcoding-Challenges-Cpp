#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool dfs(vector<int> &ans, bool visit[], int n) {
        int x = ans.back(), y, mask = 1;
        visit[x] = true;
        for (int i = 0; i < n; i++) {
            y = x ^ mask;
            if (!visit[y]) {
                ans.push_back(y);
                dfs(ans, visit, n);
                break;
            }
            mask <<= 1;
        }
        return true;
    }

    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        bool visit[1 << n];
        memset(visit, false, sizeof(visit));
        dfs(ans, visit, n);
        return ans;
    }
};