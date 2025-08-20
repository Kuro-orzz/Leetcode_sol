class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> mxRow(n), mxCol(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mxRow[i] = max(mxRow[i], grid[i][j]);
                mxCol[j] = max(mxCol[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += min(mxRow[i], mxCol[j]) - grid[i][j];
            }
        }
        return ans;
    }
};