class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int x : coins)
            for(int i = 1; i <= amount; i++){
                if(x <= i)
                    dp[i] += dp[i-x];
            }
        return dp[amount];
    }
};