#include <bits/stdc++.h>

using namespace std;

class NumArray {
   public:
    vector<int> A, nums;

    NumArray(vector<int>& nums) {
        // A is a Fenwick Tree
        A = vector<int>(nums.size() + 1, 0);
        this->nums = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) update(i, nums[i]);
    }

    void update(int index, int val) {
        int i = index + 1, diff = val - nums[index];
        nums[index] = val;
        for (; i < A.size(); i += i - (i & (i - 1))) A[i] += diff;
    }

    int prefixSum(int n) {
        if (n == -1) return 0;
        int ans = 0;
        for (n++; n > 0 && n < A.size(); n &= (n - 1)) ans += A[n];
        return ans;
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};
