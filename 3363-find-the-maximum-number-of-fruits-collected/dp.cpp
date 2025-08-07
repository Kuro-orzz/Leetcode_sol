class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[n-1][n-1] = 0;
        dp[0][n-1] = fruits[0][n-1];
        dp[n-1][0] = fruits[n-1][0];
        for (int i = 0; i < n; i++) {
            dp[n-1][n-1] += fruits[i][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (j + k >= n || dp[i-1][j+k] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i-1][j+k] + fruits[i][j]);
                }
            }
        }
        for (int j = 1; j < n; j++) {
            for (int i = j+1; i < n; i++) {
                for (int k = -1; k <= 1; k++) {
                    if (i + k >= n || dp[i+k][j-1] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i+k][j-1] + fruits[i][j]);
                }
            }
        }
        return dp[n-2][n-1] + dp[n-1][n-2] + dp[n-1][n-1];
    }
};