class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> v(n*m+1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                v[mat[i][j]] = {i, j};
        vector<int> r(n, 0), c(m, 0);
        for(int i = 0; i < n*m; i++){
            r[v[arr[i]].first]++;
            c[v[arr[i]].second]++;
            if(r[v[arr[i]].first] == m || c[v[arr[i]].second] == n)
                return i;
        }
        return -1;
    }
};