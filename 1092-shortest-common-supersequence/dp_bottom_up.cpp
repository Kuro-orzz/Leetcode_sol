class Solution {
public:
    string dp(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        if(dp[n][m] == m)
            return s1;
        int p1 = n, p2 = m;
        string res = "";
        while(p1 > 0 && p2 > 0){
            if(s1[p1-1] == s2[p2-1]){
                res += s1[p1-1];
                p1--, p2--;
            }
            else if(dp[p1-1][p2] > dp[p1][p2-1])
                res += s1[--p1];
            else
                res += s2[--p2];
        }
        while(p1 > 0) res += s1[--p1];
        while(p2 > 0) res += s2[--p2];
        reverse(res.begin(), res.end());
        return res;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        if(str1.size() < str2.size()) swap(str1, str2);
        return dp(str1, str2);
    }
};