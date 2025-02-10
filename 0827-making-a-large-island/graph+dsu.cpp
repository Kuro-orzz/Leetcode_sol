#define pii pair<int, int>
#define fi first
#define se second

struct DSU_2D {
    vector<vector<pii>> par;
    vector<vector<int>> sz;
    
    DSU_2D(int n, int m): par(n, vector<pii>(m)), sz(n, vector<int>(m, 1)) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                par[i][j] = {i, j};
    }

    pii find(pii v){
        if(v == par[v.fi][v.se])
            return v;
        return par[v.fi][v.se] = find(par[v.fi][v.se]);
    }

    void merge(pii a, pii b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(sz[a.fi][a.se] < sz[b.fi][b.se]) swap(a, b);
            par[b.fi][b.se] = a;
            sz[a.fi][a.se] += sz[b.fi][b.se];
        }
    }

    int max_component(){
        int res = 0;
        for(int i = 0; i < sz.size(); i++)
            for(int j = 0; j < sz[i].size(); j++)
                res = max(res, sz[i][j]);
        return res;
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool isValid(int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU_2D g(n, n);    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j])
                    for(int k = 0; k < 4; k++){
                        pii u = {i+dx[k], j+dy[k]};
                        if(isValid(n, n, u) && grid[u.fi][u.se]){
                            g.merge({i, j}, u);
                        }
                    }
            }
        }
        int ans = g.max_component();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]){
                    int t = 1;
                    set<pii> s;
                    for(int k = 0; k < 4; k++){
                        pii u = {i+dx[k], j+dy[k]};
                        if(isValid(n, n, u) && grid[u.fi][u.se]){
                            pii v = g.find(u);
                            if(s.count(v)) continue;
                            t += g.sz[v.fi][v.se];
                            s.insert(v);
                        }
                    }
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};