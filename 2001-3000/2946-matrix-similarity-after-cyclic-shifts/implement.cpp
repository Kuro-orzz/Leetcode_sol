class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            if (i % 2 == 0) {
                for (int j = k; j < m; j++) tmp.push_back(mat[i][j]);
                for (int j = 0; j < k; j++) tmp.push_back(mat[i][j]);
            } else {
                for (int j = m-k; j < m; j++) tmp.push_back(mat[i][j]);
                for (int j = 0; j < m-k; j++) tmp.push_back(mat[i][j]);
            }
            if (mat[i] != tmp) return false;
        }
        return true;
    }
};