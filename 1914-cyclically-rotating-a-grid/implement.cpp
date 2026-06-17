#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    pii move(pii cur, int k, pii start, int _n, int _m) {
        for (int _ = 0; _ < k; _++) {
            if (cur.se == start.se && cur.fi != start.fi + _n - 1) {
                cur.fi++;
            } else if (cur.fi == start.fi + _n - 1 && cur.se != start.se + _m - 1) {
                cur.se++;
            } else if (cur.se == start.se + _m - 1 && cur.fi != start.fi) {
                cur.fi--;
            } else if (cur.fi == start.fi && cur.se != start.se) {
                cur.se--;
            }
        }
        return cur;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < min(n, m)/2; i++) {
            int num_block = (n + m - 2) * 2 - i * 8;
            int rotate = k % num_block;
            int _n = n - 2 * i, _m = m - 2 * i;
            pii start = {i, i};
            pii cur = {i, i};
            pii next = move(cur, rotate, start, _n, _m);
            ans[next.fi][next.se] = grid[cur.fi][cur.se];
            for (int i = 0; i < _n; i++) {
                for (int j = 0; j < _m; j++) {
                    if (!i && !j) continue;
                    cur = move(cur, 1, start, _n, _m);
                    next = move(next, 1, start, _n, _m);
                    ans[next.fi][next.se] = grid[cur.fi][cur.se];  
                }
            }
        }
        return ans;
    }
};