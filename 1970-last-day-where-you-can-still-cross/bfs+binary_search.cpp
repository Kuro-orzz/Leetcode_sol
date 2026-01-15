#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isValid(pii v, int n, int m) {
        return v.fi >= 0 && v.fi < n && v.se >= 0 && v.se < m;
    }

    bool bfs(int n, int m, vector<vector<int>>& a) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pii> q;
        for (int j = 0; j < m; j++) {
            if (!a[0][j]) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }
        while (!q.empty()) {
            pii u = q.front(); q.pop();
            if (u.fi == n-1) return true;
            for (int k = 0; k < 4; k++) {
                pii v = {u.fi + dx[k], u.se + dy[k]};
                if (isValid(v, n, m) && !vis[v.fi][v.se] && a[v.fi][v.se] == 0) {
                    q.push(v);
                    vis[v.fi][v.se] = 1;
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, r = row * col;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            vector<vector<int>> a(row, vector<int>(col, 0));
            for (int i = 0; i < mid; i++) {
                a[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            if (bfs(row, col, a)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};