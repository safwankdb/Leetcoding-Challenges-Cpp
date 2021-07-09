#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dp[1001][1001];
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        fill_n(&dp[0][0], (n1+1) * (1001), 0);
        int ans = 0;
        for(int i = 1; i <= n1; i++)
            for(int j = 1; j <= n2; j++)
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
        return ans;
    }
};