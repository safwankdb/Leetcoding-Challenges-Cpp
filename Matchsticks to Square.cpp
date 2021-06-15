#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& m, int l[], const long& s, int x){
        int i;
        if (x == m.size()) {
            for (i = 0; i < 4; i++)
                if (l[i] != s) return false;
            return true;
        }
        for (i = 0; i < 4; i++)
            if (l[i] > s) return false;
        for (i = 0; i < 4; i++) {
            l[i] += m[x];
            if (check(m, l, s, x+1)) return true;
            l[i] -= m[x];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        long sumSides = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sumSides % 4 != 0) return false;
        const long side = sumSides / 4;
        int n = matchsticks.size();
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int l[] = {0, 0, 0, 0};
        return check(matchsticks, l, side, 0);
    }
};