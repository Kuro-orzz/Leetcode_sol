#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pii> dp(n, {1, 1});
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++)
                if(nums[i] > nums[j]){
                    if(dp[j].fi+1 > dp[i].fi)
                        dp[i] = {dp[j].fi+1, dp[j].se};
                    else if(dp[j].fi+1 == dp[i].fi)
                        dp[i].se += dp[j].se;
                }
        }
        pii ans = {0, 0};
        for(int i = 0; i < n; i++){
            if(dp[i].fi > ans.fi)
                ans = dp[i];
            else if(dp[i].fi == ans.fi)
                ans.se += dp[i].se;
        }
        return ans.se;
    }
};