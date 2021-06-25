#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        if (maxMove == 1)
            return (startRow == 0) + (startRow == m - 1) + (startColumn == 0) +
                   (startColumn == n - 1);

        int mod = 1e9 + 7, i, j, k;
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxMove, 0)));
        for (i = 0; i < m; i++) {
            dp[i][0][0] += 1;
            dp[i][n - 1][0] += 1;
        }
        for (j = 0; j < n; j++) {
            dp[0][j][0] += 1;
            dp[m - 1][j][0] += 1;
        }
        int ans = dp[startRow][startColumn][0];
        for (k = 1; k < maxMove; k++) {
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    if (i > 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
                    if (i < m - 1)
                        dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][k - 1]) % mod;
                    if (j > 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k - 1]) % mod;
                    if (j < n - 1)
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j + 1][k - 1]) % mod;
                }
            }
            ans += dp[startRow][startColumn][k];
            ans %= mod;
        }
        return ans;
    }
};