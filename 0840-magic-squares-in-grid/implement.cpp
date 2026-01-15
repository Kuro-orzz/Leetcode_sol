class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                bool flag = true;
                vector<int> cnt(10, 0);
                for (int k1 = 0; k1 < 3; k1++) {
                    for (int k2 = 0; k2 < 3; k2++) {
                        if (!grid[i+k1][j+k2] || grid[i+k1][j+k2] > 9) flag = false;
                        else cnt[grid[i+k1][j+k2]]++;
                    }
                }
                for (int x : cnt) if (x > 1) flag = false;
                int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                if (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != sum) flag = false;
                if (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != sum) flag = false;
                if (grid[i][j] + grid[i+1][j] + grid[i+2][j] != sum) flag = false;
                if (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != sum) flag = false;
                if (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != sum) flag = false;
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != sum) flag = false;
                if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != sum) flag = false;
                if (flag) ans++;
            }
        }
        return ans;
    }
};