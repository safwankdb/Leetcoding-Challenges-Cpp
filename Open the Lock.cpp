#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    char nextNum(char a) { return ((a - '0' + 1) % 10) + '0'; }

    char prevNum(char a) { return ((a - '0' + 9) % 10) + '0'; }

    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> path;
        path["0000"] = 0;
        for (string dead : deadends) {
            if (dead == "0000") return -1;
            path[dead] = INT_MAX;
        }
        string t;
        int curr_path;
        vector<string> frontier = {"0000"}, next;
        while (!frontier.empty()) {
            next.clear();
            for (string s : frontier)
                for (int i = 0; i < 4; i++) {
                    t = s;
                    t[i] = nextNum(t[i]);
                    if (path.find(t) == path.end()) {
                        path[t] = 1 + path[s];
                        next.push_back(t);
                    }
                    t = s;
                    t[i] = prevNum(t[i]);
                    if (path.find(t) == path.end()) {
                        path[t] = 1 + path[s];
                        next.push_back(t);
                    }
                }
            frontier = next;
        }
        return (path.find(target) != path.end()) ? path[target] : -1;
    }
};