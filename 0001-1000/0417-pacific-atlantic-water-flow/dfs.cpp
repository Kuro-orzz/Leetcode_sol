#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<int>> h, vis1, vis2;

    bool isValid(pii u) {
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    void dfs1(pii u) {
        vis1[u.fi][u.se] = 1;
        for (int k = 0; k < 4; k++) {
            pii v = {u.fi + dx[k], u.se + dy[k]};
            if (!isValid(v) || vis1[v.fi][v.se]) continue;
            if (h[v.fi][v.se] >= h[u.fi][u.se]) dfs1(v);
        }
    }

    void dfs2(pii u) {
        vis2[u.fi][u.se] = 1;
        for (int k = 0; k < 4; k++) {
            pii v = {u.fi + dx[k], u.se + dy[k]};
            if (!isValid(v) || vis2[v.fi][v.se]) continue;
            if (h[v.fi][v.se] >= h[u.fi][u.se]) dfs2(v);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->h = heights;
        n = heights.size();
        m = heights[0].size();
        vis1 = vis2 = vector<vector<int>>(n, vector<int>(m, 0));
        // Pacific Ocean
        for (int i = 0; i < n; i++) {
            if (!vis1[i][0]) dfs1({i, 0});
        }
        for (int j = 0; j < m; j++) {
            if (!vis1[0][j]) dfs1({0, j});
        }

        // Atlantic Ocean
        for (int j = 0; j < m; j++) {
            if (!vis2[n-1][j]) dfs2({n-1, j});
        }
        for (int i = 0; i < n; i++) {
            if (!vis2[i][m-1]) dfs2({i, m-1});
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis1[i][j] + vis2[i][j] == 2) ans.push_back({i, j});
            }
        }
        return ans;
    }
};