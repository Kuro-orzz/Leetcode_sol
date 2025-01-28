#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<vector<int>> h;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    struct cmp{
        bool operator()(pair<int, pii> a, pair<int, pii> b){
            return a.fi >= b.fi;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if(n < 3 || m < 3) return 0;
        this->h = heightMap;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> pq;   
        for(int i = 0; i < m; i++){
            pq.push({h[0][i], {0, i}});
            pq.push({h[n-1][i], {n-1, i}});
            vis[0][i] = vis[n-1][i] = 1;
        }     
        for(int i = 1; i < n-1; i++){
            pq.push({h[i][0], {i, 0}});
            pq.push({h[i][m-1], {i, m-1}});
            vis[i][0] = vis[i][m-1] = 1;
        }
        auto isValid = [&](pii u){
            return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
        };     
        int ans = 0;
        while(!pq.empty()){
            pair<int, pii> u = pq.top(); pq.pop();
            for(int i = 0; i < 4; i++){
                pii v = {u.se.fi+dx[i], u.se.se+dy[i]};
                if(isValid(v) && !vis[v.fi][v.se]){
                    if(u.fi > h[v.fi][v.se]){
                        ans += u.fi - h[v.fi][v.se];
                        pq.push({u.fi, {v.fi, v.se}});
                    }
                    else pq.push({h[v.fi][v.se], {v.fi, v.se}});                   
                    vis[v.fi][v.se] = 1;
                }
            }
        }
        return ans;
    }
};