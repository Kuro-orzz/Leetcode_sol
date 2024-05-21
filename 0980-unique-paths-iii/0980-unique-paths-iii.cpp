#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    bool vis[20][20];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int cnt = 0;
    int total = 0;
    int ans = 0;
    void dfs(pii u, int n, int m, vector<vector<int>> &grid){
        vis[u.fi][u.se] = true;
        cnt++;
        if(grid[u.fi][u.se] == 2 && cnt == total)
            ans++;
        for(int i = 0; i < 4; i++){
            pii v = {u.fi+dx[i], u.se+dy[i]};
            if(v.fi >= 0 && v.fi < n && v.se >= 0 && v.se < m){
                if(!vis[v.fi][v.se] && grid[v.fi][v.se] != -1)
                    dfs(v, n, m, grid);
            }
        }
        vis[u.fi][u.se] = false;
        cnt--;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pii start;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(grid[i][j] != -1)
                    total++;
                if(grid[i][j] == 1)
                    start = {i, j};
            }
        dfs(start, n, m, grid);
        return ans;
    }
};