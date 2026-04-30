class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;
                int cost = !grid[i-1][j-1] ? 0 : 1;
                int score = grid[i-1][j-1];
                for (int t = cost; t <= k; t++) {
                    dp[i][j][t-cost] = 0;
                    int flag = 0;
                    if (dp[i-1][j][t] != -1 && i != 1) {
                        dp[i][j][t-cost] = max(dp[i][j][t-cost], dp[i-1][j][t]);
                        flag = 1;
                    }
                    if (dp[i][j-1][t] != -1 && j != 1) {
                        dp[i][j][t-cost] = max(dp[i][j][t-cost], dp[i][j-1][t]);
                        flag = 1;
                    }
                    if (flag) dp[i][j][t-cost] += score;
                    else dp[i][j][t-cost] = -1;
                }
                for (int t = k-cost+1; t <= k; t++) {
                    dp[i][j][t] = -1;
                }
            }
        }
        int ans = -1;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, dp[n][m][i]);
        }
        return ans;
    }
};