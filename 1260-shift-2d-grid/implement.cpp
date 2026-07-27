class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v.push_back(grid[i][j]);
            }
        }
        rotate(v.begin(), v.end() - k%(n*m), v.end());
        int p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = v[p++];
            }
        }
        return grid;
    }
};