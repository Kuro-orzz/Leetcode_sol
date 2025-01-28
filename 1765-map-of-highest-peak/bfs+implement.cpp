#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    vector<vector<int>> ans;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    void bfs(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        ans.resize(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pii> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
        while(!q.empty()){
            pii u = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                pii v = {u.fi+dx[i], u.se+dy[i]};
                if(isValid(n, m, v) && !vis[v.fi][v.se]){
                    q.push(v);
                    vis[v.fi][v.se] = 1;
                    ans[v.fi][v.se] = ans[u.fi][u.se] + 1;
                }
            }
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        bfs(isWater);
        return ans;
    }
};