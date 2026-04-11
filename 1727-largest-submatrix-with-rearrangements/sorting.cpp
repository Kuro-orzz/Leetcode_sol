class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] && i) matrix[i][j] += matrix[i-1][j];
            }
            vector<int> col = matrix[i];
            sort(col.begin(), col.end() , greater<int>());
            for (int j = 0; j < m; j++) {
                ans = max(ans, col[j] * (j + 1));
            }
        }
        return ans;
    }
};