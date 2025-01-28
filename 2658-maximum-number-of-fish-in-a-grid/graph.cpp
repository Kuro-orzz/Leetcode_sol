#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int n, m;
    vector<vector<int>> vis, grid;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0}; 

    bool isValid(int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    int dfs(pii u){
        vis[u.fi][u.se] = 1;
        int res = grid[u.fi][u.se];
        for(int i = 0; i < 4; i++){
            pii v = {u.fi + dx[i], u.se + dy[i]};
            if(isValid(n, m, v) && !vis[v.fi][v.se] && grid[v.fi][v.se])
                res += dfs(v);
        }
        return res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        vis.resize(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j])
                    ans = max(ans, dfs({i, j}));
            }
        return ans;
    }
};