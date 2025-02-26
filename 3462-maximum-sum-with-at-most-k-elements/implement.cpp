#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<ll> sum(n, 0), pos(n, -1);
        vector<pii> v;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                v.push_back({grid[i][j], i});
        sort(v.begin(), v.end(), greater<pii>());
        ll ans = 0;
        int i = 0;
        while(i < v.size() && k){
            int val = v[i].fi;
            int row = v[i].se;
            if(sum[row] < limits[row]){
                sum[row]++;
                ans += val;
                k--;
            }
            i++;
        }
        return ans;
    }
};