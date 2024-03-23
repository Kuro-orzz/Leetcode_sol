#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m][m];
        int dx[3] = {-1, 0, 1};
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = j+1; k < m; k++){
                    if(i == 0){
                        if(j == 0 && k == m-1)
                            dp[i][j][k] = grid[i][j] + grid[i][k];
                        else
                            dp[i][j][k] = -1;
                    }
                    else{
                        dp[i][j][k] = -1;
                        for(int c1 = 0; c1 < 3; c1++)
                            for(int c2 = 0; c2 < 3; c2++){
                                int j1 = j + dx[c1];
                                int k1 = k + dx[c2];
                                if(j1 >= 0 && j1 < m && k1 >= 0 && k1 < m && j1 < k1)
                                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j1][k1]);
                            }
                        if(dp[i][j][k] != -1)
                            dp[i][j][k] += grid[i][j] + grid[i][k];
                    }
                }
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = i+1; j < m; j++)
                ans = max(ans, dp[n-1][i][j]);
        return ans;
    }
};