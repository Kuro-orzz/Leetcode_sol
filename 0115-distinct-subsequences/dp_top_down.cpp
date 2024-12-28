class Solution {
public:
    string s, t;
    vector<vector<unsigned int>> dp;

    unsigned int cal(int i, int j){
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(j == 0) return dp[i][j] = 1;
        if(i == 0) return dp[i][j] = 0;
        if(s[i-1] == t[j-1]) 
            return dp[i][j] = cal(i-1, j-1) + cal(i-1, j);
        return dp[i][j] = cal(i-1, j);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        this->s = s;
        this->t = t;
        dp.resize(n+1, vector<unsigned int>(m+1, INT_MAX));
        return cal(n, m);
    }
};