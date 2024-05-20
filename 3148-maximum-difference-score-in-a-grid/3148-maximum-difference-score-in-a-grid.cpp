class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else{
                    dp[i][j] = grid[i][j];
                    if(j != 0)
                        dp[i][j] = min(dp[i][j-1], dp[i][j]);
                    if(i != 0)
                        dp[i][j] = min(dp[i-1][j], dp[i][j]);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                ans = max(ans, grid[i][j]-dp[i][j]);
        }
        if(ans == 0){
            ans = INT_MIN;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(i != 0)
                        ans = max(ans, grid[i][j]-grid[i-1][j]);
                    if(j != 0)
                        ans = max(ans, grid[i][j]-grid[i][j-1]);
                }
            }
        }
        return ans;
    }
};