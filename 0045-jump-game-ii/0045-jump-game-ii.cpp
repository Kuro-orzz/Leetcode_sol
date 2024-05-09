class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < min(n, i+nums[i]+1); j++){
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[n-1];
    }
};