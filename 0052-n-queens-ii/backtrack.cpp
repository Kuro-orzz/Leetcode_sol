class Solution {
public:
    vector<vector<int>> v;
    int ans = 0;
    bool isValid(int n, int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, -1, 1};
    void Try(int x, int y, int n){
        if(y == n) return;
        for(int i = 0; i < n; i++){
            if(v[i][y] == 1 || v[x][i] == 1)
                return;
            for(int j = 0; j < 4; j++){
                pair<int, int> u = {x+dx[j]*i, y+dy[j]*i};
                if(isValid(n, u.first, u.second) && v[u.first][u.second] == 1)
                    return;
            }
        }
        v[x][y] = 1;
        if(y == n-1)
            ans++;
        for(int i = 0; i < n; i++)
            Try(i, y+1, n);
        v[x][y] = 0;
    }
    int totalNQueens(int n) {
        v.resize(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            Try(i, 0, n);          
        return ans;
    }
};