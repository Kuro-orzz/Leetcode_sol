class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 1;
        vector<int> dp(m, 1);
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                bool check = true;
                for (int k = 0; k < n; k++) {
                    if (strs[k][i] > strs[k][j]) {
                        check = false;
                        break;
                    }
                }
                if (check) dp[j] = max(dp[j], dp[i] + 1);
                ans = max(ans, dp[j]);
            }
        }
        return m - ans;
    }
};