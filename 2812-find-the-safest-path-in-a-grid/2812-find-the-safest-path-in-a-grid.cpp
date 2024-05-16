#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int visited[400][400];
    bool vis[400][400];
    void multi_source_bfs(int n, vector<vector<int>> &grid){
        queue<pii> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        while(!q.empty()){
            pii v = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                pii t = {v.fi+dx[i], v.se+dy[i]};
                if(t.fi >= 0 && t.fi < n && t.se >= 0 && t.se < n){
                    if(!vis[t.fi][t.se] && grid[t.fi][t.se] && grid[t.fi][t.se] > grid[v.fi][v.se]){
                        grid[t.fi][t.se] = grid[v.fi][v.se]+1;
                        q.push(t);
                        vis[t.fi][t.se] = true;
                    }
                }
            }
        }
    }
    void dijkstra(int n, vector<vector<int>> &grid){
        vector<vector<int>> d(n, vector<int>(n, INT_MAX));
        d[0][0] = grid[0][0];
        priority_queue<pip> pq;
        pq.push({d[0][0], {0, 0}});
        while(!pq.empty()){
            pip top = pq.top(); pq.pop();
            // cout << top.fi << " {" << top.se.fi << ", " << top.se.se << "}\n"; 
            int distance = top.fi;
            pii u = top.se;
            if(visited[n-1][n-1] == 1) return;
            if(visited[u.fi][u.se] == 1) continue;
            visited[u.fi][u.se] = 1;
            for(int i = 0; i < 4; i++){
                pii v = {u.fi+dx[i], u.se+dy[i]};
                if(v.fi >= 0 && v.fi < n && v.se >= 0 && v.se < n){
                    if(grid[v.fi][v.se] != 0 && !visited[v.fi][v.se]){
                        int k = min(distance, grid[v.fi][v.se]);
                        grid[v.fi][v.se] = min(grid[u.fi][u.se], grid[v.fi][v.se]);
                        pq.push({k,v});
                    }
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0)
                    grid[i][j] = INT_MAX;
                else
                    grid[i][j] = 0;
        multi_source_bfs(n, grid);
        dijkstra(n, grid);
        if(visited[n-1][n-1] == 1)
            return grid[n-1][n-1];
        else
            return 0;
    }
};