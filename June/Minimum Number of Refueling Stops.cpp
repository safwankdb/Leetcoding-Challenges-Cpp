#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int f(int sf, vector<vector<int>> &st, int i) {
        if (sf < 0) {
            return -1;
        } else if (i == st.size() - 1) {
            return 0;
        } else {
            int refuel = f(sf + st[i][1] - st[i + 1][0] + st[i][0], st, i + 1);
            int noRefuel = f(sf - st[i + 1][0] + st[i][0], st, i + 1);
            if (refuel >= 0 && noRefuel >= 0) {
                return min(1 + refuel, noRefuel);
            } else if (refuel >= 0) {
                return 1 + refuel;
            } else {
                return -1;
            }
        }
    }

    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>> &stations) {
        stations.push_back({target, 0});
        return f(startFuel - stations[0][0], stations, 0);
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> v = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int ans = s->minRefuelStops(100, 10, v);
    cout << ans << endl;
}
