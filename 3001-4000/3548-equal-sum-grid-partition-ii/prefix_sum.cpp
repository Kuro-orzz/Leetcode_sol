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

        // horizontal
        vector<int> cnt(1e5+6, 0);
        for (int i = 1; i < n; i++) {
            ll t1 = get(pref, 1, 1, i, m);
            ll t2 = get(pref, i+1, 1, n, m);
            for (int j = 0; j < m; j++) cnt[grid[i-1][j]] = 1;
            if (t1 == t2) return true;
            else {
                if (t1 > t2) {
                    if (i != 1 && m > 1) {
                        if (t1 - t2 <= 1e5 && cnt[t1-t2]) return true;
                    } else if (i != 1 && m == 1) {
                        if (t1 - grid[0][0] == t2 || t1 - grid[i-1][0] == t2) return true;
                    } else  if (t1 - grid[0][0] == t2 || t1 - grid[0][m-1] == t2) return true;
                }
            }
        }
        cnt.assign(1e5+6, 0);
        for (int i = n-1; i >= 1; i--) {
            ll t1 = get(pref, 1, 1, i, m);
            ll t2 = get(pref, i+1, 1, n, m);
            for (int j = 0; j < m; j++) cnt[grid[i][j]] = 1;
            if (t1 == t2) return true;
            else {
                if (t1 < t2) {
                    if (i != n-1 && m > 1) {
                        if (t2 - t1 <= 1e5 && cnt[t2-t1]) return true;
                    } else if (i != n-1 && m == 1) {
                        if (t2 - grid[i][0] == t1 || t2 - grid[n-1][0] == t1) return true;
                    } else if (t2 - grid[n-1][0] == t1 || t2 - grid[n-1][m-1] == t2) return true;
                }
            }
        }

        // vertical
        cnt.assign(1e5+6, 0);
        for (int j = 1; j < m; j++) {
            ll t1 = get(pref, 1, 1, n, j);
            ll t2 = get(pref, 1, j+1, n, m);
            for (int i = 0; i < n; i++) cnt[grid[i][j-1]] = 1;
            if (t1 == t2) return true;
            else {
                if (t1 > t2) {
                    if (j != 1 && n > 1) {
                        if (t1 - t2 <= 1e5 && cnt[t1-t2]) return true;
                    } else if (j != 1 && n == 1) {
                        if (t1 - grid[0][0] == t2 || t1 - grid[0][j-1] == t2) return true;
                    } else if (t1 - grid[0][0] == t2 || t1 - grid[n-1][0] == t2) return true;
                }
            }
        }
        for (int j = m-1; j >= 1; j--) {
            ll t1 = get(pref, 1, 1, n, j);
            ll t2 = get(pref, 1, j+1, n, m);
            for (int i = 0; i < n; i++) cnt[grid[i][j]] = 1;
            if (t1 == t2) return true;
            else {
                if (t1 < t2) {
                    if (j != m-1 && n > 1) {
                        if (t2 - t1 <= 1e5 && cnt[t2-t1]) return true;
                    } else if (j != m-1 && n == 1) {
                        if (t2 - grid[0][j] == t1 || t2 - grid[0][m-1] == t1) return true;
                    } else if (t2 - grid[0][m-1] == t1 || t2 - grid[n-1][m-1] == t1) return true;
                }
            }
        }
        return false;
    }
};