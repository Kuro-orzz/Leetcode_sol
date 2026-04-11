#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1));
        int mn_diff = INT_MAX;
        for (int i = 0; i < n-k+1; i++) {
            for (int j = 0; j < m-k+1; j++) {
                vector<int> v;
                for (int p1 = i; p1 < i+k; p1++) {
                    for (int p2 = j; p2 < j+k; p2++) {
                        v.push_back(grid[p1][p2]);
                    }
                }
                sort(v.begin(), v.end());
                unique(v);
                int diff = INT_MAX;
                for (int l = 1; l < v.size(); l++) {
                    diff = min(diff, v[l] - v[l-1]);
                }
                ans[i][j] = (diff == INT_MAX ? 0 : diff);
            }
        }
        return ans;
    }
};