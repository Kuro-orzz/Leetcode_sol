class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1);
        tower[0].push_back(poured);
        for (int i = 1; i <= query_row; i++) {
            tower[i].resize(i + 1);
            for (int j = 0; j <= i; j++) {
                if (j-1 >= 0 && tower[i-1][j-1] > 1) tower[i][j] += (tower[i-1][j-1] - 1) / 2;
                if (j != i && tower[i-1][j] > 1) tower[i][j] += (tower[i-1][j] - 1) / 2;
            }
        }
        return min(1.0, tower[query_row][query_glass]);
    }
};