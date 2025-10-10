class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = mana.size();
        int m = skill.size();
        vector<vector<long long>> dp(n, vector<long long>(m));
        dp[0][0] = skill[0] * mana[0];
        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j-1] + 1ll * mana[0] * skill[j];
        }
        for (int i = 1; i < n; i++) {
            dp[i][m-1] = dp[i-1][m-1] + 1ll * mana[i] * skill[m-1];
            long long need = 0;
            for (int j = m-2; j >= 0; j--) {
                dp[i][j] = dp[i][j+1] - 1ll * mana[i] * skill[j+1];
                need = max(need, dp[i-1][j] - dp[i][j] + 1ll * mana[i] * skill[j]);
            }
            for (int j = 0; j < m; j++) {
                dp[i][j] += need;
            }
        }
        return dp[n-1][m-1];
    }
};