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
        return pref[c][d] - pref[c][b-1] - pref[a-1][d] + pref[a-1][b-1];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<ll>> pref = prefix_2d_init(n, m, mat);
        int k = min(n, m);
        for (int sz = k; sz > 0; sz--) {
            for (int i = sz; i <= n; i++) {
                for (int j = sz; j <= m; j++) {
                    if ( get(pref, i-sz+1, j-sz+1, i, j) <= threshold ) {
                        return sz;
                    }
                }
            }
        }
        return 0;
    }
};