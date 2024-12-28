class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        int n = matrix.size();
        for(int i = 1; i < n; i++){
            if(matrix[i][0] > target && matrix[i-1][0] <= target){
                row = i-1;
                break;
            }
        }
        if(row == -1)
            return binary_search(matrix[n-1].begin(), matrix[n-1].end(), target);
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};