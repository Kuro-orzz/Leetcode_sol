#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> dp;

    bool isValid(pii u, int n, int m) {
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    void bfs(pii s, vector<vector<int>> &mat, int n, int m) {
        queue<pii> q;
        q.push(s);
        dp[s.fi][s.se] = 1;
        while (!q.empty()) {
            pii u = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                pii v = {u.fi + dx[k], u.se + dy[k]};
                if (!isValid(v, n, m)) continue;
                if (mat[v.fi][v.se] > mat[u.fi][u.se] && dp[v.fi][v.se] <= dp[u.fi][u.se]) {
                    dp[v.fi][v.se] = dp[u.fi][u.se] + 1;
                    q.push(v);
                }
            }
        }   
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j]) continue;
                bfs({i, j}, matrix, n, m);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};