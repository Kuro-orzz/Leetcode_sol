#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<pii> cnt(sz);
        for (int i = 0; i < sz; i++) {
            int zero = 0, one = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') zero++;
                else one++;
            }
            cnt[i] = {zero, one};
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = m; j >= cnt[i].fi; j--) {
                for (int k = n; k >= cnt[i].se; k--) {
                    dp[j][k] = max(dp[j][k], dp[j-cnt[i].fi][k-cnt[i].se] + 1);
                    ans = max(ans, dp[j][k]);
                }
            }
        }
        return ans;
    }
};