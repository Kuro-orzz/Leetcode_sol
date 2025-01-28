class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> r(n, 0), c(m, 0);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(grid[i][j]) 
                    r[i]++;
            }
        for(int i = 0; i < n; i++){
            if(r[i] > 1){
                ans += r[i];
                for(int j = 0; j < m; j++)
                    vis[i][j] = 1;
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    c[j]++;
        for(int j = 0; j < m; j++){
            if(c[j] > 1){
                for(int i = 0; i < n; i++){
                    if(grid[i][j] && !vis[i][j])
                        ans++;
                }
            }
        }
        return ans;
    }
};