#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool isValid(pii u, int n, int m) {
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt_fresh = 0, cnt_rotten = 0;
        queue<pii> rotten;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) cnt_fresh++;
                else if (grid[i][j] == 2) {
                    cnt_rotten++;
                    rotten.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int turn = 0;
        while (!rotten.empty() && cnt_fresh) {
            int sz = rotten.size();
            for (int i = 0; i < sz; i++) {
                pii u = rotten.front(); rotten.pop();
                for (int k = 0; k < 4; k++) {
                    pii v = {u.fi + dx[k], u.se + dy[k]};
                    if (isValid(v, n, m) && !vis[v.fi][v.se] && grid[v.fi][v.se] == 1) {
                        rotten.push(v);
                        vis[v.fi][v.se] = 1;
                        cnt_fresh--;
                    }
                }
            }
            turn++;
        }
        return cnt_fresh ? -1 : turn;
    }
};