#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums)
            sum += x;
        if(sum % 2 != 0)
            return false;
        bool dp[sum+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            for(int j = sum; j >= nums[i]; j--)
                if(dp[j-nums[i]])
                    dp[j] = true;
        if(dp[sum/2])
            return true;
        return false;
    }
};