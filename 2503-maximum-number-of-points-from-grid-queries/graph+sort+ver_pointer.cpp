#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> grid;
    map<int, int> mp;
    int cnt = 0, cur_mx = 0;

    struct cmp{
        vector<vector<int>> *grid;
        cmp(vector<vector<int>> *grid){
            this->grid = grid;
        }
        bool operator()(pii a, pii b){
            return (*grid)[a.fi][a.se] > (*grid)[b.fi][b.se];
        }
    };

    bool isValid(pii u, int n, int m){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    void bfs(pii u, int n, int m){
        priority_queue<pii, vector<pii>, cmp> pq(&grid);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        pq.push({u.fi, u.se});
        vis[u.fi][u.se] = 1;
        mp[0] = 0;
        cur_mx = grid[u.fi][u.se];
        while(!pq.empty()){
            pii v = pq.top(); pq.pop();
            cnt++;
            for(int i = 0; i < 4; i++){
                pii k = {v.fi+dx[i], v.se+dy[i]};
                if(isValid(k, n, m) && !vis[k.fi][k.se]){
                    vis[k.fi][k.se] = 1;
                    pq.push({k.fi, k.se});
                }
            }
            if(grid[v.fi][v.se] >= cur_mx)
                mp[grid[v.fi][v.se]] = cnt;
            else mp[cur_mx] = cnt;
            cur_mx = max(cur_mx, grid[v.fi][v.se]);
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        this->grid = grid;
        bfs({0, 0}, n, m);
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            auto it = mp.lower_bound(queries[i]);
            if(it == mp.end() || it->fi >= queries[i])
                ans[i] = prev(it)->se;
            else ans[i] = it->se;
        }
        return ans;
    }
};