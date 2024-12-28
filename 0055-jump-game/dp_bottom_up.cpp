class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] != INT_MAX){
                for(int j = i+1; j < min(n, i+nums[i]+1); j++){
                    dp[j] = min(dp[j], dp[i]+1);
                }
            }
        }
        return (dp[n-1] == INT_MAX ? 0 : dp[n-1]);
    }
};