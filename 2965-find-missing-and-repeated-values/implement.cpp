class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        unordered_set<int> s;
        long long sum = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(s.count(grid[i][j]))
                    ans.push_back(grid[i][j]);
                s.insert(grid[i][j]);
                sum += grid[i][j];
            }
        ans.push_back(n*n*(1+n*n)/2-sum+ans[0]);
        return ans;
    }
};