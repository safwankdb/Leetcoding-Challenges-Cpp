#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    // Is there a contiguous subarray of size m with <= k zeros?
    bool check(vector<int> &lSum, int k, int m) {
        int n = lSum.size(), i, zeros;
        for (i = 0; i < n - m; i++) {
            zeros = m - (lSum[i + m] - lSum[i]);
            if (zeros <= k) return true;
        }
        return false;
    }
    
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), lo = k, hi = n, mid;
        vector<int> lSum(n+1, 0);
        for (int i = 1; i <= n; i++) 
            lSum[i] = nums[i-1] + lSum[i-1];
        while (lo + 1 < hi) {
            mid = (lo + hi) / 2;
            if (check(lSum, k, mid)) lo = mid;
            else hi = mid - 1;
        }
        return check(lSum, k, hi) ? hi : lo;
    }
};