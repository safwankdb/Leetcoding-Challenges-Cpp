#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i : arr)
            if (freq.count(i) == 0)
                freq[i] = 1;
            else
                freq[i]++;
        vector<int> freqVec;
        for (auto p : freq) freqVec.push_back(p.second);
        make_heap(freqVec.begin(), freqVec.end());
        int counter = 0, size = 0;
        for (; size < (arr.size() + 1) / 2; counter++) {
            size += freqVec.front();
            pop_heap(freqVec.begin(), freqVec.end());
            freqVec.pop_back();
        }
        return counter;
    }
};