class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n-1; i++)
            for(int j = 0; j < m-1; j++){
                int cnt = 0;
                if(grid[i][j] == 'B') cnt++;
                if(grid[i][j+1] == 'B') cnt++;
                if(grid[i+1][j] == 'B') cnt++;
                if(grid[i+1][j+1] == 'B') cnt++;
                if(cnt != 2) return true;
            }
        return false;
    }
};