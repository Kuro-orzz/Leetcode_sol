class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int val = arr[j]-arr[i];
                if(!mp.count(val) || val >= arr[i]) continue;
                int pos = mp[val];
                dp[i][j] = max(dp[i][j], dp[pos][i]+1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, dp[i][j]);
        if(ans < 3) return 0;
        return ans;
    }
};