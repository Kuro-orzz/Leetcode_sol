#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> vis;
    bool isValid(int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }
    void dfs(pii u, int n, int m, vector<vector<char>>& board){
        vis[u.fi][u.se] = 1;
        for(int i = 0; i < 4; i++){
            pii v = {u.fi+dx[i], u.se+dy[i]};
            if(isValid(n, m, v) && !vis[v.fi][v.se] && board[u.fi][u.se] == board[v.fi][v.se])
                dfs(v, n, m, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vis.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            if(!vis[i][0])
                dfs({i, 0}, n, m, board);
            if(!vis[i][m-1])
                dfs({i, m-1}, n, m, board);
        }
        for(int i = 0; i < m; i++){
            if(!vis[0][i])
                dfs({0, i}, n, m, board);
            if(!vis[n-1][i])
                dfs({n-1, i}, n, m, board);
        }
        for(int i = 1; i < n-1; i++)
            for(int j = 1; j < m-1; j++)
                if(!vis[i][j]){
                    if(board[i][j] == 'O')
                        board[i][j] = 'X';
                }
    }
};