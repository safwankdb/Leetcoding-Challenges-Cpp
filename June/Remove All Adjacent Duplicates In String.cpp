#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string removeDuplicates(string s) {
        string ans;
        stack<char> S;
        for (char c : s)
            if (S.empty())
                S.push(c);
            else if (c == S.top())
                S.pop();
            else
                S.push(c);
        for (; !S.empty(); S.pop()) ans += S.top();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};