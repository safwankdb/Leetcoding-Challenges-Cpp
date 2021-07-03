#include <bits/stdc++.h>

using namespace std;

class Solution {
    // max sum in array <= k
    int maxSumArray(vector<int> &sum, int k) {
        set<int> S = {0};
        int currSum = 0, maxSum = INT_MIN;
        for (int i : sum) {
            currSum += i;
            auto it = S.lower_bound(currSum - k);
            if (it != S.end())
                maxSum = max(maxSum, currSum - *it);
            S.insert(currSum);
            if (maxSum == k) return k;
        }
        return maxSum;
    }

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res, ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> sum(n, 0);
            for (int j = i; j < m; j++) {
                for (int ii = 0; ii < n; ii++)
                    sum[ii] += matrix[j][ii];
                ans = max(ans, maxSumArray(sum, k));
                if (ans == k) return k;
            }
        }
        return ans;
    }
};