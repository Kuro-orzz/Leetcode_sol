class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                v.push_back(grid[i][j]);
        sort(v.begin(), v.end());
        int t = v[v.size()/2];
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                int tmp = abs(grid[i][j]-t);
                if(tmp % x != 0) return -1;
                ans += tmp / x;
            }
        return ans;
    }
};