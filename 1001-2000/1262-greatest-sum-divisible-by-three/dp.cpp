class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = dp[0][2] = -1e9;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                int m = (j + nums[i-1]) % 3;
                dp[i][m] = dp[i-1][m];
                dp[i][m] = max(dp[i][m], dp[i-1][j] + nums[i-1]);
            }
        }
        return dp[n][0];
    }
};