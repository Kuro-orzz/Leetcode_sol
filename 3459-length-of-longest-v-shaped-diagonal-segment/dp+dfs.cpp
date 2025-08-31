#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int n, m, ans;
    vector<vector<int>> grid;
    int dp[506][506][4][2];
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, 1, -1};

    bool isValid(pii u) {
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    void dfs(pii cur, int direct = -1, bool turned = false) {
        // turned -- not turned (can only turn at most clockwise 90 degrees)
        for (int k = 0; k < 4; k++) {
            // next grid
            pii v = {cur.fi + dx[k], cur.se + dy[k]};
            if (!isValid(v)) continue;
            // if start grid we can go any direction
            // if not start grid
            if (grid[cur.fi][cur.se] != 1) {                
                // not turned yet and can only turn clockwise 90 degrees
                if (k != direct && k != (direct + 1) % 4) continue;
                
                // if turned and not that direction then skip
                if (turned && k != direct) continue;
                
                // if not satisfied
                if (grid[cur.fi][cur.se] == 2 && grid[v.fi][v.se] != 0) continue;
                if (grid[cur.fi][cur.se] == 0 && grid[v.fi][v.se] != 2) continue;
            } else {
                if (grid[v.fi][v.se] != 2) continue;
            }

            if (!turned) {
                // same direction
                if ((k == direct || direct == -1) && dp[v.fi][v.se][k][0] < dp[cur.fi][cur.se][k][0] + 1) {
                    dp[v.fi][v.se][k][0] = dp[cur.fi][cur.se][k][0] + 1;
                    dfs(v, k, false);
                } else if (k != direct && dp[v.fi][v.se][k][1] < dp[cur.fi][cur.se][direct][0] + 1) {
                    dp[v.fi][v.se][k][1] = dp[cur.fi][cur.se][direct][0] + 1;
                    dfs(v, k, true);
                }
            } else {
                if (k == direct && dp[cur.fi][cur.se][k][1] + 1 > dp[v.fi][v.se][k][1]) {
                    dp[v.fi][v.se][k][1] = dp[cur.fi][cur.se][k][1] + 1;
                    dfs(v, k, true);
                }
            }
            
        }
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        dp[i][j][k][0] = 1;
                    }
                    dfs({i, j});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    ans = max({ans, dp[i][j][k][0], dp[i][j][k][1]});
                }
            }
        }
        return ans;
    }
};