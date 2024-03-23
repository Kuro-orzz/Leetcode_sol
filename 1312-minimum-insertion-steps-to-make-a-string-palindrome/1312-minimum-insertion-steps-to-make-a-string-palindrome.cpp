#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string x = s;
        reverse(x.begin(), x.end());
        int dp[n+1][n+1];
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else{
                    if(x[i-1] == s[j-1])
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        return n-dp[n][n];
    }
};