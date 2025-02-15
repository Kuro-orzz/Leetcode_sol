class Solution {
public:
    vector<long long> dp;
    vector<vector<int>> questions;

    long long cal(int i, int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int p = i+questions[i][1]+1;
        dp[i] = questions[i][0];
        return dp[i] = max(cal(i+1, n), questions[i][0] + cal(p, n)); 
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        this->questions = questions;
        dp.resize(n, -1);
        return cal(0, n);
    }
};