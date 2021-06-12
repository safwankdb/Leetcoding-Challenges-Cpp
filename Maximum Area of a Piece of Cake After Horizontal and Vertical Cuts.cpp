#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxArea(int h, int w, vector<int>& horizontalCuts,
                vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mh = horizontalCuts[0], mv = verticalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++)
            mh = max(mh, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < verticalCuts.size(); i++)
            mv = max(mv, verticalCuts[i] - verticalCuts[i - 1]);
        mh = max(mh, h - horizontalCuts.back());
        mv = max(mv, w - verticalCuts.back());
        return (long(mh) * mv) % 1000000007;
    }
};