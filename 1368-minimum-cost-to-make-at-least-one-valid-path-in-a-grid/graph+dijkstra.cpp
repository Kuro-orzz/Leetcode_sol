class Grid {
public:
    int x, y, cost;

    Grid(int x, int y, int cost): x(x), y(y), cost(cost) {}

    bool operator < (Grid other) const {
        return this->cost > other.cost;
    }
};

class Solution {
public:
    int n, m;
    vector<vector<int>> c;
    int dx[5] = {0, 0, 0, 1, -1};
    int dy[5] = {0, 1, -1, 0, 0};

    bool isValid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        c.resize(n, vector<int>(m, INT_MAX));
        priority_queue<Grid> pq;
        c[0][0] = 0;
        pq.push({0, 0, 0});
        while(!pq.empty()){
            Grid cur = pq.top(); pq.pop();
            for(int i = 1; i <= 4; i++){
                int x = cur.x + dx[i];
                int y = cur.y + dy[i];
                if(!isValid(x, y)) continue;
                int cost = cur.cost + (i != grid[cur.x][cur.y]);
                if(cost < c[x][y]){
                    pq.push({x, y, cost});
                    c[x][y] = cost;
                }
            }
        }
        return c[n-1][m-1];
    }
};