#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPath(vector<vector<int>>& grid, vector<vector<bool>> &visited, int t, int x, int y) {
        cout << t << ", " << x << ", " << y << endl;
        visited[x][y] = true;
        int n = grid.size();
        if (x == n-1 && y == n-1) return true;
        static const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int p, q;
        for (int i = 0; i < 4; i++) {
            p = x + dx[i];
            q = y + dy[i];
            if (p < 0 || p >= n || q < 0 || q >= n) continue;
            else if (grid[p][q] > t || visited[p][q]) continue;
            else if (isPath(grid, visited, t, p, q)) return true;
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int lo = max({grid[0][0], grid[n-1][n-1]});
        int hi = n*n-1, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            for (int i = 0; i < n; i++)
                fill(visited[i].begin(), visited[i].end(), false);
            if (isPath(grid, visited, mid, 0, 0)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};