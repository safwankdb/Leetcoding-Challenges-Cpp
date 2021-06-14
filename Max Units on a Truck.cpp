#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; });
        int currSize = 0, ans = 0;
        for (auto box : boxTypes) {
            int numBox = min(box[0], truckSize - currSize);
            ans += box[1] * numBox;
            currSize += numBox;
            if (currSize > truckSize) break;
        }
        return ans;
    }
};