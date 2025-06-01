#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    struct pair_hash {
        size_t operator()(const pii& p) const {
            return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
        }
    };

    unordered_map<int, pii> mp1;
    unordered_map<pii, int, pair_hash> mp2;
    vector<vector<int>> d;

    void bfs(pii u, int n, vector<vector<int>> &a) {
        d.assign(n, vector<int>(n, INT_MAX));
        queue<pii> q;
        q.push(u);
        d[u.fi][u.se] = 0;
        while (!q.empty()) {
            pii v = q.front(); q.pop();
            int cur = mp2[v];
            for (int i = cur+1; i <= min(cur+6, n*n); i++) {
                auto [x, y] = mp1[i];
                if (a[x][y] != -1) {
                    tie(x, y) = mp1[a[x][y]];
                    if (d[x][y] > d[v.fi][v.se] + 1) {
                        q.push({x, y});
                        d[x][y] = d[v.fi][v.se] + 1;
                    }
                } else if (d[x][y] > d[v.fi][v.se] + 1) {
                    q.push({x, y});
                    d[x][y] = d[v.fi][v.se] + 1;
                }
            }         
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int cnt = 1;
        for (int i = n-1; i >= 0; i--) {
            if ((n-1-i) % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    mp1[cnt] = {i, j};
                    mp2[{i, j}] = cnt++;
                }
            } else {
                for (int j = n-1; j >= 0; j--) {
                    mp1[cnt] = {i, j};
                    mp2[{i, j}] = cnt++;
                }
            }
        }
        bfs({n-1, 0}, n, board);
        pii fin = mp1[n*n];
        return d[fin.fi][fin.se] == INT_MAX ? -1 : d[fin.fi][fin.se];
    }
};