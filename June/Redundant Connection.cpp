#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int find(vector<int> &parents, int i) {
        if (i == parents[i]) return i;
        parents[i] = find(parents, parents[i]);
        return parents[i];
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size(), p1, p2;
        vector<int> parents(n, 0);
        for (int i = 0; i < n; i++) parents[i] = i;
        for (vector<int> &edge : edges) {
            p1 = find(parents, edge[0] - 1);
            p2 = find(parents, edge[1] - 1);
            if (p1 == p2) return edge;
            parents[p2] = p1;
        }
        return {};
    }
};