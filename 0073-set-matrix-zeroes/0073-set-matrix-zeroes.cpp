class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> col;
        unordered_set<int> row;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        for(int x : row)
            for(int i = 0; i < m; i++)
                matrix[x][i] = 0;
        for(int x : col)
            for(int i = 0; i < n; i++)
                matrix[i][x] = 0;
    }
};