class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < m-2; j++)
                memo[i][j] = max({grid[i][j], grid[i][j+1], grid[i][j+2]});
        vector<vector<int>> ans(n-2, vector<int>(m-2));
        for(int i = 0; i < n-2; i++)
            for(int j = 0; j < m-2; j++)
                ans[i][j] = max({memo[i][j], memo[i+1][j], memo[i+2][j]});
        return ans;
    }
};