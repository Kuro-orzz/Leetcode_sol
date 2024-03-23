class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        vector<int> ans;
        if(n == 1){
            for(int i = 0; i < m; i++)
                ans.push_back(matrix[0][i]);
            return ans;
        }
        if(m == 1){
            for(int i = 0; i < n; i++)
                ans.push_back(matrix[i][0]);
            return ans;
        }
        int i = 0;
        int j = 0;
        while(j+1 < m && v[i][j+1] == 0){
            while(j+1 < m && v[i][j+1] == 0){
                v[i][j] = 1;
                ans.push_back(matrix[i][j]);
                j++;
            }            
            while(i+1 < n && v[i+1][j] == 0){
                v[i][j] = 1;
                ans.push_back(matrix[i][j]);
                i++;
            }
            while(j-1 >= 0 && v[i][j-1] == 0){
                v[i][j] = 1;
                ans.push_back(matrix[i][j]);
                j--;
            }
            while(i-1 >= 0 && v[i-1][j] == 0){
                v[i][j] = 1;
                ans.push_back(matrix[i][j]);
                i--;
            }
        }
        ans.push_back(matrix[i][j]);
        return ans;
    }
};