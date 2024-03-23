class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            long long tmp = 0;
            for(int j = 0; j < n; j++)
                if(i >= nums[j])
                    tmp += dp[i-nums[j]];
            dp[i] = tmp;
        }
        return dp[target]; 
    }
};