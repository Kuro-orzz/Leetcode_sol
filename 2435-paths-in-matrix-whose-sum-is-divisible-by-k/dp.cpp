class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int path[n][m][k];
        memset(path, 0, sizeof path);
        path[0][0][grid[0][0] % k]++;
        int prev = grid[0][0] % k;
        for (int i = 1; i < n; i++) {
            prev = (prev + grid[i][0]) % k;
            path[i][0][prev]++;
        }
        prev = grid[0][0] % k;
        for (int j = 1; j < m; j++) {
            prev = (prev + grid[0][j]) % k;
            path[0][j][prev]++;
        }
        int MOD = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int l = 0; l < k; l++) {
                    int mod = (l + grid[i][j]) % k;
                    if (path[i-1][j][l]) path[i][j][mod] = (path[i][j][mod] + path[i-1][j][l]) % MOD;
                    if (path[i][j-1][l]) path[i][j][mod] = (path[i][j][mod] + path[i][j-1][l]) % MOD;
                }
            }
        }
        return path[n-1][m-1][0];
    }
};