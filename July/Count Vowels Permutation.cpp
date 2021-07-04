#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int ways(int dp[][5], int i, int j) {
        if (i == 1) return 1;
        if (dp[i][j] != -1)  return dp[i][j];
        if (j == 0) {
            dp[i][j] = ways(dp, i-1, 1);
        } else if (j == 1) {
            dp[i][j] = (ways(dp, i-1, 0) + ways(dp, i-1, 2)) % MOD;            
        } else if (j == 2) {
            dp[i][j] = (ways(dp, i-1, 0) + ways(dp, i-1, 1)) % MOD;            
            dp[i][j] += (ways(dp, i-1, 3) + ways(dp, i-1, 4)) % MOD;        
            dp[i][j] %= MOD;
        } else if (j == 3) {
            dp[i][j] = (ways(dp, i-1, 2) + ways(dp, i-1, 4)) % MOD;            
        } else if (j == 4) {
            dp[i][j] = ways(dp, i-1, 0);
        }
        return dp[i][j];
    }
    
    int countVowelPermutation(int n) {
        int dp[n+1][5];
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < 5; i++)
            ans = (ans + ways(dp, n, i)) % MOD;
        return ans;
    }
};