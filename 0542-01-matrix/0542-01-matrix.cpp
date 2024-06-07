#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    vector<vector<int>> vis;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool isValid(pii x, int n, int m){
        return x.fi >= 0 && x.fi < n && x.se >= 0 && x.se < m;
    }
    void bfs(int n, int m, vector<vector<int>> &a){
        vis.resize(n, vector<int>(m));
        queue<pii> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            pii u = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                pii v = {u.fi+dx[i], u.se+dy[i]};
                if(isValid(v, n, m) && !vis[v.fi][v.se]){
                    if(a[v.fi][v.se] != 0){
                        a[v.fi][v.se] = a[u.fi][u.se]+1;
                        vis[v.fi][v.se] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bfs(n, m, mat);
        return mat;
    }
};