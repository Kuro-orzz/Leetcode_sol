class Solution {
public:
    int visited[301][301];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    void dfs(int a, int b, int n, int m, vector<vector<char>>& grid){
        visited[a][b] = true;
        for(int i = 0; i < 4; i++){
            int x = a + dx[i];
            int y = b + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == '1')
                dfs(x, y, n, m, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        memset(visited, false, sizeof visited);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, n, m, grid);
                }
        return ans;
    }
};