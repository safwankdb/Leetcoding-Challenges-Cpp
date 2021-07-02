#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) return {"()"};
        unordered_set<string> S;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n - i; j++)
                for (string a : generateParenthesis(j))
                    for (string b : generateParenthesis(n - i - j)) {
                        string s = string(i, '(') + a + b + string(i, ')');
                        S.insert(s);
                    }
        S.insert(string(n, '(') + string(n, ')'));
        vector<string> ans;
        for (string s : S) ans.push_back(s);
        return ans;
    }
};