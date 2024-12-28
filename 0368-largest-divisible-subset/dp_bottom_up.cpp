class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(dp[i] > dp[ans])
                ans = i;
        vector<int> res;
        while(ans != -1){
            res.push_back(nums[ans]);
            ans = prev[ans];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};