#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(int x, vector<int> &cost, vector<int> &dp){
        if (dp[x] >= 0) return dp[x];
        else if (x == cost.size()) dp[x] = 0;
        else if (x == cost.size() - 1) dp[x] = cost[x];
        else dp[x] = cost[x] + min(f(x+1, cost, dp), f(x+2, cost, dp));
        return dp[x];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(f(0, cost, dp), f(1, cost, dp));
    }
};