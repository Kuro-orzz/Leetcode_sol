#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<char>> a;
    vector<vector<int>> vis;
    vector<vector<pii>> par;
    int n, m;

    bool isValid(pii u) { return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m; }

    bool bfs(pii t) {
        vis[t.fi][t.se] = 1;
        queue<pii> q;
        q.push(t);
        par[t.fi][t.se] = t;
        while (!q.empty()) {
            pii u = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                pii v = {u.fi + dx[k], u.se + dy[k]};
                if (isValid(v) && a[v.fi][v.se] == a[u.fi][u.se]) {
                    if (vis[v.fi][v.se] && v != par[u.fi][u.se]) {
                        return true;
                    } else if (!vis[v.fi][v.se]) {
                        vis[v.fi][v.se] = 1;
                        par[v.fi][v.se] = u;
                        q.push(v);
                    }
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        this->a = grid;
        this->n = grid.size();
        this->m = grid[0].size();
        this->vis.resize(n, vector<int>(m, 0));
        this->par.resize(n, vector<pii>(m, {0, 0}));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (bfs({i, j})) return true;
                }
            }
        }
        return false;
    }
};