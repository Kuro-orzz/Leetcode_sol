class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(3, vector<long long>(n, 0));
        dp[0][0] = energyDrinkA[0];
        dp[1][0] = 0;
        dp[2][0] = energyDrinkB[0];
        for(int i = 1; i < n; i++){
            dp[0][i] = max(dp[0][i-1], dp[1][i-1])+energyDrinkA[i];
            dp[1][i] = max(dp[0][i-1], dp[2][i-1]);
            dp[2][i] = max(dp[2][i-1], dp[1][i-1])+energyDrinkB[i];
        }
        return max({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
    }
};