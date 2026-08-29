/*
    Matrix chain multiplication
    O(n*n*n)
*/
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 2; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;
                dp[i][j] = 1e9;
                for (int k = i+1; k < j; k++) {
                    int val = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k];
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[0][n-1];
    }
};