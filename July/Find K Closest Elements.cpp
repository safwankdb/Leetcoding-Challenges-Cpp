#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto C = [x](const int a, const int b) {
            if (abs(a - x) != abs(b - x)) return abs(a - x) > abs(b - x);
            return a > b;
        };
        make_heap(arr.begin(), arr.end(), C);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            pop_heap(arr.begin(), arr.end(), C);
            ans.push_back(arr.back());
            arr.pop_back();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};