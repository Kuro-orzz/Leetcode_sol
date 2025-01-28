class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n);
        dp[0] = 0;
        int mn = prices[0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1];
            if(prices[i] > mn){
                dp[i] += prices[i]-mn;
                mn = INT_MAX;
            }
            mn = min(mn, prices[i]);
        }
        return dp[n-1];
    }
};