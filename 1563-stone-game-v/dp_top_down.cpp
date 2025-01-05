class Solution {
public:
    vector<int> val, pre;
    vector<vector<int>> dp;

    int calc(int l, int r){
        if(l >= r-1) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int total = pre[r]-pre[l];
        int sum = 0;
        int mx = 0;
        for(int i = l; i < r-1; i++){
            sum += val[i];
            if(sum < total-sum)
                mx = max(mx, sum + calc(l, i+1));
            else if(sum > total-sum)
                mx = max(mx, total-sum + calc(i+1, r));
            else
                mx = max({mx, sum + calc(l, i+1), total-sum + calc(i+1, r)});
        }
        return dp[l][r] = mx;
    }

    int stoneGameV(vector<int>& stoneValue) {
        this->val = stoneValue;
        int n = stoneValue.size();
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        pre = vector<int>(n+1, 0);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i-1] + val[i-1];
        return calc(0, n);
    }
};