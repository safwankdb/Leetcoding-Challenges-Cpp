#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int getArea(int x, int y, vector<vector<bool>>& visited,
                vector<vector<int>>& grid) {
        if (x >= visited.size() || x < 0)
            return 0;
        else if (y >= visited[0].size() || y < 0)
            return 0;
        else if (visited[x][y])
            return 0;
        else
            visited[x][y] = true;
        if (!grid[x][y])
            return 0;
        else
            return getArea(x, y + 1, visited, grid) +
                   getArea(x, y - 1, visited, grid) +
                   getArea(x + 1, y, visited, grid) +
                   getArea(x - 1, y, visited, grid) + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                ans = max(ans, getArea(x, y, visited, grid));
        return ans;
    }
};