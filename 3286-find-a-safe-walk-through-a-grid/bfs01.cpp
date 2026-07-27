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

    int bfs01(vector<vector<int>> &grid, int n, int m) {
        deque<pii> q;
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        q.push_front({0, 0});
        d[0][0] = grid[0][0];
        while (!q.empty()) {
            pii u = q.front(); q.pop_front();
            for (int i = 0; i < 4; i++) {
                pii v = {u.fi + dx[i] ,u.se + dy[i]};
                if (!isValid(v, n, m)) continue;
                int w = grid[v.fi][v.se];
                if (w + d[u.fi][u.se] < d[v.fi][v.se]) {
                    d[v.fi][v.se] = w + d[u.fi][u.se];
                    if (!w) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
        return d[n-1][m-1];
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int d = bfs01(grid, n, m);
        return d < health;
    }
};