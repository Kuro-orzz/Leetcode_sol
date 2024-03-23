class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = min(cost[0], cost[1]);
        for(int i = 2; i < n; i++)
            dp[i] = min(dp[i-1]+cost[i], dp[i-2]+cost[i-1]);
        return dp[n-1];
    }
};