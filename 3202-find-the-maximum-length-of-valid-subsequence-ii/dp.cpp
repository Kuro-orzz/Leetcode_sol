class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            vector<int> dp(k);
            for (int x : nums) {
                dp[x % k] = dp[(i - x % k + k) % k] + 1;
                ans = max(ans, dp[x % k]);
            }
        }
        return ans;
    }
};