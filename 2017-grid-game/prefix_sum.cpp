class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> pre(2, vector<long long>(n+1));
        pre[0][0] = pre[1][0] = 0;
        for(int i = 1; i < n+1; i++){
            pre[0][i] = pre[0][i-1] + grid[0][i-1];
            pre[1][i] = pre[1][i-1] + grid[1][i-1];
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++)
            ans = min(ans, max(pre[1][i], pre[0][n]-pre[0][i+1]));
        return ans;
    }
};