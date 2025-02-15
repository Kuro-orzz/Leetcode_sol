#define pii pair<int, int>
#define fi first
#define se second
class neighborSum {
public:
    vector<vector<int>> a;
    neighborSum(vector<vector<int>>& grid) {
        a = grid;
    }
    
    bool isValid(int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    int adjacentSum(int value) {
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        pii u;
        for(int i = 0; i < a.size(); i++)
            for(int j = 0; j < a[0].size(); j++)
                if(a[i][j] == value)
                    u = {i, j};
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            pii v = {u.fi+dx[i], u.se+dy[i]};
            if(isValid(a.size(), a[0].size(), v))
                ans += a[v.fi][v.se];
        }
        return ans;
    }
    
    int diagonalSum(int value) {
        int dx[] = {-1, -1, 1, 1};
        int dy[] = {-1, 1, -1, 1};
        pii u;
        for(int i = 0; i < a.size(); i++)
            for(int j = 0; j < a[0].size(); j++)
                if(a[i][j] == value)
                    u = {i, j};
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            pii v = {u.fi+dx[i], u.se+dy[i]};
            if(isValid(a.size(), a[0].size(), v))
                ans += a[v.fi][v.se];
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */