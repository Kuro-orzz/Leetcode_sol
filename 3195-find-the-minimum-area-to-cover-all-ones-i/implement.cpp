#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pii mn = {1e9, 1e9}, mx = {0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) continue;
                mn.fi = min(mn.fi, i);
                mn.se = min(mn.se, j);
                mx.fi = max(mx.fi, i);
                mx.se = max(mx.se, j);
            }
        }
        return (mx.fi - mn.fi + 1) * (mx.se - mn.se + 1);
    }
};