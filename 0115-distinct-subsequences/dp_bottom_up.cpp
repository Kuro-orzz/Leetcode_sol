class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(m+1, 1));
        for(int i = 1; i <= m; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                if(s[j-1] == t[i-1])
                    dp[j][i] = dp[j-1][i-1] + dp[j-1][i];
                else dp[j][i] = dp[j-1][i]; 
            }
        return dp[n][m];
    }
};