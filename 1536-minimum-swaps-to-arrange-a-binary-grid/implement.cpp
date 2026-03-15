class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int cur = -1;
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) cur = j;
            }
            v[i] = cur;
        }
        int op = 0;
        for (int i = 0; i < n; i++) {
            int line = -1;
            for (int j = i; j < n; j++) {
                if (v[j] <= i) {
                    line = j;
                    break;
                }
            }
            if (line == -1) return -1;
            for (int j = line; j > i; j--) {
                swap(v[j], v[j-1]);
                op++;
            }
        }
        return op;
    }
};