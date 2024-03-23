#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    string longestPalindrome(string s) {
        int ans[2];
        ans[0] = 0;
        ans[1] = 1;
        int n = s.length();
        bool dp[n+1][n+1];
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
                if(i == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= n-i+1; j++){
                if(i == 2 && s[j-1] == s[j+i-2])
                    dp[j-1][j+i-2] = 1;
                else{
                    if(s[j-1] == s[j+i-2] && dp[j][j+i-3])
                        dp[j-1][j+i-2] = 1;
                    else
                        dp[j-1][j+i-2] = 0; 
                }
                if(dp[j-1][j+i-2] && i > ans[1])
                    ans[0] = j-1, ans[1] = i;
            }
        return s.substr(ans[0], ans[1]);
    }
};