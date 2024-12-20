class Solution {
public:
    string s1, s2;
    vector<vector<int>> dp;
    int cal(int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 && j == 0) return dp[i][j] = 0;
        if(i == 0) return dp[i][j] = cal(i, j-1) + s2[j-1];
        if(j == 0) return dp[i][j] = cal(i-1, j) + s1[i-1];
        if(s1[i-1] == s2[j-1]) return dp[i][j] = cal(i-1, j-1);
        return dp[i][j] = min({cal(i-1, j) + s1[i-1], cal(i, j-1) + s2[j-1], 
                            cal(i-1, j-1) + s1[i-1] + s2[j-1]});
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        this->s1 = s1;
        this->s2 = s2;
        dp.resize(n+1, vector<int>(m+1, -1));
        return cal(n, m);
    }
};