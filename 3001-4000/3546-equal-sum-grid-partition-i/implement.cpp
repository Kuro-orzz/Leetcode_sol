#define ll long long

class Solution {
public:
    vector<vector<ll>> prefix_2d_init(int n, int m, const vector<vector<int>> &a) {
        vector<vector<ll>> pref(n+1, vector<ll>(m+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];
            }
        }
        return pref;
    }

    ll get(const vector<vector<ll>> &pref, int a, int b, int c, int d) {
        return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<ll>> pref = prefix_2d_init(n, m, grid);
        for (int i = 1; i < n; i++) {
            ll t1 = get(pref, 1, 1, i, m);
            ll t2 = get(pref, i+1, 1, n, m);
            if (t1 == t2) return true;
        }
        for (int i = 1; i < m; i++) {
            ll t1 = get(pref, 1, 1, n, i);
            ll t2 = get(pref, 1, i+1, n, m);
            if (t1 == t2) return true;
        }
        return false;
    }
};