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

    // weak test, O(n^4) still pass with small optimize
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<ll>> pref = prefix_2d_init(n, m, mat);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k1 = 0; k1 < i; k1++) {
                    for (int k2 = 0; k2 < j; k2++) {
                        ll sum_submatrix = get(pref, i-k1, j-k2, i, j);
                        if (sum_submatrix == (k1 + 1) * (k2 + 1)) ans++;
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};