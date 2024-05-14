#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    bool visited[20][20];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int ans = 0;
    void dfs(pii u, int &n, int &m, vector<vector<int>> &grid, int &sum){
        ans = max(ans, sum);
        visited[u.fi][u.se] = true;
        for(int i = 0; i < 4; i++){
            pii v = {u.fi+dx[i], u.se+dy[i]};
            if(v.fi >= 0 && v.fi < n && v.se >= 0 && v.se < m)
                if(grid[v.fi][v.se] && !visited[v.fi][v.se]){
                    sum += grid[v.fi][v.se];
                    ans = max(ans, sum);
                    dfs(v, n, m, grid, sum);
                    sum -= grid[v.fi][v.se];
                }
        }
        visited[u.fi][u.se] = false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    dfs({i, j}, n, m, grid, grid[i][j]);
        return ans;
    }
};