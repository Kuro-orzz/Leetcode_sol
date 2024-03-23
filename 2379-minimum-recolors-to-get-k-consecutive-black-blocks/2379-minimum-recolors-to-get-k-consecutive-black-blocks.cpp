class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        vector<int> dp(n+1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            dp[i] = cnt;
            if(blocks[i] == 'B')
                cnt++;
        }
        dp[n] = cnt;
        int ans = k;
        for(int i = 0; i <= n-k; i++)
            ans = min(ans, k-dp[i+k]+dp[i]);
        return ans;
    }
};