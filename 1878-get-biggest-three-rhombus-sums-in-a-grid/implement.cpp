#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int t = min({j, m-j-1, (n-i-1)/2});
                v.push_back(grid[i][j]);
                for (int k = 1; k <= t; k++) {
                    int sum = grid[i][j] + grid[i+2*k][j] + grid[i+k][j-k] + grid[i+k][j+k];
                    for (int l = 1; l < k; l++) {
                        sum += grid[i+l][j-l] + grid[i+l][j+l];
                        sum += grid[i+2*k-l][j-l] + grid[i+2*k-l][j+l];
                    }
                    v.push_back(sum);
                }
            }
        }
        sort(all(v));
        unique(v);
        reverse(all(v));
        if (v.size() >= 3) v.resize(3);
        return v;
    }
};