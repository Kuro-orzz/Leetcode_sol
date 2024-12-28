class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        int i = 1;
        while(i * i <= n){
            v.push_back(i*i);
            i++;
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < v.size(); j++)
                if(v[j] <= i && dp[i-v[j]]+1 < dp[i])
                    dp[i] = dp[i-v[j]]+1;
        return dp[n];
    }
};