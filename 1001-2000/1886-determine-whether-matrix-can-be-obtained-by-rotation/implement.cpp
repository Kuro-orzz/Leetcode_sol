class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int _ = 0; _ < 4; _++) {
            vector<vector<int>> rot_mat(n, vector<int>(n));
            for (int j = n-1; j >= 0; j--) {
                for (int i = 0; i < n; i++) {
                    rot_mat[n-j-1][i] = mat[i][j];
                }
            }
            if (rot_mat == target) return true;
            mat = rot_mat;
        }
        return false;
    }
};