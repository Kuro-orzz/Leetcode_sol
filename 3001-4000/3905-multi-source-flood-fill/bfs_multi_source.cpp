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
    
    void bfs(vector<vector<int>> &grid, int n, int m) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            map<pii, int> mp;
            for (int i = 0; i < sz; i++) {
                pii u = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    pii v = {u.fi + dx[k], u.se + dy[k]};
                    if (isValid(v, n, m) && !vis[v.fi][v.se]) {
                        mp[v] = grid[u.fi][u.se];
                        vis[v.fi][v.se] = 1;
                        q.push(v);
                    } else if (mp.count(v)) {
                        mp[v] = max(mp[v], grid[u.fi][u.se]);
                    }
                }
            }
            for (auto &it : mp) {
                grid[it.fi.fi][it.fi.se] = it.se; 
            }
        }
    }
    
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < sources.size(); i++) {
            int r = sources[i][0];
            int c = sources[i][1];
            int color = sources[i][2];
            grid[r][c] = color;
        }
        bfs(grid, n, m);
        return grid;
    }
};