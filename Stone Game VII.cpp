#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int f(int x, int y, vector<int>& stones, vector<vector<int>>& dp){
        if (dp[x][y] >= 0) return dp[x][y];
        else if (x == y) dp[x][y] = 0;
        else if (x == y - 1) dp[x][y] = max(stones[x], stones[y]);
        else {
            int l = min(stones[x+1] + f(x+2, y, stones, dp), stones[y] + f(x+1, y-1, stones, dp));
            int r = min(stones[y-1] + f(x, y-2, stones, dp), stones[x] + f(x+1, y-1, stones, dp));
            dp[x][y] = max(l, r);
        }
        return dp[x][y];
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, stones, dp);
    }
};