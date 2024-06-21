#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    struct dsu_2D{
        vector<vector<pii>> par;
        vector<vector<int>> sz;
        dsu_2D(int n, int m): par(n, vector<pii>(m)), sz(n, vector<int>(m, 1)){
            for(int i = 0; i < par.size(); i++)
                for(int j = 0; j < par[i].size(); j++)
                    par[i][j] = {i, j};
        }
        pii find(pii v){
            if(v == par[v.fi][v.se])
                return v;
            return par[v.fi][v.se] = find(par[v.fi][v.se]);
        }
        void Union(pii a, pii b){
            a = find(a);
            b = find(b);
            if(a != b){
                if(sz[a.fi][a.se] < sz[b.fi][b.se]) swap(a, b);
                par[b.fi][b.se] = a;
                sz[a.fi][a.se] += sz[b.fi][b.se];
            }
        }
    };
    bool isValid(int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dsu_2D g(n, m);
        bool ch = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    for(int k = 0; k < 4; k++){
                        pii v = {i+dx[k], j+dy[k]};
                        if(isValid(n, m, v) && grid[i][j] == grid[v.fi][v.se])
                            g.Union({i, j}, v);
                    }
                    ch = true;
                }
            }
        if(!ch)
            return 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans = max(ans, g.sz[i][j]);
        return ans;
    }
};