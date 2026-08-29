class Solution {
public:
    void reverse_shape(vector<vector<int>> &v){
        int n = v.size();
        int m = v[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                swap(v[i][j], v[i][m - 1 - j]);
            }
        }
    }

    void transpose(vector<vector<int>> &v){
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[j][i] = v[i][j];
            }
        }
        res.swap(v);
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse_shape(matrix);
    }
};