#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != s3.size()) return false;
        auto dp =  vector<vector<bool>>(n1+1, vector<bool>(n2+1, true));
        for (int i = 1; i <= n1; i++)
            dp[i][0] = (s1[i-1] == s3[i-1]) && dp[i-1][0];
        for (int j = 1; j <= n2; j++)
            dp[0][j] = (s2[j-1] == s3[j-1]) && dp[0][j-1];
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else if (s1[i-1] == s3[i+j-1])
                    dp[i][j] = dp[i-1][j];
                else if (s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = false;
        return dp[n1][n2];
    }
};