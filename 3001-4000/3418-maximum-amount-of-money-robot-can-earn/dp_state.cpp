class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        // dp[n][m][3]: dp state, number of prevent stealing left
        // init number is small enough to calc without checking
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        dp[0][0][2] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < 3; k++) {
                dp[i][0][k] = dp[i-1][0][k] + coins[i][0];
            }
            if (coins[i][0] < 0) {
                dp[i][0][1] = max(dp[i-1][0][2], dp[i-1][0][1] + coins[i][0]);
                dp[i][0][0] = max(dp[i-1][0][1], dp[i-1][0][0] + coins[i][0]);
            }
        }
        for (int j = 1; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                dp[0][j][k] = dp[0][j-1][k] + coins[0][j];
            }
            if (coins[0][j] < 0) {
                dp[0][j][1] = max(dp[0][j-1][2], dp[0][j-1][1] + coins[0][j]);
                dp[0][j][0] = max(dp[0][j-1][1], dp[0][j-1][0] + coins[0][j]);
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]) + coins[i][j];
                }
                if (coins[i][j] < 0) {
                    for (int k = 0; k <= 1; k++) {
                        dp[i][j][k] = max({dp[i][j][k], dp[i-1][j][k+1], dp[i][j-1][k+1]});
                    }
                }
            }
        }
        return *max_element(dp[n-1][m-1].begin(), dp[n-1][m-1].end());
    }
};