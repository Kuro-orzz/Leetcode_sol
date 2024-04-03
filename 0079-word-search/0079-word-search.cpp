class Solution {
public:
    int visited[7][7];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool dfs(pair<int, int> u, string s, int k, int n, int m, vector<vector<char>> &board){
        if(k == s.size())
            return true;
        visited[u.first][u.second] = true;
        for(int i = 0; i < 4; i++){
            pair<int, int> v = {u.first+dx[i], u.second+dy[i]};
            if(v.first >= 0 && v.first < n && v.second >= 0 && v.second < m){
                if(!visited[v.first][v.second] && board[v.first][v.second] == s[k]){
                    if(dfs(v, s, k+1, n, m, board))
                        return true;
                }
            }
        }
        visited[u.first][u.second] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word){      
        int n = board.size();
        int m = board[0].size();  
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == word[0]){
                    if(dfs({i, j}, word, 1, n, m, board))
                        return true;
                }
        return false;
    }
};