class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(2));
        vector<int> pref(n+1);
        // 0: current number of people know
        // 1: number of people know in day i
        dp[1][0] = dp[1][1] = 1;
        pref[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i-1][0];
            pref[i] = pref[i-1];
            if (i <= delay) continue;
            if (i > forget) {
                dp[i][0] = (dp[i][0] - dp[i-forget][1] + mod) % mod;
            }
            int sum = (pref[i-delay] - pref[max(0, i-forget)] + mod) % mod;
            dp[i][0] = (dp[i][0] + sum) % mod;
            dp[i][1] = sum;
            pref[i] = (pref[i] + dp[i][1]) % mod;
        }
        return dp[n][0];
    }
};