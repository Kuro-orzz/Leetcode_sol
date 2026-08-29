class Solution {
public:
    int mod = 1e9 + 7;

    int rearrangeSticks(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                if (i == j) dp[i][j] = 1;
                else if (j == 1) dp[i][j] = 1ll * dp[i-1][1] * (i - 1) % mod;
                else dp[i][j] = (dp[i-1][j-1] + 1ll * (i - 1) * dp[i-1][j]) % mod;
            }
        }
        return dp[n][k];
    }
};