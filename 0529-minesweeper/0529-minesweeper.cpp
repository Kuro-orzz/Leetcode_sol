#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    bool isValid(pii u, int n, int m){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }
    void bfs(vector<int> &click, vector<vector<char>> &board, int n, int m){
        vector<vector<int>> vis(n, vector<int>(m, 0));
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return;
        }
        queue<pii> q;
        q.push({click[0], click[1]});
        vis[click[0]][click[1]] = 1;
        while(!q.empty()){
            pii u = q.front(); q.pop();
            if(board[u.fi][u.se] != 'E') continue;
            int bomb = 0;
            for(int i = 0; i < 8; i++){
                pii v = {u.fi+dx[i], u.se+dy[i]};
                if(isValid(v, n, m) && !vis[v.fi][v.se]){
                    if(board[v.fi][v.se] == 'M')
                        bomb++;
                    if(board[v.fi][v.se] == 'E'){
                        bool check = true;
                        for(int j = 0; j < 8; j++){
                            pii t = {u.fi+dx[j], u.se+dy[j]};
                            if(isValid(t, n, m) && board[t.fi][t.se] == 'M')
                                check = false;
                        }
                        if(check)
                            q.push(v);
                    }
                }
            }
            if(bomb)
                board[u.fi][u.se] = bomb+'0';
            else
                board[u.fi][u.se] = 'B';
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();
        bfs(click, board, n, m);
        return board;
    }
};