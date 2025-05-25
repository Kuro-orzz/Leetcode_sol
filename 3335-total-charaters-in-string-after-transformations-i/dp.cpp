class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9+7;
        int ans = 0;
        vector<int> fre(26, 0);
        for (char c : s) fre[c-'a']++;
        vector<vector<int>> dp;
        for (int i = 0; i < 26; i++) {
            if (fre[i] == 0) continue;
            int p = t - (26 - i);
            if (p < 0) {
                ans = (ans + fre[i]) % mod;
                continue;
            } else if (p == 0) {
                ans = (ans + fre[i] * 2) % mod;
                continue;
            }
            dp.resize(p+1, vector<int>(2, 0));
            for (int i = 0; i <= p; i++)
                dp[i][0] = dp[i][1] = 0;
            dp[p][0] = dp[p][1] = fre[i];
            for (int j = p; j >= 25; j--) {
                if (j >= 26) { // 'a' -> 'ab'
                    dp[j-26][0] = (dp[j-26][0] + dp[j][0]) % mod;
                    dp[j-26][1] = (dp[j-26][1] + dp[j][0]) % mod;
                }
                if (j >= 25) { // 'b' -> 'ab'
                    dp[j-25][0] = (dp[j-25][0] + dp[j][1]) % mod;
                    dp[j-25][1] = (dp[j-25][1] + dp[j][1]) % mod;
                }
            }
            for (int j = 0; j < min(26, p+1); j++) {
                ans = (ans + dp[j][0]) % mod;
                if (j != 25) ans = (ans + dp[j][1]) % mod;
            }
        }
        return ans;
    }
};