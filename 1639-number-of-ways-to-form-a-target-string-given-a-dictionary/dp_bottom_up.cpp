class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9+7;
        int n = words.size();
        int m = words[0].size();
        vector<vector<int>> v(m, vector<int>(26, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                v[j][words[i][j]-'a']++;
        vector<vector<long long>> dp(target.size()+1, vector<long long>(m+1));
        for(int i = 1; i <= target.size(); i++){
            for(int j = i; j <= m; j++){
                if(i == 1) 
                    dp[i][j] = dp[i][j-1] + v[j-1][target[i-1]-'a'];
                else
                    dp[i][j] = dp[i][j-1] + v[j-1][target[i-1]-'a'] * dp[i-1][j-1];
                dp[i][j] %= mod;
            }
        }
        return dp[target.size()][m];
    }
};