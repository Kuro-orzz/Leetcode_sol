#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(pii u, int n, int m) {
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    int dijkstra(pii u, int n, int m, vector<vector<int>> &grid) {
        int cur_d = 0;
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        vector<vector<int>> vis(n, vector<int>(m));
        pq.push({0, u});
        while (!pq.empty()) {
            auto tmp = pq.top(); pq.pop();
            int dist = tmp.fi;
            pii pos = tmp.se;
            if (vis[pos.fi][pos.se]) continue;
            vis[pos.fi][pos.se] = 1;
            cur_d = max(cur_d, grid[pos.fi][pos.se]);
            if (pos == make_pair(n-1, m-1)) return cur_d;
            for (int k = 0; k < 4; k++) {
                pii v = {pos.fi + dx[k], pos.se + dy[k]};
                if (!isValid(v, n, m) || vis[v.fi][v.se]) continue;
                pq.push({grid[v.fi][v.se], v});
            }
        }
        return -1;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return dijkstra({0, 0}, n, m, grid);
    }
};