class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mn_row = m, mn_col = n;
        for (size_t i = 0; i < ops.size(); i++) {
            mn_row = min(mn_row, ops[i][0]);
            mn_col = min(mn_col, ops[i][1]);
        }
        return mn_row * mn_col;
    }
};