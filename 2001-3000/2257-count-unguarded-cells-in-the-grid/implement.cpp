class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        swap(n, m);
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = -1;
        }
        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = -1;
        }
        for (int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            // left
            for (int j = y+1; j < m; j++) {
                if (grid[x][j] == -1) break;
                grid[x][j] = 1;
            } 
            // up
            for (int j = x-1; j >= 0; j--) {
                if (grid[j][y] == -1) break;
                grid[j][y] = 1;
            }
            // right
            for (int j = y-1; j >= 0; j--) {
                if (grid[x][j] == -1) break;
                grid[x][j] = 1;
            }
            // down
            for (int j = x+1; j < n; j++) {
                if (grid[j][y] == -1) break;
                grid[j][y] = 1;
            }
        }
        int unsafe = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) unsafe++;
            }
        }
        return unsafe;
    }
};