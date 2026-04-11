class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pref(n, vector<int>(m+1, 1)), suff(n, vector<int>(m+2, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = (1ll * pref[i][j-1] * grid[i][j-1]) % mod; 
            }
            for (int j = m; j >= 1; j--) {
                suff[i][j] = (1ll * suff[i][j+1] * grid[i][j-1]) % mod;
            }
        }
        vector<int> row_pref(n+1, 1), row_suff(n+2, 1);
        for (int i = 1; i <= n; i++) {
            row_pref[i] = (row_pref[i-1] * pref[i-1][m]) % mod;
        }
        for (int i = n; i >= 1; i--) {
            row_suff[i] = (row_suff[i+1] * pref[i-1][m]) % mod;
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (row_pref[i] * row_suff[i+2]) % mod;
                ans[i][j] = (ans[i][j] * pref[i][j]) % mod;
                ans[i][j] = (ans[i][j] * suff[i][j+2]) % mod;
            }
        }
        return ans;
    }
};